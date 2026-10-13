# WinAPI_MapleStory 코드 조사

조사일: 2026-10-13

## 범위와 한계

- `Maplestory WinAPI Project`의 C++ 구현 101개, 헤더 108개 및 솔루션·프로젝트·Windows 리소스 설정을 대상으로 정적 조사했다.
- 엔진 수명 관리, 씬 전환, 입력, 충돌, 물리, 애니메이션, 이미지·사운드 로딩, 플레이어, 몬스터, 보스, UI를 확인했다.
- 실제 실행·빌드·성능 측정은 하지 않았다. 아래의 실행 결과는 코드 경로에서 판단한 영향이며 실제 재현 완료를 뜻하지 않는다.
- 프로젝트에 등록된 C++/헤더/RC 파일은 존재한다. 문자열로 지정한 Resources 경로 중 없는 것은 미등록 LoginBack.cpp의 LoginUI/Login.bmp였다.
- 게임 코드는 수정하지 않았다. 이 문서만 추가했다.

## 구조

`wWinMain → Application::Run → Update → Render → SceneManager::Destroy` 순서로 동작한다. Update 내부에서는 시간·입력·카메라·씬·충돌을 차례로 갱신한다.

SceneManager는 시작 시 13개 씬을 모두 생성하고 초기화한다. 각 Scene이 Layer를 보유하고 Layer가 GameObject를 삭제한다. GameObject는 Component를 삭제한다. 이미지와 사운드는 별도 전역 RResources 캐시에서 공유한다.

진행 경로는 로딩 → 로고 → 채널 선택 → 캐릭터 선택 → 헤네시스 → 소멸의 여로 → 아르카나 → 보스 입구 → 1단계 연출 → 1단계 보스 → 2단계 연출 → 최종 보스 → 엔딩이다. 일반 맵 전환은 N 키로 처리된다.

구조상 가장 취약한 부분은 객체를 소유하는 Layer와 해당 객체를 참조하는 씬 사이의 수명 관리다. 씬 전환도 현재 Update가 끝나기 전에 전역 활성 씬을 바꿔, 갱신 중인 객체와 전역 조회 대상이 달라진다.

## P1 — 빌드·크래시·진행 차단 우선 수정

### 1. RC 파일의 절대 경로로 새 작업 폴더에서 빌드가 막힌다

위치: `Maplestory WinAPI Project.rc:141,143`

커서 PNG가 `D:\API_MapleStory\WinAPI_MapleStory\Resources\...`로 지정돼 있다. 현재 clone 경로의 파일을 참조하지 않으므로 이전 위치가 없는 PC에서는 리소스 컴파일이 실패한다. `..\Resources\UI\Cursor\...` 같은 프로젝트 기준 상대 경로로 수정해야 한다.

### 2. 1단계 보스 삭제 후 씬이 삭제된 객체를 다시 읽는다

위치: `Boss_Stage1_Scene.cpp:92-106`, `Boss_Ion.cpp:266-269`, `Boss_Yaldabaoth.cpp:264-267`, `Scene.cpp:59`

사망 애니메이션 완료 시 보스가 Death로 표시되고 같은 프레임 끝에 Scene::Destroy에서 delete된다. 다음 Update는 남아 있는 `m_Boss_Ion` / `m_Boss_Yaldabaoth`로 HP와 사망 여부를 읽는다. 한 마리만 먼저 죽어도 발생하는 use-after-free이며, 둘 다 죽은 후 4초 대기 역시 안전하지 않다. 사망 상태를 씬에 전달하고 참조를 해제하거나, 전환 전까지 보스를 소유하는 명확한 정책이 필요하다.

### 3. 엔딩 씬에서 플레이어 조회가 nullptr를 반환한다

위치: `LastMapScene.h`, `Scene.cpp:70`, `Cosmos.cpp:45-46`, `Missobj.cpp:33-34`

LastMapScene은 플레이어를 생성하지만 GetPlayer를 재정의하지 않는다. 엔딩에서 D로 Cosmos를 사용하면 기본 Scene::GetPlayer의 nullptr를 역참조한다. LastMapScene에도 GetPlayer 재정의가 필요하다. 모든 조회 사용처의 null 처리도 필요하다.

### 4. 실제 사용되는 상태·시간·좌표 멤버가 초기화되지 않는다

위치: `emptyScene.cpp:12,32`, `happy.cpp:23,64`, `waterspirit.cpp:23,81`, `Missobj.cpp:15,36`

- emptyScene::mTime은 최초 로딩에서 바로 누적·비교된다.
- happy와 waterspirit의 m_State는 초기화 없이 switch에서 읽힌다. 이동 여부가 정의되지 않는다.
- Missobj::div는 첫 피격 표시부터 초기화 없이 감소해 화면 위치 계산에 쓰인다.
- RedSnail도 같은 상태 초기화 문제가 있지만 현재 진행 씬에서는 사용되지 않는다.

생성자나 멤버 선언에서 명시적으로 초기화해야 한다.

### 5. 이미지 캐시 키가 파일명만 사용돼 서로 다른 프레임을 공유한다

위치: `Animator.cpp:87-94`, `RResources.h:32-37`, `BackCover.cpp:18`, `Hp_Mp.cpp:18`

애니메이션 프레임은 전체 경로 대신 파일명으로 캐시한다. 실제 참조되는 폴더에서도 동일한 대소문자의 파일명 중복을 확인했다. 예를 들어 mushroom/IdleLeft와 IdleRight의 `mIdleLeft0.bmp`, SoulEclipse/StartEffect와 Continue의 `SSE30.bmp`가 겹친다. 나중에 로딩한 프레임은 먼저 읽은 이미지를 받는다.

또한 BackCover와 Hp_Mp는 서로 다른 파일을 동일한 `hp/mp` 키로 로딩한다. 헤네시스에서는 Hp_Mp가 먼저 로딩돼 BackCover가 HP_Cover 대신 상태 UI를 받는다. 정규화한 전체 경로를 이미지 키로 쓰고 UI 키도 구분해야 한다.

### 6. 사망 조건이 정확한 값과의 일치여서 동시 공격 시 사망을 놓친다

위치: `mushroom.cpp:73`, `happy.cpp:60`, `waterspirit.cpp:78`, `Boss_Ion.cpp:79`, `Boss_Yaldabaoth.cpp:78`, `Boss.cpp:102`

일반 몬스터는 `Hp == 0`, 보스는 누적 피격 횟수가 `== 6` 또는 `== 7`인 경우만 죽는다. 충돌 루프에서 공격 두 개가 같은 프레임에 들어오면 HP가 10에서 -10으로, 피격 횟수가 6에서 8로 넘어갈 수 있다. 일반 몬스터는 `<= 0`, 피격 카운트는 `>= 임계값`으로 검사하고 사망 이후 피해 처리를 차단해야 한다.

### 7. 씬 전환 후 이전 씬의 Update가 계속 실행된다

위치: `SceneManager.cpp:75-85`, `Boss_Enter_Scene.cpp:69-78`, `Boss_Stage1_Scene.cpp:95-111`, `Boss_Stage2_Scene.cpp:83-94`

LoadScene이 즉시 활성 씬을 바꾸지만 호출한 씬은 이후 Scene::Update와 Camera::SetTarget을 계속 수행한다. 예를 들어 보스 입구에서 Cosmos가 살아 있을 때 N을 누르면, 이전 씬의 Cosmos::Update가 새 연출 씬의 GetPlayer를 조회해 nullptr를 역참조할 수 있다. 2단계 연출 씬은 미초기화 mMainChar를 GetPlayer에서 반환한다.

전환 요청을 프레임 끝에 적용하는 방식이 가장 일관적이다. 최소한 전환 후 즉시 return하고 카메라·플레이어 조회가 이전 씬으로 되돌아가지 않게 해야 한다.

### 8. 사운드 로딩 실패가 성공으로 반환된다

위치: `Sound.cpp:5-22,65-83`, `Application.cpp:49`

Sound::Load는 장치 누락, 확장자 오류, WAV 로딩 실패를 assert로만 처리한 뒤 S_OK를 반환한다. Release에서는 assert가 제거되므로 실패한 사운드가 정상 리소스로 캐시되고 Play가 null 버퍼를 사용할 수 있다. Application도 SoundManager::Initialize의 실패를 무시한다. HRESULT를 전파하고 실패 시 파일·버퍼를 정리해야 한다. WAV chunk 조회, 읽기, Lock 반환값도 확인해야 한다.

## P2 — 기능 오류·리소스 누수

### 9. 충돌 마스크가 레이어 수보다 작다

위치: `CollisionManager.h:30`, `CollisionManager.cpp:5,146`, `Enums.h:24`

레이어는 22개인데 각 행은 16비트 WORD다. 인덱스 16 이상인 Effect·UI·ChannelList·Mous 등의 비트는 SetLayer에서 잘린다. 현재 Player/Ground/WallCollider는 인덱스 15 이하라 이 문제만으로 모든 지형 충돌이 끊기는 것은 아니다. UINT32나 레이어 수에 맞춘 bitset을 사용해야 한다.

### 10. 충돌 ID에 포인터 하위 32비트를 사용하고 삭제된 쌍을 보관한다

위치: `Entity.cpp:5`, `CollisionManager.cpp:56-67`, `CollisionManager.cpp:151`, `Scene.cpp:59`

64비트 주소를 UINT로 자른 값이 ID이며, 충돌 쌍은 씬 전환 전까지 삭제되지 않는다. 메모리 주소가 재사용되면 새 스킬이 과거 스킬과 같은 ID를 받아 Enter 대신 Stay가 발생할 수 있다. 보스는 Enter에서만 피해를 받으므로 공격 누락으로 이어질 수 있다. 단조 증가 ID와 객체 제거 시 쌍 정리가 필요하다. 매번 모든 후보 쌍을 map에 남겨 장시간 생성·삭제 시 캐시도 커진다.

### 11. 이미지·백버퍼·DirectSound 자원을 해제하지 않는다

위치: `Image.cpp:49`, `Application.cpp:16`, `Sound.h`, `SoundManager.cpp`, `main.cpp:79-80`

Image와 Application의 소멸자가 비어 있다. 이미지 HBITMAP/HDC, 백버퍼와 창 DC가 정리되지 않는다. Sound에는 DirectSound 버퍼를 Release하는 소멸자가 없고 SoundManager의 장치도 해제되지 않는다. C++ 객체 delete만으로 Windows 핸들과 COM 자원이 해제되지는 않는다.

초기화 시 원래 선택된 비트맵을 보관하고, 정리 시 선택을 복원한 후 DeleteObject/DeleteDC/ReleaseDC를 호출해야 한다. 사운드 버퍼와 장치는 순서에 맞춰 Release해야 한다.

### 12. 중복 Initialize가 기존 컴포넌트를 덮어써 누수시킨다

위치: `GameObject.h:27-35`, `ChannelSelectScene.cpp:36,47`, `SolunaDivideStart.cpp:36-37`, `Object.h:12-16`

BG를 직접 초기화한 뒤 Scene::Initialize에서 다시 초기화한다. SolunaDivideEffect는 Instantiate가 이미 초기화했는데 다시 Initialize한다. AddComponent는 기존 Animator를 delete하지 않고 덮어쓴다. 초기화 호출을 한 번으로 통일하고 같은 타입 컴포넌트 중복 추가 정책을 정해야 한다.

### 13. 지면 충돌이 위치 보정과 착지 방향을 처리하지 않는다

위치: `Ground.cpp:35-66,72-82`, `Rigidbody.cpp:42-55`

겹치기만 하면 Ground(true)를 설정한다. 위로 뛰는 중 플랫폼 밑면이나 옆면을 만난 경우도 착지로 처리하고, 파고든 위치의 보정 코드는 주석 처리돼 있다. 여러 지면과 겹친 상태에서 하나의 Exit가 발생하면 다른 지면 접촉을 무시하고 Ground(false)로 바꾼다. 하강 시 윗면 착지, 위치 보정, 지면 접촉 수 관리가 필요하다.

### 14. 공격 위치와 충돌 설정이 방향·상태마다 다르다

위치: `MainChar.cpp:276-286,388-424`

이동 중 왼쪽 공격도 `bsPos.x + 280`을 사용해 공격 판정이 오른쪽에 생성된다. 정지 중 왼쪽 공격은 -280이다. 최종 보스는 Boss 레이어인데 Skill/Boss 충돌 설정은 정지 중 오른쪽 F 공격에만 있다. 새 씬 진입 직후 왼쪽 F 또는 Cosmos부터 쓰면 보스에 맞지 않다가 오른쪽 F를 사용한 뒤 동작할 수 있다. 공격 생성을 공통 함수로 묶고 씬 진입에서 충돌 관계를 설정해야 한다.

### 15. 플레이어 HP 감소·사망 처리가 구현되지 않았다

위치: `MainChar.cpp:45,158-215`, `MainChar.h:38-41`, `HpBar.cpp`, `HenesysScene.h:32-35`

HP는 1000으로 시작해 피해 충돌에서 감소하지 않는다. hit는 Miss 표시만 생성하며 Death 상태 처리도 없다. HpBar도 실제 HP를 읽지 않는다. HenesysScene::SetCheck는 멤버 대신 같은 이름의 지역 변수를 바꿔 UI 갱신 경로도 열지 못한다. 피해·무적시간·사망·HP UI 연결이 필요한 미구현 기능이다.

### 16. 물리 속도 제한 계산이 최종 속도에 반영되지 않는다

위치: `Rigidbody.cpp:10,36,62-73`

gravity와 sideVelocity를 제한한 뒤 mVelocity에 다시 합치지 않는다. 제한값을 넘는 속도가 그대로 위치에 적용된다. 또한 기본 mMass가 0인데 가속도는 질량으로 나누므로 기본 사용 시 NaN/무한대가 생길 수 있다. 현재 MainChar는 질량을 1로 설정하므로 해당 경로는 회피하고 있다.

### 17. 콜라이더 좌표가 이동보다 먼저 갱신된다

위치: `GameObject.cpp:35-43`, `Enums.h:52`, `Rigidbody.cpp:96-100`, `MainChar.cpp:112,313-328`, `Cosmos.cpp:44-47`

컴포넌트 순서는 Collider → Animator → Rigidbody다. Collider가 좌표를 읽은 뒤 물리 및 객체별 이동이 Transform을 바꾸므로 충돌은 이전 위치로 검사된다. 고속 이동 시 충돌 지연과 관통 위험이 있다. 이동 후 콜라이더를 동기화하는 단계를 분리해야 한다.

### 18. 단발 애니메이션에는 완료 이벤트가 호출되지 않는다

위치: `Animator.cpp:34-41`

완료 이벤트가 `mbLoop && IsComplete()` 안에 묶여 있어 Play(name, false)는 완료 콜백을 호출하지 않는다. 현재 많은 객체가 일회성 종료에도 true를 전달해 우회하고 있다. 완료 이벤트는 반복 여부와 독립적으로 한 번 호출하고 반복 재생만 따로 결정해야 한다. 콜백에서 Play가 호출되면 직후 Reset은 원래 완료된 애니메이션이 아니라 새 활성 애니메이션에 적용되는 점도 정리해야 한다.

### 19. 애니메이션 시간 누적과 파일 순서에 문제가 있다

위치: `Animation.cpp:40-51`, `Animator.cpp:85-118`, `Application.cpp:47-50`

Animation은 긴 프레임에도 한 장만 넘기고 남은 시간을 0으로 버린다. 저프레임에서 재생 시간과 보스 패턴 타이밍이 늘어난다. 프레임 파일을 명시적으로 정렬하지 않아 디렉터리 열거 순서에도 의존한다. 초기 씬 리소스를 모두 로딩하기 전에 Time을 초기화하므로 첫 DeltaTime에는 로딩 시간도 포함된다. 로딩 완료 후 시간 기준을 재설정하고 남은 시간을 보존해 필요한 프레임 수만큼 진행해야 한다.

### 20. 최종 보스의 일부 공격은 시각 효과만 생성한다

위치: `LeftFullSkill.cpp:20-39`, `CenterFullSkill.cpp:20-39`, `RightFullSkill.cpp:21-40`, `Boss_Stage2_Scene.cpp:108-114`, `MainChar.cpp:158-215`

좌·중앙·우 전면 스킬에는 Collider가 없다. BossSkill/Player 충돌 관계도 설정하지 않는다. CircleObj/Player 관계는 별도로 켜지지 않아 체인 공격이 Player/BossObj 설정을 켠 뒤에야 활성화될 수 있다. 여기에 플레이어 피해 기능 미구현이 겹쳐 보스 공격 효과와 피해 판정이 연결되지 않는다.

### 21. 스킬 지속음이 씬 전환 후에도 재생된다

위치: `SoulEclipseStart.cpp:44-45,80-83`, 각 게임 씬의 OnExit

SoulEclipse 루프 음원은 A 키로 End할 때만 정지한다. 스킬을 켠 상태에서 N으로 맵을 이동하면 이전 씬은 더 이상 업데이트되지 않고 OnExit는 해당 음원을 정지하지 않아 루프 사운드가 남는다. 씬을 떠날 때 실행 중 스킬과 지속 사운드를 정리해야 한다.

## P3 — 잠재 오류·정리 대상

### 22. 호출되면 잘못 동작하는 공개 API가 있다

위치: `MainChar.h:100-103,116-118`, `ChannelSelectScene.h:26-29`, `HenesysScene.h:32-35`, `GameObject.h:52-61`

- SetCharPosY가 posy 대신 posx를 바꾼다.
- GetCollider는 초기화하지 않은 collider2를 역참조해 복사 반환한다.
- SetSound/SetCheck는 멤버 대신 지역 변수를 만든다.
- GetComponents<T>는 vector<T*>에 Component*를 그대로 넣어 일반적인 파생 컴포넌트 타입으로 인스턴스화하면 컴파일되지 않는다.

현재 주요 진행 경로의 호출과 구분해 잠재 결함으로 분류했다. API 의도에 맞게 반환 타입과 대입 대상을 고쳐야 한다.

### 23. 보스 플래그 대입 오타와 씬 설정 불일치가 있다

위치: `Boss.cpp:171`, `Arcana.cpp:59-64`, `LastMapScene.cpp:58`, `Boss_Stage2_Scene.cpp:116-117`

Skill4Loop를 종료하는 문장이 `Skill4Loop == false`여서 값이 바뀌지 않는다. 아르카나 Ground 객체는 Monster 레이어에 들어 있어 Player/Monster 충돌에 의존한다. 엔딩의 지면 크기는 Collider::SetSize 대신 Transform::SetScale로 설정했지만 Collider는 scale을 반영하지 않는다. 2단계 맵 크기는 연속 두 번 설정돼 첫 값이 즉시 덮인다.

### 24. 빌드 구성이 일관되지 않고 설명 문서가 부족하다

위치: `Maplestory WinAPI Project.vcxproj:108`, `CommonInclude.h`, `Animator.cpp:85`, `LoginScene.cpp`, `LoginBack.cpp`

std::filesystem을 사용하지만 언어 표준은 Debug/x64에만 C++20으로 설정돼 있다. 나머지 구성도 C++17 이상을 명시해야 한다. LoginScene/LoginBack은 파일은 존재하지만 프로젝트·씬 진행에 등록되지 않았고 Login.bmp도 없다. 미사용 코드와 실제 진행 코드를 구분하고 VS 도구 집합 v143, 실행 작업 디렉터리, 조작키를 README에 정리할 필요가 있다.

### 25. 리소스·씬·애니메이션 API가 실패와 재사용에 취약하다

위치: `RResources.h:40-44,57-64`, `Animator.cpp:149-153,182-214`, `Stage1Enter_AniScene.cpp:30-35`, `Stage2Enter_AniScene.cpp:31-36`

리소스 로딩 실패 시 new한 객체를 삭제하지 않는다. Release는 컨테이너를 비우지 않아 재호출하면 삭제된 포인터를 다시 사용할 수 있다. Animator::Play와 이벤트 조회는 없는 이름을 전달하면 nullptr를 바로 역참조한다. 연출 씬의 mTime은 OnEnter에서 재설정하지 않아 재진입 시 바로 다음 씬으로 넘어간다. 현재 단방향 진행과 정해진 애니메이션 이름에서는 일부 문제가 드러나지 않지만 재시작·맵 복귀·기능 추가 전에 정리해야 한다.

## 유지보수 개선

- MainChar의 입력·상태·공격 생성 코드가 방향별로 반복된다. 이동 상태와 공격 상태를 분리하고 방향을 인자로 받는 공격 함수를 만들면 14번 같은 비대칭을 줄일 수 있다.
- 맵별 지면·벽·몬스터 배치가 긴 new/AddGameObeject/SetPos 나열이다. 배치 데이터를 구조체 배열이나 별도 파일로 분리하면 좌표 수정과 맵 추가가 쉬워진다.
- 배경과 UI 클래스 대부분이 동일한 로딩·BitBlt/TransparentBlt 코드를 반복한다. 공통 SpriteRenderer를 활용할 여지가 있으나 현재 enum 항목만 있고 실제 컴포넌트 구현은 없다.
- Layer의 Update/Render와 CollisionManager는 Pause/Death 상태를 검사하지 않는다. 삭제 표시된 객체가 같은 프레임의 나머지 충돌을 계속 처리할 수 있으므로 상태 정책을 통일해야 한다.
- main 루프는 프레임 제한이나 비활성 창 대기가 없다. CPU 사용량은 실행 측정하지 않았으므로 수치로 단정하지 않지만 불필요한 반복을 줄일 수 있다.
- Camera는 플레이어 이동 전에 갱신돼 한 프레임 늦게 따라간다. 화면 좌표용 객체도 음수 좌표로 카메라 보정을 상쇄하는 방식이 섞여 있다. 월드 좌표와 UI 좌표를 명시적으로 구분하는 편이 낫다.
- 여러 파일의 한글 주석 인코딩이 UTF-8과 혼재돼 있다. 코드 변경 시 원본 인코딩 보존 또는 일괄 UTF-8 전환 정책이 필요하다.

## 권장 수정 순서와 필요한 확인

1. RC 상대 경로와 모든 빌드 구성의 C++ 표준을 정리한다. 이후 목표 구성 1개를 빌드해 실제 컴파일 장애만 확인한다.
2. 보스 포인터 수명, 씬 전환 적용 시점, GetPlayer 계약, 사용 멤버 초기화를 고친다. 보스 한 마리 먼저 처치 / 스킬 도중 맵 이동 / 엔딩 D 사용만 확인한다.
3. 리소스 키와 실패 반환, GDI·DirectSound 자원 해제를 고친다. 서로 중복되는 SoulEclipse 프레임과 HP UI, 누락 리소스 실패 처리만 확인한다.
4. 피해·사망·방향별 공격·충돌·착지를 정리한다. 동시에 두 공격 적중, 왼쪽 이동 공격, 플랫폼 밑면·끝부분, 최종 보스 최초 공격을 확인한다.
5. 애니메이션 시간 및 코드 중복을 정리한다. 구조 정리는 위의 실행 차단 결함 해결 후 진행한다.

이번 조사에는 불필요한 빌드나 테스트를 추가하지 않았다. 위 확인 항목은 실제 수정 후 해당 위험을 확인하기 위한 최소 범위다.
