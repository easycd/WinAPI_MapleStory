#include "SomyeolScene.h"
#include "SomyeolBack.h"
#include "SomyeolObject.h"
#include "MainChar.h"
#include "happy.h"
#include "Input.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "Ground.h"
#include "Transform.h"
#include "Portal.h"
#include "WallColliderLeft.h"
#include "WallColliderRight.h"

SomyeolScene::SomyeolScene()
{
}
SomyeolScene::~SomyeolScene()
{
}
void SomyeolScene::Initialize()
{
	m_somyeolBack = new SomyeolBack();
	AddGameObeject(m_somyeolBack, eLayerType::BG);

	m_somyeolObject = new SomyeolObject();
	AddGameObeject(m_somyeolObject, eLayerType::BG);

	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);
	
	//-------------포탈 오브젝트---------------
	Portal* portal0 = new Portal();
	AddGameObeject(portal0, eLayerType::Portal);
	Portal* portal1 = new Portal();
	AddGameObeject(portal1, eLayerType::Portal);

	//-----------즐거움의 에르다스 오브젝트-----------
	happy* m_happy0 = new happy(); AddGameObeject(m_happy0, eLayerType::Monster);
	happy* m_happy1 = new happy(); AddGameObeject(m_happy1, eLayerType::Monster);
	happy* m_happy2 = new happy(); AddGameObeject(m_happy2, eLayerType::Monster);
	happy* m_happy3 = new happy(); AddGameObeject(m_happy3, eLayerType::Monster);
	happy* m_happy4 = new happy(); AddGameObeject(m_happy4, eLayerType::Monster);
	happy* m_happy5 = new happy(); AddGameObeject(m_happy5, eLayerType::Monster);
	happy* m_happy6 = new happy(); AddGameObeject(m_happy6, eLayerType::Monster);
	happy* m_happy7 = new happy(); AddGameObeject(m_happy7, eLayerType::Monster);
	happy* m_happy8 = new happy(); AddGameObeject(m_happy8, eLayerType::Monster);
	happy* m_happy9 = new happy(); AddGameObeject(m_happy9, eLayerType::Monster);
	happy* m_happy10 = new happy(); AddGameObeject(m_happy10, eLayerType::Monster);
	happy* m_happy11 = new happy(); AddGameObeject(m_happy11, eLayerType::Monster);
	happy* m_happy12 = new happy(); AddGameObeject(m_happy12, eLayerType::Monster);
	happy* m_happy13 = new happy(); AddGameObeject(m_happy13, eLayerType::Monster);
	happy* m_happy14 = new happy(); AddGameObeject(m_happy14, eLayerType::Monster);
	happy* m_happy15 = new happy(); AddGameObeject(m_happy15, eLayerType::Monster);
	happy* m_happy16 = new happy(); AddGameObeject(m_happy16, eLayerType::Monster);
	happy* m_happy17 = new happy(); AddGameObeject(m_happy17, eLayerType::Monster);
	happy* m_happy18 = new happy(); AddGameObeject(m_happy18, eLayerType::Monster);
	happy* m_happy19 = new happy(); AddGameObeject(m_happy19, eLayerType::Monster);
	happy* m_happy20 = new happy(); AddGameObeject(m_happy20, eLayerType::Monster);
	happy* m_happy21 = new happy(); AddGameObeject(m_happy21, eLayerType::Monster);



	//-----------------------------------------방향 충돌체 오브젝트------------------------------------------------------
	
	WallColliderRight* wallcolRight1 = new WallColliderRight(); AddGameObeject(wallcolRight1, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft1 = new WallColliderLeft(); AddGameObeject(wallcolLeft1, eLayerType::WallCollider);
	WallColliderRight* wallcolRight3 = new WallColliderRight(); AddGameObeject(wallcolRight3, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft3 = new WallColliderLeft(); AddGameObeject(wallcolLeft3, eLayerType::WallCollider);
	WallColliderRight* wallcolRight4 = new WallColliderRight(); AddGameObeject(wallcolRight4, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft4 = new WallColliderLeft(); AddGameObeject(wallcolLeft4, eLayerType::WallCollider);
	WallColliderRight* wallcolRight5 = new WallColliderRight(); AddGameObeject(wallcolRight5, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft5 = new WallColliderLeft(); AddGameObeject(wallcolLeft5, eLayerType::WallCollider);
	WallColliderRight* wallcolRight6 = new WallColliderRight(); AddGameObeject(wallcolRight6, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft6 = new WallColliderLeft(); AddGameObeject(wallcolLeft6, eLayerType::WallCollider);



	//----------------------------바닥 오브젝트---------------------------------
	Ground* ground0 = new Ground(); AddGameObeject(ground0, eLayerType::Ground);
	Ground* ground1 = new Ground(); AddGameObeject(ground1, eLayerType::Ground);
	Ground* ground2 = new Ground(); AddGameObeject(ground2, eLayerType::Ground);
	Ground* ground3 = new Ground(); AddGameObeject(ground3, eLayerType::Ground);
	Ground* ground4 = new Ground(); AddGameObeject(ground4, eLayerType::Ground);
	Ground* ground5 = new Ground(); AddGameObeject(ground5, eLayerType::Ground);
	Ground* ground6 = new Ground(); AddGameObeject(ground6, eLayerType::Ground);

	Scene::Initialize();

	//-------------------------포탈Pos----------------------------------
	portal0->GetComponent<Transform>()->SetPos(Vector2(100.0f, 560.0f));
	portal1->GetComponent<Transform>()->SetPos(Vector2(2000.0f, 1210.0f));

	//------------------------------------------------------------바닥Pos----------------------------------------------------------------------
	ground0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 1210.0f));   ground0->GetComponent<Collider>()->SetSize(Vector2(2100.0f, 30.0f));
	ground1->GetComponent<Transform>()->SetPos(Vector2(0.0f, 975.0f));    ground1->GetComponent<Collider>()->SetSize(Vector2(650.0f, 30.0f));
	ground2->GetComponent<Transform>()->SetPos(Vector2(0.0f, 555.0f));    ground2->GetComponent<Collider>()->SetSize(Vector2(650.0f, 30.0f));
	ground3->GetComponent<Transform>()->SetPos(Vector2(1445.0f, 555.0f)); ground3->GetComponent<Collider>()->SetSize(Vector2(650.0f, 30.0f));
	ground4->GetComponent<Transform>()->SetPos(Vector2(1445.0f, 975.0f)); ground4->GetComponent<Collider>()->SetSize(Vector2(650.0f, 30.0f));
	ground5->GetComponent<Transform>()->SetPos(Vector2(665.0f, 855.0f));  ground5->GetComponent<Collider>()->SetSize(Vector2(778.0f, 30.0f));
	ground6->GetComponent<Transform>()->SetPos(Vector2(665.0f, 435.0f));  ground6->GetComponent<Collider>()->SetSize(Vector2(778.0f, 30.0f));

	//-----------------------방향 충돌체Pos--------------------------------------------- 왼쪽 = Ground의 X축값 , 오른쪽 = Ground의 X축값 + collider사이즈 - 10, Y축 GroundY축값 - 10
	wallcolLeft1->GetComponent<Transform>()->SetPos(Vector2(0.0f, 965.0f)); wallcolLeft1->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f)); //4마리
	wallcolRight1->GetComponent<Transform>()->SetPos(Vector2(640.0f, 965.0f)); wallcolRight1->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolLeft3->GetComponent<Transform>()->SetPos(Vector2(1445.0f, 545.0f)); wallcolLeft3->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f)); //4마리
	wallcolRight3->GetComponent<Transform>()->SetPos(Vector2(2085.0f, 545.0f)); wallcolRight3->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolLeft4->GetComponent<Transform>()->SetPos(Vector2(1445.0f, 965.0f)); wallcolLeft4->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f)); //4마리
	wallcolRight4->GetComponent<Transform>()->SetPos(Vector2(2085.0f, 965.0f)); wallcolRight4->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolLeft5->GetComponent<Transform>()->SetPos(Vector2(665.0f, 845.0f)); wallcolLeft5->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f)); //5마리
	wallcolRight5->GetComponent<Transform>()->SetPos(Vector2(1433.0f, 845.0f)); wallcolRight5->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolLeft6->GetComponent<Transform>()->SetPos(Vector2(665.0f, 425.0f)); wallcolLeft6->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f)); //5마리
	wallcolRight6->GetComponent<Transform>()->SetPos(Vector2(1433.0f, 425.0f)); wallcolRight6->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));

	//-------------------------------몬스터Pos-------------------------------- x축 = GroundX축 + 50, Y축 = GroundY축 , 몬스터 간격 X축 + 150
	//1번 바닥
	m_happy0->GetComponent<Transform>()->SetPos(Vector2(80.0f, 975.0f));
	m_happy1->GetComponent<Transform>()->SetPos(Vector2(230.0f, 975.0f)); 
	m_happy2->GetComponent<Transform>()->SetPos(Vector2(380.0f, 975.0f)); m_happy2->SetInitialize_Direction(1);
	m_happy3->GetComponent<Transform>()->SetPos(Vector2(530.0f, 975.0f)); m_happy3->SetInitialize_Direction(1);
	//3번 바닥
	m_happy4->GetComponent<Transform>()->SetPos(Vector2(1530.0f, 555.0f));
	m_happy5->GetComponent<Transform>()->SetPos(Vector2(1680.0f, 555.0f));
	m_happy6->GetComponent<Transform>()->SetPos(Vector2(1830.0f, 555.0f)); m_happy6->SetInitialize_Direction(1);
	m_happy7->GetComponent<Transform>()->SetPos(Vector2(1980.0f, 555.0f)); m_happy7->SetInitialize_Direction(1);
	//4번 바닥
	m_happy8->GetComponent<Transform>()->SetPos(Vector2(1530.0f, 975.0f));
	m_happy9->GetComponent<Transform>()->SetPos(Vector2(1680.0f, 975.0f));
	m_happy10->GetComponent<Transform>()->SetPos(Vector2(1830.0f, 975.0f)); m_happy10->SetInitialize_Direction(1);
	m_happy11->GetComponent<Transform>()->SetPos(Vector2(1980.0f, 975.0f));	m_happy11->SetInitialize_Direction(1);
	//5번 바닥
	m_happy12->GetComponent<Transform>()->SetPos(Vector2(750.0f, 855.0f));
	m_happy13->GetComponent<Transform>()->SetPos(Vector2(900.0f, 855.0f));
	m_happy14->GetComponent<Transform>()->SetPos(Vector2(1050.0f, 855.0f)); 
	m_happy15->GetComponent<Transform>()->SetPos(Vector2(1200.0f, 855.0f));	m_happy15->SetInitialize_Direction(1);
	m_happy16->GetComponent<Transform>()->SetPos(Vector2(1350.0f, 855.0f));	m_happy16->SetInitialize_Direction(1);
	//6번 바닥
	m_happy17->GetComponent<Transform>()->SetPos(Vector2(750.0f, 435.0f));
	m_happy18->GetComponent<Transform>()->SetPos(Vector2(900.0f, 435.0f));
	m_happy19->GetComponent<Transform>()->SetPos(Vector2(1050.0f, 435.0f));
	m_happy20->GetComponent<Transform>()->SetPos(Vector2(1200.0f, 435.0f)); m_happy20->SetInitialize_Direction(1);
	m_happy21->GetComponent<Transform>()->SetPos(Vector2(1350.0f, 435.0f)); m_happy21->SetInitialize_Direction(1);
}
void SomyeolScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Arcana);
	}
	Scene::Update();

	Camera::SetTarget(mMainChar);
}
void SomyeolScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void SomyeolScene::Release()
{
}
void SomyeolScene::OnEnter()
{
	mMainChar->GetComponent<Transform>()->SetPos(Vector2(600.0f, 1050.0f));
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
	CollisionManager::SetLayer(eLayerType::Monster, eLayerType::WallCollider, true);

	Camera::SetLookRange(Vector2(2095.f, 1360.f));
}
void SomyeolScene::OnExit()
{
}