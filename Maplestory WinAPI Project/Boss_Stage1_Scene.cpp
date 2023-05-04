#include "Boss_Stage1_Scene.h"
#include "Boss_Stage1_Back.h"
#include "Boss_Stage1_Object.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"
#include "Boss_Ion.h"
#include "Boss_Yaldabaoth.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "Ground.h"
#include "Transform.h"
#include "Boss_Ion.h"
#include "Sound.h"
#include "RResources.h"
#include "Time.h"
#include "IonHP.h"
#include "YalHP.h"

#include "Portal.h"
#include "Exbar.h"
#include "Hp_Mp.h"
#include "Menubar.h"
#include "Skillbar.h"

Boss_Stage1_Scene::Boss_Stage1_Scene()
	: mTime(0.0f)
	, produce(false)
{
}
Boss_Stage1_Scene::~Boss_Stage1_Scene()
{
}
void Boss_Stage1_Scene::Initialize()
{
	m_Boss_Stage1_Back = new Boss_Stage1_Back();
	AddGameObeject(m_Boss_Stage1_Back, eLayerType::BG);
	m_Boss_Stage1_Object = new Boss_Stage1_Object();
	AddGameObeject(m_Boss_Stage1_Object, eLayerType::BG);

	ionhp = new IonHP();
	AddGameObeject(ionhp, eLayerType::UI);

	yalhp = new YalHP();
	AddGameObeject(yalhp, eLayerType::UI);

	Portal* portal = new Portal();
	AddGameObeject(portal, eLayerType::Portal);

	Exbar* exbar = new Exbar();
	AddGameObeject(exbar, eLayerType::UI);

	Hp_Mp* hp = new Hp_Mp();
	AddGameObeject(hp, eLayerType::UI);

	Menubar* menu = new Menubar();
	AddGameObeject(menu, eLayerType::UI);

	Skillbar* skillbar = new Skillbar();
	AddGameObeject(skillbar, eLayerType::UI);


	Stage1 = RResources::Load<Sound>(L"Stage1", L"..\\Resources\\Sound\\Map_Sound\\boss_stage1.wav");
	NextMap = RResources::Load<Sound>(L"NextMap", L"..\\Resources\\Sound\\UI_Sound\\Portal.wav");

	Ground* ground0 = new Ground();
	AddGameObeject(ground0, eLayerType::Ground);

	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);

	m_Boss_Ion = new Boss_Ion();
	AddGameObeject(m_Boss_Ion, eLayerType::Monster);

	m_Boss_Yaldabaoth = new Boss_Yaldabaoth();
	AddGameObeject(m_Boss_Yaldabaoth, eLayerType::Monster);

	Scene::Initialize();
	m_Boss_Ion->GetComponent<Transform>()->SetPos(Vector2(1800, 820));
	m_Boss_Ion->GetComponent<Transform>()->SetScale(Vector2(1.15f, 1.15f));
	m_Boss_Yaldabaoth->GetComponent<Transform>()->SetPos(Vector2(2700, 860));
	m_Boss_Yaldabaoth->GetComponent<Transform>()->SetScale(Vector2(1.15f, 1.15f));

	ground0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 770.0f));
	ground0->GetComponent<Collider>()->SetSize(Vector2(5000.0f, 30.0f));

	portal->GetComponent<Transform>()->SetPos(Vector2(510.0f, 770.0f));

}
void Boss_Stage1_Scene::Update()
{
	ionhp->Ion_HP = m_Boss_Ion->GetionHP();
	yalhp->Yal_HP = m_Boss_Yaldabaoth->GetYalHP();

	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Boss_Stage2_Ani);
	}

	IDie = m_Boss_Ion->GetDieState();
	YDie = m_Boss_Yaldabaoth->GetDieState();
	if (IDie && YDie)
	{
		mTime += Time::DeltaTime();
		if(mTime > 4.0f)
			SceneManager::LoadScene(eSceneType::Boss_Stage2_Ani);
	}

	Scene::Update();

	Camera::SetTarget(mMainChar);

}
void Boss_Stage1_Scene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void Boss_Stage1_Scene::Release()
{
	Scene::Release();
}
void Boss_Stage1_Scene::OnEnter()
{
	Stage1->Play(true);
	mMainChar->GetComponent<Transform>()->SetPos(Vector2(2300.0f, 800.0f));
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);

	m_Boss_Yaldabaoth->Yaldabaoth_respawn();
	m_Boss_Ion->Ion_respawn();

	Camera::SetImgResolution(Vector2(4520.f, 880.f));
}
void Boss_Stage1_Scene::OnExit()
{
	Stage1->Stop(true);
	NextMap->Play(false);
}