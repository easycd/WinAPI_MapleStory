#include "Boss_Stage2_Scene.h"
#include "Boss_Stage2_Back.h"
#include "Boss_Stage2_Object.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "Ground.h"
#include "Transform.h"
#include "Boss.h"
#include "CircleObj.h"
#include "Time.h"
#include "Sound.h"
#include "RResources.h"
#include"BossHP_State.h"
#include "BossHP_Bar.h"

#include "Exbar.h"
#include "Hp_Mp.h"
#include "Menubar.h"
#include "Skillbar.h"

Boss_Stage2_Scene::Boss_Stage2_Scene()
	: mTime(0.0f)
	, bossHpCnt(0)
	, cnt(0)
{
}
Boss_Stage2_Scene::~Boss_Stage2_Scene()
{
}
void Boss_Stage2_Scene::Initialize()
{
	m_Boss_Stage2_Back = new Boss_Stage2_Back();
	AddGameObeject(m_Boss_Stage2_Back, eLayerType::BG);

	m_Boss_Stage2_Object = new Boss_Stage2_Object();
	AddGameObeject(m_Boss_Stage2_Object, eLayerType::BossObj);

	Hpb = new BossHP_Bar();
	AddGameObeject(Hpb, eLayerType::UI);

	Exbar* exbar = new Exbar();
	AddGameObeject(exbar, eLayerType::UI);

	Hp_Mp* hp = new Hp_Mp();
	AddGameObeject(hp, eLayerType::UI);

	Menubar* menu = new Menubar();
	AddGameObeject(menu, eLayerType::UI);

	Skillbar* skillbar = new Skillbar();
	AddGameObeject(skillbar, eLayerType::UI);

	Stage2 = RResources::Load<Sound>(L"Stage2", L"..\\Resources\\Sound\\Map_Sound\\boss.wav");

	Ground* ground0 = new Ground();
	AddGameObeject(ground0, eLayerType::Ground);

	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);

	boss = new Boss();
	AddGameObeject(boss, eLayerType::Boss);

	Scene::Initialize();

	ground0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 690.0f));
	ground0->GetComponent<Collider>()->SetSize(Vector2(2000.0f, 30.0f));
	Hpb->GetComponent<Transform>()->SetPos(Vector2(720.0, 40.0f));
}

void Boss_Stage2_Scene::Update()
{
	Hpb->BossHP = boss->GetBossHPCnt();


	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Henesys);
	}

	Scene::Update();


	Camera::SetTarget(mMainChar);

}
void Boss_Stage2_Scene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void Boss_Stage2_Scene::Release()
{
	Scene::Release();
}
void Boss_Stage2_Scene::OnEnter()
{
	Stage2->Play(true);
	mMainChar->GetComponent<Transform>()->SetPos(Vector2(240.0f, 800.0f));
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::BossObj, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Boss, true);

	boss->respawn();

	Camera::SetImgResolution(Vector2(1980.f, 795.f));
	Camera::SetImgResolution(Vector2(1980.f, 700.f));
}
void Boss_Stage2_Scene::OnExit()
{
	Stage2->Stop(true);
}