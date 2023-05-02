#include "ChannelSelectScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "ChannelSelectBG.h"
#include "Time.h"
#include "Transform.h"
#include "Animator.h"
#include "Sound.h"
#include "RResources.h"
#include "MousCollider.h"
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

	//Mc = new MousCollider();
	//AddGameObeject(Mc, eLayerType::Mous);

	Sl = new ServerList();
	AddGameObeject(Sl, eLayerType::UI);

	scania = new Scania();
	AddGameObeject(scania, eLayerType::ChannelList);

	Wcs = new WorldChannelSelect();
	AddGameObeject(Wcs, eLayerType::ChannelList);

	Scene::Initialize();

	//Mc->GetComponent<Transform>()->SetPos(Vector2(-1000.f, 500.f));
	//Mc->GetComponent<Collider>()->SetSize(Vector2(25.0f, 25.0f));
}

void ChannelSelectScene::Update()
{
	//if (GetFocus())
	//{
	//	mousePos = {};
	//	GetCursorPos(&mousePos);
	//	McPos.x = mousePos.x;
	//	McPos.y = mousePos.y;
	//	Mc->GetComponent<Transform>()->SetPos(Vector2(McPos.x - 1500.0f, McPos.y - 200.0f));
	//}

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
	//CollisionManager::SetLayer(eLayerType::ChannelList, eLayerType::Mous, true);
	ChennalSd->Play(true);
}

void ChannelSelectScene::OnExit()
{
	ChennalSd->Stop(true);
	NextScene->Play(false);
}
