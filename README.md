# WinAPI MapleStory

**작업 기간: 2023년 03월 ~ 2023년 04월**

C++과 Windows API로 메이플스토리의 화면 구성, 캐릭터 조작, 스킬 연출, 몬스터 및 보스 전투를 구현한 2D 게임 프로젝트입니다.

Win32 윈도우와 메시지 루프를 바탕으로 게임 루프를 구성하고, GDI로 화면을 그리며 DirectSound로 배경음과 효과음을 재생합니다. 씬, 레이어, 게임 오브젝트, 컴포넌트를 직접 구성해 게임 진행과 객체 관리를 구현했습니다.

이 문서는 C++ 구현 파일 101개와 헤더 108개, 솔루션·프로젝트·리소스 설정을 조사한 내용을 기준으로 작성했습니다. 구현된 코드와 확인된 한계를 함께 설명하며, 실제 빌드 및 실행 검증은 아직 완료하지 않았습니다.

## 기술 구성

| 구분 | 사용 기술 |
| --- | --- |
| 언어 | C++20 |
| 개발 환경 | Visual Studio 2022, MSVC v143 |
| 플랫폼 | Windows, Win32 API |
| 화면 출력 | GDI, BitBlt, TransparentBlt, AlphaBlend |
| 사운드 | DirectSound, Windows Multimedia API |
| 입력 | GetAsyncKeyState 기반 키보드·마우스 입력 |
| 시간 관리 | QueryPerformanceCounter 기반 DeltaTime |
| 리소스 탐색 | std::filesystem |

## 주요 구현

### 화면 출력과 카메라

- 메모리 DC와 호환 비트맵을 사용한 더블 버퍼링
- 배경, 오브젝트, 캐릭터, 이펙트, UI의 레이어별 출력
- 캐릭터를 따라가는 카메라와 맵 크기에 따른 이동 범위 제한
- 스프라이트 시트 애니메이션과 색상 키 기반 투명 처리
- 화면 페이드 연출을 위한 AlphaBlend 처리

### 캐릭터와 스킬

- 좌우 이동, 점프, 앉기, 방향별 공격 애니메이션
- 기본 공격, Cosmos, Soul Eclipse, Soluna Divide의 시각·사운드 연출
- 공격 오브젝트 생성과 충돌을 이용한 몬스터 피격 처리
- 피격 시 Miss 표시 오브젝트 생성

### 몬스터와 보스

- 버섯, happy, waterspirit의 이동·피격·사망 처리
- 벽 콜라이더 접촉에 따른 몬스터 이동 방향 전환
- 1단계 보스 Ion·Yaldabaoth의 등장, 이동, 공격 및 사망 애니메이션
- 최종 보스의 좌·중앙·우 공격, 체인 공격, 낙하 오브젝트 패턴
- 보스별 피격 횟수에 연동된 HP UI

현재 플레이어 HP 감소·사망과 일부 보스 공격의 피해 판정은 연결되지 않은 상태입니다. 상세 내용은 마지막의 수정 예정 항목에 정리했습니다.

## 게임 진행

SceneManager는 시작 시 13개 씬을 생성하고 초기화합니다.

| 순서 | 씬 | 역할 |
| --- | --- | --- |
| 1 | emptyScene | 초기 로딩 화면 |
| 2 | WizetScene | 로고 연출 |
| 3 | ChannelSelectScene | 월드·채널 선택 화면 |
| 4 | CharacterSelectScene | 캐릭터 선택 화면 |
| 5 | HenesysScene | 헤네시스 맵과 버섯 몬스터 |
| 6 | SomyeolScene | 소멸의 여로 맵과 happy 몬스터 |
| 7 | Arcana | 아르카나 맵과 waterspirit 몬스터 |
| 8 | Boss_Enter_Scene | 보스 입구 |
| 9 | Stage1Enter_AniScene | 1단계 보스 진입 연출 |
| 10 | Boss_Stage1_Scene | Ion·Yaldabaoth 전투 |
| 11 | Stage2Enter_AniScene | 2단계 보스 진입 연출 |
| 12 | Boss_Stage2_Scene | 최종 보스 전투 |
| 13 | LastMapScene | 엔딩 맵 |

일반 맵은 N 키로 다음 씬으로 이동합니다. 진입 연출은 시간에 따라 전환되고, 보스 씬에는 사망 상태를 확인해 다음 씬으로 넘어가는 코드가 있습니다. 월드·채널 및 캐릭터 선택은 현재 마우스 클릭을 기준으로 진행되며, 클릭 위치에 따른 버튼 선택 처리는 연결되지 않았습니다.

## 조작법

| 입력 | 동작 |
| --- | --- |
| ← / → | 좌우 이동 |
| Space | 점프 |
| ↓ | 앉기 |
| F | 기본 공격, 앉은 상태에서 공격 애니메이션 |
| D | Cosmos |
| S | Soul Eclipse |
| A | Soluna Divide, 활성 Soul Eclipse 종료 |
| N | 일반 맵에서 다음 씬 이동, 1단계 보스 씬에서 다음 연출로 이동 |
| 마우스 왼쪽 클릭 | 월드·채널 및 캐릭터 선택 진행 |

입력은 MainChar의 현재 상태에 따라 처리됩니다. Cosmos·Soul Eclipse·Soluna Divide는 대기 상태에서 사용하는 구조이며, 모든 동작 중에 동일하게 사용할 수 있는 것은 아닙니다.

## 코드 구조

```text
WinAPI_MapleStory/
├── Client.sln                     # Visual Studio 솔루션
├── Maplestory WinAPI Project/      # 엔진 및 게임 코드, 프로젝트 설정
│   ├── main.cpp                   # 윈도우 생성과 메시지 루프
│   ├── Application.*              # 초기화, 게임 루프, 더블 버퍼링
│   ├── SceneManager.* / Scene.*    # 씬 관리와 전환
│   ├── Layer.* / GameObject.*      # 객체 보관과 수명 관리
│   ├── Component.* / Transform.*   # 컴포넌트와 위치·배율
│   ├── CollisionManager.*          # 레이어별 충돌 검사
│   ├── Collider.* / Rigidbody.*    # 충돌 영역과 물리 이동
│   ├── Animator.* / Animation.*    # 애니메이션과 이벤트
│   ├── RResources.* / Image.*      # 리소스 캐시와 이미지 로딩
│   ├── SoundManager.* / Sound.*    # 사운드 장치와 WAV 재생
│   ├── Input.* / Time.* / Camera.* # 입력, 시간, 카메라
│   ├── MainChar.*                  # 플레이어 상태와 스킬 입력
│   └── 맵·몬스터·보스·스킬·UI 클래스
├── Resources/                     # 이미지, 애니메이션 프레임, 사운드
└── CODE_AUDIT.md                   # 코드 조사 상세 보고서
```

### 게임 루프

```text
wWinMain
└── 메시지가 없으면 Application::Run
    ├── Update
    │   ├── Time / Input / Camera 갱신
    │   ├── 활성 Scene의 Layer와 GameObject 갱신
    │   └── CollisionManager 충돌 검사
    ├── Render
    │   ├── 백버퍼에 씬과 카메라 연출 출력
    │   └── BitBlt로 창에 전달
    └── SceneManager::Destroy
        └── Death 상태의 오브젝트 삭제
```

### 객체 관리

Scene은 Layer를 보유하고, Layer는 GameObject 포인터를 보관하며 소멸 시 객체를 삭제합니다. GameObject는 Transform, Animator, Collider, Rigidbody 등의 Component를 보유합니다.

`object::Instantiate<T>`는 활성 씬에 객체를 등록하고 초기화합니다. `object::Destory`는 객체를 Death 상태로 표시하며, 실제 삭제는 프레임 끝의 Scene::Destroy에서 수행합니다.

이미지와 사운드는 RResources의 전역 캐시에서 공유합니다. Animator는 폴더의 이미지 프레임을 읽어 스프라이트 시트로 구성하고, 시작·완료·종료 이벤트를 통해 객체 상태와 애니메이션을 연결합니다.

## 빌드 및 실행

### 준비 환경

- Windows
- Visual Studio 2022의 **C++를 사용한 데스크톱 개발** 워크로드
- MSVC v143 도구 집합
- Windows 10 또는 이후 Windows SDK

### 실행 순서

1. 저장소를 clone합니다.

   ```powershell
   git clone https://github.com/easycd/WinAPI_MapleStory.git
   ```

2. Visual Studio에서 `Client.sln`을 엽니다.
3. `Maplestory WinAPI Project`를 시작 프로젝트로 설정합니다.
4. 구성은 `Debug`, 플랫폼은 `x64`로 선택합니다.
5. 프로젝트 속성의 **디버깅 → 작업 디렉터리**를 `$(ProjectDir)`로 설정합니다.
6. 솔루션을 빌드한 뒤 실행합니다.

게임의 리소스 경로는 `..\Resources\...`로 지정돼 있으므로 실행 작업 디렉터리는 `Maplestory WinAPI Project` 폴더여야 합니다. `Resources` 폴더도 저장소의 기존 위치에 유지해야 합니다.

커서 PNG의 이전 PC 절대 경로는 프로젝트 기준 상대 경로로 변경했고, C++20 설정은 모든 빌드 구성에 적용했습니다. 실제 빌드 성공 여부는 아직 확인하지 못했습니다.

## 코드 조사 자료

파일 위치, 영향, 수정 방향은 [코드 조사 보고서](CODE_AUDIT.md)에 기록했습니다. 보고서는 조사 당시 상태를 기준으로 하며, 이후 반영된 커서 경로와 C++ 표준 설정 변경은 위 빌드 안내에 반영했습니다.

## 문제점 및 수정 예정

아래 항목은 코드 조사에서 확인한 미해결 문제 또는 잠재 결함입니다. **모두 수정 예정**이며, 수정 후 관련 동작과 빌드를 확인할 계획입니다.

| 우선순위 | 문제점 | 수정 예정 내용 |
| --- | --- | --- |
| 높음 | 1단계 보스 삭제 후 씬이 삭제된 포인터를 다시 참조 | 사망 상태 전달과 객체 참조 수명 관리 개선 |
| 높음 | 엔딩 씬의 GetPlayer 미구현으로 스킬 사용 시 null 참조 가능 | 플레이어 조회 구현과 null 처리 추가 |
| 높음 | 로딩 시간·몬스터 상태·Miss 좌표 등의 초기화 누락 | 사용 멤버의 초기값 명시 |
| 높음 | 프레임 파일명 및 HP UI 캐시 키 중복 | 전체 경로 기반 키와 고유 UI 키 적용 |
| 높음 | 사망 조건이 정확한 값과의 일치여서 동시 공격 시 사망 누락 | 임계값 비교와 사망 이후 피해 차단 |
| 높음 | 씬 전환 이후 이전 씬의 Update가 계속 실행 | 전환 적용 시점과 카메라·플레이어 참조 정리 |
| 높음 | 사운드 로딩 실패를 성공으로 반환 | 실패 반환, 초기화 오류 처리, WAV 로딩 검사 개선 |
| 중간 | 22개 레이어에 비해 충돌 마스크가 16비트로 부족 | 레이어 수에 맞는 마스크 적용 |
| 중간 | 포인터 기반 충돌 ID 재사용과 삭제된 충돌 쌍 잔류 | 고유 ID 발급 및 삭제 시 충돌 기록 정리 |
| 중간 | GDI 핸들·백버퍼·DirectSound 자원 해제 누락 | 자원 소유와 해제 절차 구현 |
| 중간 | 중복 Initialize와 컴포넌트 덮어쓰기로 누수 발생 | 초기화 호출 통일과 중복 추가 정책 적용 |
| 중간 | 지면 충돌의 착지 방향·위치 보정·다중 접촉 처리 부족 | 착지 판정과 접촉 상태 관리 개선 |
| 중간 | 이동 중 왼쪽 공격 위치 및 보스 충돌 설정 불일치 | 방향별 공격 생성 공통화와 충돌 설정 통일 |
| 중간 | 플레이어 HP 감소·사망·HP UI 연결 미구현 | 피해, 무적시간, 사망 및 HP 표시 연결 |
| 중간 | 속도 제한 결과 미반영과 기본 질량 0 문제 | 물리 속도 계산과 질량 조건 수정 |
| 중간 | 이동 이전 콜라이더 갱신으로 충돌 좌표 지연 | 이동 후 충돌 영역 동기화 |
| 중간 | 단발 애니메이션 완료 이벤트 미호출 | 완료 이벤트와 반복 재생 로직 분리 |
| 중간 | 애니메이션 누적 시간 손실·프레임 순서 의존·첫 DeltaTime에 로딩 시간 포함 | 시간 누적, 파일 정렬, 초기 시간 기준 개선 |
| 중간 | 일부 보스 공격이 시각 효과에 머물고 피해 판정 미연결 | 공격 콜라이더와 레이어 충돌·피해 처리 연결 |
| 중간 | 맵 이동 후 Soul Eclipse 지속음이 남음 | 씬 종료 시 지속 스킬과 사운드 정리 |
| 낮음 | 좌표 setter, 상태 setter, GetCollider, GetComponents의 잠재 오류 | 공개 API의 대입 대상·타입·반환 방식 수정 |
| 낮음 | 보스 플래그 대입 오타, 지면 레이어·크기 설정 불일치 | 설정값과 종료 조건 정리 |
| 낮음 | 미등록 Login 코드와 누락 리소스, 개발 환경 설명 부족 | 미사용 코드 정리와 실행 안내 보완 |
| 낮음 | 리소스 해제·애니메이션 조회·씬 재진입의 실패 처리 부족 | 재사용 및 실패 경로의 상태 관리 개선 |

커서 리소스의 절대 경로와 빌드 구성별 C++ 표준 누락은 수정 반영했습니다. **나머지 문제점은 수정 예정입니다.**
