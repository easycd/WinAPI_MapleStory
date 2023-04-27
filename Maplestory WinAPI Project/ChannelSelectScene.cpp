#include "ChannelSelectScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "ChannelSelectBG.h"
#include "Time.h"
#include "Transform.h"
#include "Animator.h"

ChannelSelectScene::ChannelSelectScene()
	: mTime(0.0f)
{
}

ChannelSelectScene::~ChannelSelectScene()
{
}

void ChannelSelectScene::Initialize()
{
	BG = new ChannelSelectBG();
	AddGameObeject(BG, eLayerType::BG);
	BG->Initialize();

	Scene::Initialize();
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
}
