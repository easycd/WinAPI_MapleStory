#include "SceneManager.h"
#include "Arcana.h"
#include "HenesysScene.h"
#include "SomyeolScene.h"
#include "LoginScene.h"
#include "Boss_Stage1_Scene.h"
#include "Boss_Stage2_Scene.h"

std::vector<Scene*> SceneManager::mScenes = {};
Scene* SceneManager::mActiveScene = nullptr;

void SceneManager::Initialize()
{
	mScenes.resize((UINT)eSceneType::End);

	mScenes[(UINT)eSceneType::Login] = new LoginScene(); // ?α??? ??

	mScenes[(UINT)eSceneType::Henesys] = new HenesysScene(); //???׽ý? ??

	mScenes[(UINT)eSceneType::Arcana] = new Arcana(); // ?Ƹ?ī?? ??

	mScenes[(UINT)eSceneType::Somyeol] = new SomyeolScene(); //?Ҹ꿩?? ??

	mScenes[(UINT)eSceneType::Boss_Stage1] = new Boss_Stage1_Scene(); //????????????1 ??

	mScenes[(UINT)eSceneType::Boss_Stage2] = new Boss_Stage2_Scene(); //????????????2 ??

	mActiveScene = mScenes[(UINT)eSceneType::Login];

	for (Scene* scene : mScenes)
	{
		if (scene == nullptr)
			continue;

		scene->Initialize();
	}
}

void SceneManager::Update()
{
	mActiveScene->Update();
}

void SceneManager::Render(HDC hdc)
{
	mActiveScene->Render(hdc);
}

void SceneManager::Release()
{
	for (Scene* scene : mScenes)
	{
		if (scene == nullptr)
			continue;

		delete scene;
		scene = nullptr;
	}
}

void SceneManager::LoadScene(eSceneType type)
{
	// ??????
	mActiveScene->OnExit();

	//??????
	mActiveScene = mScenes[(UINT)type];
	mActiveScene->OnEnter();
}