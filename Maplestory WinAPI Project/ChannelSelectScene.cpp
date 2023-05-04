#include "ChannelSelectScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "ChannelSelectBG.h"
#include "Time.h"
#include "Transform.h"
#include "Animator.h"
#include "Sound.h"
#include "RResources.h"
#include "Application.h"
#include "Collider.h"
#include "ServerList.h"
#include "Scania.h"
#include "CollisionManager.h"
#include "WorldChannelSelect.h"

ChannelSelectScene::ChannelSelectScene()
	: mTime(0.0f)
	, Check(false)
	, nextCheck(false)
{
}

ChannelSelectScene::~ChannelSelectScene()
{
}

void ChannelSelectScene::Initialize()
{
	ChennalSd = RResources::Load<Sound>(L"ChennalSound", L"..\\Resources\\Sound\\Map_Sound\\Login.wav");
	worldClick = RResources::Load<Sound>(L"worldClick", L"..\\Resources\\Sound\\UI_Sound\\BtMouseClick.wav");
	NextScene = RResources::Load<Sound>(L"NextScene", L"..\\Resources\\Sound\\UI_Sound\\ScrollUp.wav");

	BG = new ChannelSelectBG();
	AddGameObeject(BG, eLayerType::BG);
	BG->Initialize();


	Sl = new ServerList();
	AddGameObeject(Sl, eLayerType::UI);

	scania = new Scania();
	AddGameObeject(scania, eLayerType::ChannelList);

	Wcs = new WorldChannelSelect();
	AddGameObeject(Wcs, eLayerType::ChannelList);

	Scene::Initialize();

}

void ChannelSelectScene::Update()
{
	mTime += Time::DeltaTime();

	if (Input::GetKeyUp(eKeyCode::MousLeftClick))
	{
		Wcs->open();
		worldClick->Play(false);
		Check = true;
	}

	if (Input::GetKeyUp(eKeyCode::MousLeftClick) && nextCheck)
	{
		SceneManager::LoadScene(eSceneType::CharSelect);
	}

	if (Check)
		nextCheck = true;
	Scene::Update();
}

void ChannelSelectScene::Render(HDC hdc)
{

	Scene::Render(hdc);
}

void ChannelSelectScene::Release()
{
	Scene::Initialize();
}

void ChannelSelectScene::OnEnter()
{
	ChennalSd->Play(true);
}

void ChannelSelectScene::OnExit()
{
	ChennalSd->Stop(true);
	NextScene->Play(false);
}
