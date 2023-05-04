#include "Stage1Enter_AniScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Time.h"
#include "Transform.h"
#include "Sound.h"
#include "RResources.h"
#include "Stage1Enter_Ani.h"

Stage1Enter_AniScene::Stage1Enter_AniScene()
	: mTime(0.0f)
{
}

Stage1Enter_AniScene::~Stage1Enter_AniScene()
{
}

void Stage1Enter_AniScene::Initialize()
{
	S1Enter = RResources::Load<Sound>(L"S1Enter", L"..\\Resources\\Sound\\Boss_Sound\\Phase1.wav");
	ani = new Stage1Enter_Ani();
	AddGameObeject(ani, eLayerType::BG);

	Scene::Initialize();
}

void Stage1Enter_AniScene::Update()
{
	mTime += Time::DeltaTime();

	//if (mTime > 7.0f)
	if (mTime > 7.0f)
	{
		SceneManager::LoadScene(eSceneType::Boss_Stage1);
	}
	Scene::Update();
}

void Stage1Enter_AniScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void Stage1Enter_AniScene::Release()
{
	Scene::Release();
}

void Stage1Enter_AniScene::OnEnter()
{
	S1Enter->Play(false);
}

void Stage1Enter_AniScene::OnExit()
{
}
