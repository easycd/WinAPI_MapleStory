#include "LastMapScene.h"
#include "LastMAp.h"
#include "Input.h"
#include "SceneManager.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "Ground.h"
#include "Transform.h"
#include "Portal.h"
#include "Sound.h"
#include "RResources.h"
#include "Time.h"

#include "Exbar.h"
#include "Hp_Mp.h"
#include "Menubar.h"
#include "Skillbar.h"
LastMapScene::LastMapScene()
{
}

LastMapScene::~LastMapScene()
{
}

void LastMapScene::Initialize()
{
	mapSound = RResources::Load<Sound>(L"mapSound", L"..\\Resources\\Sound\\Map_Sound\\LostSpace.wav");
	
	LastMAp* map = new LastMAp();
	AddGameObeject(map, eLayerType::BG);

	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);

	Exbar* exbar = new Exbar();
	AddGameObeject(exbar, eLayerType::UI);

	Hp_Mp* hp = new Hp_Mp();
	AddGameObeject(hp, eLayerType::UI);

	Menubar* menu = new Menubar();
	AddGameObeject(menu, eLayerType::UI);

	Skillbar* skillbar = new Skillbar();
	AddGameObeject(skillbar, eLayerType::UI);


	Ground* ground0 = new Ground();
	AddGameObeject(ground0, eLayerType::Ground);

	Scene::Initialize();

	ground0->GetComponent<Transform>()->SetPos(Vector2(100.0f, 750.0f));
	ground0->GetComponent<Transform>()->SetScale(Vector2(8000.0f, 30.0f));
}

void LastMapScene::Update()
{
	Scene::Update();
	Camera::SetTarget(mMainChar);
}

void LastMapScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void LastMapScene::Release()
{
	Scene::Release();
}

void LastMapScene::OnEnter()
{
	mapSound->Play(true);
	mMainChar->GetComponent<Transform>()->SetPos(Vector2(1100.0f, 800.0f));
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);

	Camera::SetImgResolution(Vector2(2200.f, 1025.f));
}

void LastMapScene::OnExit()
{
}
