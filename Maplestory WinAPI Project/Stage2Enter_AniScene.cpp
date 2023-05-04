#include "Stage2Enter_AniScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Time.h"
#include "Transform.h"
#include "Sound.h"
#include "RResources.h"
#include "Stage2Enter_Ani.h"

Stage2Enter_AniScene::Stage2Enter_AniScene()
	: mTime(0.0f)
{
}

Stage2Enter_AniScene::~Stage2Enter_AniScene()
{
}

void Stage2Enter_AniScene::Initialize()
{
	S2Enter = RResources::Load<Sound>(L"S2Enter", L"..\\Resources\\Sound\\Boss_Sound\\Phase2.wav");
	ani = new Stage2Enter_Ani();
	AddGameObeject(ani, eLayerType::BG);

	Scene::Initialize();
}

void Stage2Enter_AniScene::Update()
{
	mTime += Time::DeltaTime();

	if (mTime > 1.0f)
	{
		SceneManager::LoadScene(eSceneType::Boss_Stage2);
	}
	Scene::Update();
}

void Stage2Enter_AniScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void Stage2Enter_AniScene::Release()
{
	Scene::Release();
}

void Stage2Enter_AniScene::OnEnter()
{
	S2Enter->Play(false);
}

void Stage2Enter_AniScene::OnExit()
{
}
