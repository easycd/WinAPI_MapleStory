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
	StartSound = RResources::Load<Sound>(L"StartSound", L"..\\Resources\\Sound\\UI_Sound\\CharSelect.wav");
	EndSound = RResources::Load<Sound>(L"EndSound", L"..\\Resources\\Sound\\UI_Sound\\MagnifierSuccess.wav");
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
	if (Input::GetKeyUp(eKeyCode::MousLeftClick))
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
	StartSound->Play(false);
}

void CharacterSelectScene::OnExit()
{
	EndSound->Play(false);
}
