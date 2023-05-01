#include "CharacterSelectScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "CharacterSelectBG.h"
#include "CharacterMove.h"
#include "Time.h"
#include "Transform.h"
#include "Animator.h"
#include "ChannelName.h"
#include "ChannelSelectScene.h"
#include "Sound.h"
#include "RResources.h"

CharacterSelectScene::CharacterSelectScene()
{
}

CharacterSelectScene::~CharacterSelectScene()
{
}

void CharacterSelectScene::Initialize()
{
	BG = new CharacterSelectBG();
	AddGameObeject(BG, eLayerType::BG);

	Character = new CharacterMove();
	AddGameObeject(Character, eLayerType::Player);

	ChName = new ChannelName();
	AddGameObeject(ChName, eLayerType::Player);

	Scene::Initialize();
}

void CharacterSelectScene::Update()
{
	if (Input::GetKeyDown(eKeyCode::N))
	{
		SceneManager::LoadScene(eSceneType::Henesys);
	}
	Scene::Update();
}

void CharacterSelectScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void CharacterSelectScene::Release()
{
	Scene::Release();
}

void CharacterSelectScene::OnEnter()
{
}

void CharacterSelectScene::OnExit()
{
	chs->SetSound(true);
}
