#include "Arcana.h"
#include "ArcanaBack.h"
#include "ArcanaObject.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"
#include "waterspirit.h"
#include "Camera.h"
#include "CollisionManager.h"
#include "Ground.h"
#include "Transform.h"
#include "Portal.h"
#include "WallColliderLeft.h"
#include "WallColliderRight.h"
#include "Sound.h"
#include "RResources.h"

#include "Exbar.h"
#include "Hp_Mp.h"
#include "Menubar.h"
#include "Skillbar.h"

Arcana::Arcana()
{
	
}
Arcana::~Arcana()
{
}
void Arcana::Initialize()
{
	m_arcanaback = new ArcanaBack();
	AddGameObeject(m_arcanaback, eLayerType::BG);
	m_arcanaobject = new ArcanaObject();
	AddGameObeject(m_arcanaobject, eLayerType::BG);
	m_mainchar = new MainChar();
	AddGameObeject(m_mainchar, eLayerType::Player);

	Exbar* exbar = new Exbar();
	AddGameObeject(exbar, eLayerType::UI);

	Hp_Mp* hp = new Hp_Mp();
	AddGameObeject(hp, eLayerType::UI);

	Menubar* menu = new Menubar();
	AddGameObeject(menu, eLayerType::UI);

	Skillbar* skillbar = new Skillbar();
	AddGameObeject(skillbar, eLayerType::UI);

	ArcanaSound = RResources::Load<Sound>(L"ArcanaSound", L"..\\Resources\\Sound\\Map_Sound\\Arcana.wav");
	NextMap = RResources::Load<Sound>(L"NextMap", L"..\\Resources\\Sound\\UI_Sound\\Portal.wav");

	//--------------------------포탈 오브젝트----------------------------------
	Portal* portal0 = new Portal(); AddGameObeject(portal0, eLayerType::Portal);
	Portal* portal1 = new Portal(); AddGameObeject(portal1, eLayerType::Portal);

	//---------------------------바닥 오브젝트-----------------------------------
	Ground* ground0 = new Ground(); AddGameObeject(ground0, eLayerType::Monster);
	Ground* ground1 = new Ground(); AddGameObeject(ground1, eLayerType::Monster);
	Ground* ground2 = new Ground(); AddGameObeject(ground2, eLayerType::Monster);
	Ground* ground3 = new Ground(); AddGameObeject(ground3, eLayerType::Monster);
	Ground* ground4 = new Ground(); AddGameObeject(ground4, eLayerType::Monster);
	Ground* ground5 = new Ground(); AddGameObeject(ground5, eLayerType::Monster);

	//------------------------------------------방향충돌체 오브젝트-----------------------------------------------------
	WallColliderRight* wallcolRight0 = new WallColliderRight(); AddGameObeject(wallcolRight0, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft0 = new WallColliderLeft(); AddGameObeject(wallcolLeft0, eLayerType::WallCollider);
	WallColliderRight* wallcolRight2 = new WallColliderRight(); AddGameObeject(wallcolRight2, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft2 = new WallColliderLeft(); AddGameObeject(wallcolLeft2, eLayerType::WallCollider);
	WallColliderRight* wallcolRight3 = new WallColliderRight(); AddGameObeject(wallcolRight3, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft3 = new WallColliderLeft(); AddGameObeject(wallcolLeft3, eLayerType::WallCollider);
	WallColliderRight* wallcolRight4 = new WallColliderRight(); AddGameObeject(wallcolRight4, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft4 = new WallColliderLeft(); AddGameObeject(wallcolLeft4, eLayerType::WallCollider);
	WallColliderRight* wallcolRight5 = new WallColliderRight(); AddGameObeject(wallcolRight5, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft5 = new WallColliderLeft(); AddGameObeject(wallcolLeft5, eLayerType::WallCollider);

	//-------------------------------------물의 정령 오브젝트---------------------------------------------
	waterspirit* m_waterspirit0 = new waterspirit(); AddGameObeject(m_waterspirit0, eLayerType::Monster);
	waterspirit* m_waterspirit1 = new waterspirit(); AddGameObeject(m_waterspirit1, eLayerType::Monster);
	waterspirit* m_waterspirit2 = new waterspirit(); AddGameObeject(m_waterspirit2, eLayerType::Monster);
	waterspirit* m_waterspirit3 = new waterspirit(); AddGameObeject(m_waterspirit3, eLayerType::Monster);
	waterspirit* m_waterspirit4 = new waterspirit(); AddGameObeject(m_waterspirit4, eLayerType::Monster);
	waterspirit* m_waterspirit5 = new waterspirit(); AddGameObeject(m_waterspirit5, eLayerType::Monster);
	waterspirit* m_waterspirit6 = new waterspirit(); AddGameObeject(m_waterspirit6, eLayerType::Monster);
	waterspirit* m_waterspirit7 = new waterspirit(); AddGameObeject(m_waterspirit7, eLayerType::Monster);
	waterspirit* m_waterspirit8 = new waterspirit(); AddGameObeject(m_waterspirit8, eLayerType::Monster);
	waterspirit* m_waterspirit9 = new waterspirit(); AddGameObeject(m_waterspirit9, eLayerType::Monster);
	waterspirit* m_waterspirit10 = new waterspirit(); AddGameObeject(m_waterspirit10, eLayerType::Monster);
	waterspirit* m_waterspirit11 = new waterspirit(); AddGameObeject(m_waterspirit11, eLayerType::Monster);
	waterspirit* m_waterspirit12 = new waterspirit(); AddGameObeject(m_waterspirit12, eLayerType::Monster);
	waterspirit* m_waterspirit13 = new waterspirit(); AddGameObeject(m_waterspirit13, eLayerType::Monster);
	waterspirit* m_waterspirit14 = new waterspirit(); AddGameObeject(m_waterspirit14, eLayerType::Monster);
	waterspirit* m_waterspirit15 = new waterspirit(); AddGameObeject(m_waterspirit15, eLayerType::Monster);
	waterspirit* m_waterspirit16 = new waterspirit(); AddGameObeject(m_waterspirit16, eLayerType::Monster);
	waterspirit* m_waterspirit17 = new waterspirit(); AddGameObeject(m_waterspirit17, eLayerType::Monster);
	waterspirit* m_waterspirit18 = new waterspirit(); AddGameObeject(m_waterspirit18, eLayerType::Monster);
	waterspirit* m_waterspirit19 = new waterspirit(); AddGameObeject(m_waterspirit19, eLayerType::Monster);

	Scene::Initialize();

	//-------------------------------------------------------바닥Pos-------------------------------------------------------------------------
	ground0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 1005.0f)); ground0->GetComponent<Collider>()->SetSize(Vector2(2800.0f, 30.0f));
	ground1->GetComponent<Transform>()->SetPos(Vector2(0.0f, 370.0f)); ground1->GetComponent<Collider>()->SetSize(Vector2(510.0f, 30.0f));
	ground2->GetComponent<Transform>()->SetPos(Vector2(500.0f, 580.0f)); ground2->GetComponent<Collider>()->SetSize(Vector2(510.0f, 30.0f));
	ground3->GetComponent<Transform>()->SetPos(Vector2(990.0f, 730.0f)); ground3->GetComponent<Collider>()->SetSize(Vector2(600.0f, 30.0f));
	ground4->GetComponent<Transform>()->SetPos(Vector2(1580.0f, 580.0f)); ground4->GetComponent<Collider>()->SetSize(Vector2(510.0f, 30.0f));
	ground5->GetComponent<Transform>()->SetPos(Vector2(2070.0f, 730.0f)); ground5->GetComponent<Collider>()->SetSize(Vector2(510.0f, 30.0f));

	//------------------------포탈pos------------------------------------
	portal0->GetComponent<Transform>()->SetPos(Vector2(160.0f, 370.0f));
	portal1->GetComponent<Transform>()->SetPos(Vector2(2650.0f, 1000.0f));

	//-----------------------방향 충돌체Pos--------------------------------------------- 왼쪽 = Ground의 X축값 , 오른쪽 = Ground의 X축값 + collider사이즈 - 10, Y축 GroundY축값 - 10
	wallcolLeft0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 995.0f)); wallcolLeft0->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolRight0->GetComponent<Transform>()->SetPos(Vector2(2760.0f, 995.0f)); wallcolRight0->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolLeft2->GetComponent<Transform>()->SetPos(Vector2(500.0f, 570.0f)); wallcolLeft2->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolRight2->GetComponent<Transform>()->SetPos(Vector2(1000.0f, 570.0f)); wallcolRight2->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolLeft3->GetComponent<Transform>()->SetPos(Vector2(990.0f, 720.0f)); wallcolLeft3->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolRight3->GetComponent<Transform>()->SetPos(Vector2(1580.0f, 720.0f)); wallcolRight3->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolLeft4->GetComponent<Transform>()->SetPos(Vector2(1580.0f, 570.0f)); wallcolLeft4->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolRight4->GetComponent<Transform>()->SetPos(Vector2(2080.0f, 570.0f)); wallcolRight4->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolLeft5->GetComponent<Transform>()->SetPos(Vector2(2070.0f, 720.0f)); wallcolLeft5->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolRight5->GetComponent<Transform>()->SetPos(Vector2(2570.0f, 720.0f)); wallcolRight5->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));

	//0번 바닥
	m_waterspirit0->GetComponent<Transform>()->SetPos(Vector2(300.0f, 995.0f));
	m_waterspirit1->GetComponent<Transform>()->SetPos(Vector2(600.0f, 995.0f)); m_waterspirit1->SetInitialize_Direction(1);
	m_waterspirit2->GetComponent<Transform>()->SetPos(Vector2(900.0f, 995.0f));
	m_waterspirit3->GetComponent<Transform>()->SetPos(Vector2(1200.0f, 995.0f)); m_waterspirit3->SetInitialize_Direction(1);
	m_waterspirit4->GetComponent<Transform>()->SetPos(Vector2(1500.0f, 995.0f)); 
	m_waterspirit5->GetComponent<Transform>()->SetPos(Vector2(1800.0f, 995.0f)); m_waterspirit5->SetInitialize_Direction(1);
	m_waterspirit6->GetComponent<Transform>()->SetPos(Vector2(2100.0f, 995.0f)); 
	m_waterspirit7->GetComponent<Transform>()->SetPos(Vector2(2400.0f, 995.0f)); m_waterspirit7->SetInitialize_Direction(1);
	//2번 바닥
	m_waterspirit8->GetComponent<Transform>()->SetPos(Vector2(600.0f, 580.0f)); m_waterspirit8->SetInitialize_Direction(1);
	m_waterspirit9->GetComponent<Transform>()->SetPos(Vector2(750.0f, 580.0f));
	m_waterspirit10->GetComponent<Transform>()->SetPos(Vector2(900.0f, 580.0f)); m_waterspirit10->SetInitialize_Direction(1);
	//3번 바닥
	m_waterspirit11->GetComponent<Transform>()->SetPos(Vector2(1150.0f, 730.0f));
	m_waterspirit12->GetComponent<Transform>()->SetPos(Vector2(1300.0f, 730.0f)); m_waterspirit12->SetInitialize_Direction(1);
	m_waterspirit13->GetComponent<Transform>()->SetPos(Vector2(1450.0f, 730.0f));
	//4번 바닥
	m_waterspirit14->GetComponent<Transform>()->SetPos(Vector2(1680.0f, 580.0f)); m_waterspirit14->SetInitialize_Direction(1);
	m_waterspirit15->GetComponent<Transform>()->SetPos(Vector2(1830.0f, 580.0f));
	m_waterspirit16->GetComponent<Transform>()->SetPos(Vector2(1990.0f, 580.0f));
	//5번 바닥
	m_waterspirit17->GetComponent<Transform>()->SetPos(Vector2(2170.0f, 730.0f));
	m_waterspirit18->GetComponent<Transform>()->SetPos(Vector2(2320.0f, 730.0f)); m_waterspirit18->SetInitialize_Direction(1);
	m_waterspirit19->GetComponent<Transform>()->SetPos(Vector2(2470.0f, 730.0f)); m_waterspirit19->SetInitialize_Direction(1);
}
void Arcana::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Boss_Enter);
	}

	Scene::Update();

	Camera::SetTarget(m_mainchar);

}
void Arcana::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void Arcana::Release()
{
	Scene::Release();
}
void Arcana::OnEnter()
{
	ArcanaSound->Play(true);
	m_mainchar->GetComponent<Transform>()->SetPos(Vector2(160.0f, 500.0f));
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
	CollisionManager::SetLayer(eLayerType::Monster, eLayerType::WallCollider, true);
	
	Camera::SetImgResolution(Vector2(2770.f, 1180.f));
}
void Arcana::OnExit()
{
	ArcanaSound->Stop(true);
	NextMap->Play(false);
}