#include "HenesysScene.h"
#include "HenesysBack.h"
#include "MainChar.h"
#include "Input.h"
#include "SceneManager.h"
#include "mushroom.h"
#include "RedSnail.h"
#include "Transform.h"
#include "Camera.h"
#include "CollisionManager.h"
#include "Ground.h"
#include "GameObject.h"
#include "HenesysObject.h"
#include "Rigidbody.h"
#include "Portal.h"
#include "MainChar_GroundCollider.h"
#include "Camera.h"
#include "WallColliderLeft.h"
#include "WallColliderRight.h"
#include "Sound.h"
#include "RResources.h"

#include "Exbar.h"
#include "Hp_Mp.h"
#include "Menubar.h"
#include "Skillbar.h"

HenesysScene::HenesysScene()
{
}
HenesysScene::~HenesysScene()
{
}
void HenesysScene::Initialize()
{
	//헤네시스 배경
	HenesysBack* m_henesysBack = new HenesysBack();
	AddGameObeject(m_henesysBack, eLayerType::BG);

	HenesysObject* m_henesysobject = new HenesysObject();
	AddGameObeject(m_henesysobject, eLayerType::Object);

	Exbar* exbar = new Exbar();
	AddGameObeject(exbar, eLayerType::UI);

	Hp_Mp* hp = new Hp_Mp();
	AddGameObeject(hp, eLayerType::UI);

	Menubar* menu = new Menubar();
	AddGameObeject(menu, eLayerType::UI);

	Skillbar* skillbar = new Skillbar();
	AddGameObeject(skillbar, eLayerType::UI);

	HenesysSound = RResources::Load<Sound>(L"HenesysSound", L"..\\Resources\\Sound\\Map_Sound\\Henesys.wav");
	NextMap = RResources::Load<Sound>(L"NextMap", L"..\\Resources\\Sound\\UI_Sound\\Portal.wav");


	//캐릭터
	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);


	MainChar_GroundCollider* CGround = new MainChar_GroundCollider();
	AddGameObeject(CGround, eLayerType::PlayerGround);

	//-------------------------포탈 오브젝트-----------------------------------------
	Portal* m_portal0 = new Portal(); AddGameObeject(m_portal0, eLayerType::Portal);
	Portal* m_portal1 = new Portal(); AddGameObeject(m_portal1, eLayerType::Portal);
	
	//------------------------주황버섯 몬스터 오브젝트----------------------------------------
	//1번 바닥
	m_mushroom0 = new mushroom(); AddGameObeject(m_mushroom0, eLayerType::Monster);
	m_mushroom1 = new mushroom(); AddGameObeject(m_mushroom1, eLayerType::Monster);
	m_mushroom2 = new mushroom(); AddGameObeject(m_mushroom2, eLayerType::Monster);
	m_mushroom3 = new mushroom(); AddGameObeject(m_mushroom3, eLayerType::Monster);
	//4번 바닥
	m_mushroom4 = new mushroom(); AddGameObeject(m_mushroom4, eLayerType::Monster);
	m_mushroom5 = new mushroom(); AddGameObeject(m_mushroom5, eLayerType::Monster);
	m_mushroom6 = new mushroom(); AddGameObeject(m_mushroom6, eLayerType::Monster);
	m_mushroom7 = new mushroom(); AddGameObeject(m_mushroom7, eLayerType::Monster);
	//6번 바닥
	m_mushroom8 = new mushroom(); AddGameObeject(m_mushroom8, eLayerType::Monster);
	m_mushroom9 = new mushroom(); AddGameObeject(m_mushroom9, eLayerType::Monster);
	m_mushroom10 = new mushroom(); AddGameObeject(m_mushroom10, eLayerType::Monster);
	m_mushroom11 = new mushroom(); AddGameObeject(m_mushroom11, eLayerType::Monster);
	m_mushroom12 = new mushroom(); AddGameObeject(m_mushroom12, eLayerType::Monster);
	//7번 바닥
	m_mushroom13 = new mushroom(); AddGameObeject(m_mushroom13, eLayerType::Monster);
	m_mushroom14 = new mushroom(); AddGameObeject(m_mushroom14, eLayerType::Monster);
	m_mushroom15 = new mushroom(); AddGameObeject(m_mushroom15, eLayerType::Monster);
	m_mushroom16 = new mushroom(); AddGameObeject(m_mushroom16, eLayerType::Monster);
	//8번 바닥
	m_mushroom17 = new mushroom(); AddGameObeject(m_mushroom17, eLayerType::Monster);
	m_mushroom18 = new mushroom(); AddGameObeject(m_mushroom18, eLayerType::Monster);
	m_mushroom19 = new mushroom(); AddGameObeject(m_mushroom19, eLayerType::Monster);
	m_mushroom20 = new mushroom(); AddGameObeject(m_mushroom20, eLayerType::Monster);


	//------------------------------------------방향충돌체 오브젝트-----------------------------------------------------
	WallColliderRight* wallcolRight6 = new WallColliderRight(); AddGameObeject(wallcolRight6, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft6 = new WallColliderLeft(); AddGameObeject(wallcolLeft6, eLayerType::WallCollider);
	WallColliderRight* wallcolRight1 = new WallColliderRight(); AddGameObeject(wallcolRight1, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft1 = new WallColliderLeft(); AddGameObeject(wallcolLeft1, eLayerType::WallCollider);
	WallColliderRight* wallcolRight7 = new WallColliderRight(); AddGameObeject(wallcolRight7, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft7 = new WallColliderLeft(); AddGameObeject(wallcolLeft7, eLayerType::WallCollider);
	WallColliderRight* wallcolRight8 = new WallColliderRight(); AddGameObeject(wallcolRight8, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft8 = new WallColliderLeft(); AddGameObeject(wallcolLeft8, eLayerType::WallCollider);
	WallColliderRight* wallcolRight4 = new WallColliderRight(); AddGameObeject(wallcolRight4, eLayerType::WallCollider);
	WallColliderLeft* wallcolLeft4 = new WallColliderLeft(); AddGameObeject(wallcolLeft4, eLayerType::WallCollider);

	//---------------------------바닥 오브젝트----------------------------------
	Ground* ground0 = new Ground(); AddGameObeject(ground0, eLayerType::Ground);
	Ground* ground1 = new Ground(); AddGameObeject(ground1, eLayerType::Ground);
	Ground* ground2 = new Ground(); AddGameObeject(ground2, eLayerType::Ground);
	Ground* ground3 = new Ground(); AddGameObeject(ground3, eLayerType::Ground);
	Ground* ground4 = new Ground(); AddGameObeject(ground4, eLayerType::Ground);
	Ground* ground5 = new Ground(); AddGameObeject(ground5, eLayerType::Ground);
	Ground* ground6 = new Ground(); AddGameObeject(ground6, eLayerType::Ground);
	Ground* ground7 = new Ground(); AddGameObeject(ground7, eLayerType::Ground);
	Ground* ground8 = new Ground(); AddGameObeject(ground8, eLayerType::Ground);


	Scene::Initialize();
	//1번 바닥
	//-----------------------------------------------------바닥Pos-----------------------------------------------------------------------------
	ground0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 880.0f));    ground0->GetComponent<Collider>()->SetSize(Vector2(1900.0f, 30.0f));
	ground1->GetComponent<Transform>()->SetPos(Vector2(110.0f, 310.0f));  ground1->GetComponent<Collider>()->SetSize(Vector2(680.0f, 30.0f));
	ground2->GetComponent<Transform>()->SetPos(Vector2(1190.0f, 310.0f)); ground2->GetComponent<Collider>()->SetSize(Vector2(140.0f, 30.0f));
	ground3->GetComponent<Transform>()->SetPos(Vector2(830.0f, 250.0f));  ground3->GetComponent<Collider>()->SetSize(Vector2(320.0f, 30.0f));
	ground4->GetComponent<Transform>()->SetPos(Vector2(745.0f, 430.0f));  ground4->GetComponent<Collider>()->SetSize(Vector2(485.0f, 30.0f));
	ground5->GetComponent<Transform>()->SetPos(Vector2(1280.0f, 430.0f)); ground5->GetComponent<Collider>()->SetSize(Vector2(50.0f, 30.0f));
	ground6->GetComponent<Transform>()->SetPos(Vector2(650.0f, 610.0f));  ground6->GetComponent<Collider>()->SetSize(Vector2(680.0f, 30.0f)); //set monster
	ground7->GetComponent<Transform>()->SetPos(Vector2(110.0f, 670.0f));  ground7->GetComponent<Collider>()->SetSize(Vector2(500.0f, 30.0f));
	ground8->GetComponent<Transform>()->SetPos(Vector2(1375.0f, 370.0f)); ground8->GetComponent<Collider>()->SetSize(Vector2(495.0f, 30.0f));


	//-------------------------포탈 오브젝트Pos-----------------------------------------
	m_portal0->GetComponent<Transform>()->SetPos(Vector2(1050.0f, 250.0f));
	m_portal1->GetComponent<Transform>()->SetPos(Vector2(1800.0f, 880.0f));

	//-----------------------방향 충돌체Pos--------------------------------------------- 왼쪽 = Ground의 X축값 , 오른쪽 = Ground의 X축값 + collider사이즈 - 10, Y축 GroundY축값 - 10
	wallcolLeft6->GetComponent<Transform>()->SetPos(Vector2(650.0f, 600.0f)); wallcolLeft6->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolRight6->GetComponent<Transform>()->SetPos(Vector2(1320.0f, 600.0f)); wallcolRight6->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolLeft1->GetComponent<Transform>()->SetPos(Vector2(110.0f, 300.0f)); wallcolLeft1->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolRight1->GetComponent<Transform>()->SetPos(Vector2(780.0f, 300.0f)); wallcolRight1->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolLeft4->GetComponent<Transform>()->SetPos(Vector2(745.0f, 420.0f)); wallcolLeft4->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolRight4->GetComponent<Transform>()->SetPos(Vector2(1220.0f, 420.0f)); wallcolRight4->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolLeft7->GetComponent<Transform>()->SetPos(Vector2(110.0f, 660.0f)); wallcolLeft7->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolRight7->GetComponent<Transform>()->SetPos(Vector2(600.0f, 660.0f)); wallcolRight7->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolLeft8->GetComponent<Transform>()->SetPos(Vector2(1375.0f,360.0f)); wallcolLeft8->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));
	wallcolRight8->GetComponent<Transform>()->SetPos(Vector2(1860.0f, 360.0f)); wallcolRight8->GetComponent<Collider>()->SetSize(Vector2(10.0f, -10.0f));


	//-------------------------------------------주황버섯Pos------------------------------------------------------------
	m_mushroom0->GetComponent<Transform>()->SetPos(Vector2(130.0f, 310.0f));
	m_mushroom1->GetComponent<Transform>()->SetPos(Vector2(330.0f, 310.0f));
	m_mushroom2->GetComponent<Transform>()->SetPos(Vector2(530.0f, 310.0f)); m_mushroom2->SetInitialize_Direction(1);
	m_mushroom3->GetComponent<Transform>()->SetPos(Vector2(730.0f, 310.0f)); m_mushroom3->SetInitialize_Direction(1);
	//4번 바닥
	m_mushroom4->GetComponent<Transform>()->SetPos(Vector2(760.0f, 430.0f));
	m_mushroom5->GetComponent<Transform>()->SetPos(Vector2(910.0f, 430.0f));
	m_mushroom6->GetComponent<Transform>()->SetPos(Vector2(1060.0f, 430.0f)); m_mushroom6->SetInitialize_Direction(1);
	m_mushroom7->GetComponent<Transform>()->SetPos(Vector2(1210.0f, 430.0f)); m_mushroom7->SetInitialize_Direction(1);
	//6번 바닥
	m_mushroom8->GetComponent<Transform>()->SetPos(Vector2(670.0f, 610.0f));
	m_mushroom9->GetComponent<Transform>()->SetPos(Vector2(870.0f, 610.0f));
	m_mushroom10->GetComponent<Transform>()->SetPos(Vector2(1070.0f, 610.0f)); m_mushroom10->SetInitialize_Direction(1);
	m_mushroom11->GetComponent<Transform>()->SetPos(Vector2(1270.0f, 610.0f)); m_mushroom11->SetInitialize_Direction(1);
	m_mushroom12->GetComponent<Transform>()->SetPos(Vector2(1370.0f, 610.0f)); m_mushroom11->SetInitialize_Direction(1);
	//7번 바닥
	m_mushroom13->GetComponent<Transform>()->SetPos(Vector2(130.0f, 670.0f));
	m_mushroom14->GetComponent<Transform>()->SetPos(Vector2(300.0f, 670.0f)); 
	m_mushroom15->GetComponent<Transform>()->SetPos(Vector2(470.0f, 670.0f)); m_mushroom15->SetInitialize_Direction(1);
	m_mushroom16->GetComponent<Transform>()->SetPos(Vector2(640.0f, 670.0f)); m_mushroom16->SetInitialize_Direction(1);
	//8번 바닥
	m_mushroom17->GetComponent<Transform>()->SetPos(Vector2(1390.0f, 370.0f));
	m_mushroom18->GetComponent<Transform>()->SetPos(Vector2(1540.0f, 370.0f));
	m_mushroom19->GetComponent<Transform>()->SetPos(Vector2(1690.0f, 370.0f)); m_mushroom19->SetInitialize_Direction(1);
	m_mushroom20->GetComponent<Transform>()->SetPos(Vector2(1840.0f, 370.0f)); m_mushroom20->SetInitialize_Direction(1);




}
void HenesysScene::Update()
{
	/*if(mMainChar->GetPotalState() == true)
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Somyeol);
	}*/

	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Somyeol);
	}
	Scene::Update();

	Camera::SetTarget(mMainChar);
}
void HenesysScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void HenesysScene::Release()
{
}
void HenesysScene::OnEnter()
{
	HenesysSound->Play(true);

	mMainChar->GetComponent<Transform>()->SetPos(Vector2(1050.0f, 350.0f));
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
	CollisionManager::SetLayer(eLayerType::Monster, eLayerType::WallCollider, true);

	Camera::SetImgResolution(Vector2(1890.f, 1080.f));

	
}
void HenesysScene::OnExit()
{
	HenesysSound->Stop(true);
	NextMap->Play(false);
}