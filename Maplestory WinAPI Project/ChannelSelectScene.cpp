#include "ChannelSelectScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "ChannelSelectBG.h"
#include "Time.h"
#include "Transform.h"
#include "Animator.h"
#include "Sound.h"
#include "RResources.h"

ChannelSelectScene::ChannelSelectScene()
	: mTime(0.0f)
	, Check(false)
{
}

ChannelSelectScene::~ChannelSelectScene()
{
}

void ChannelSelectScene::Initialize()
{
	Scene::Initialize();
	ChennalSd = RResources::Load<Sound>(L"ChennalSound", L"..\\Resources\\Sound\\Map_Sound\\Login.wav");
	ChennalSd->Play(true);
	BG = new ChannelSelectBG();
	AddGameObeject(BG, eLayerType::BG);
	BG->Initialize();

}

void ChannelSelectScene::Update()
{
	if (Input::GetKeyDown(eKeyCode::N))
	{
		SceneManager::LoadScene(eSceneType::CharSelect);
	}
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
}

void ChannelSelectScene::OnExit()
{
	ChennalSd->Stop(false);
}
