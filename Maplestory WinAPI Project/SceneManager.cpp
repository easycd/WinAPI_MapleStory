#include "SceneManager.h"
#include "CollisionManager.h"
#include "Arcana.h"
#include "HenesysScene.h"
#include "SomyeolScene.h"
#include "LoginScene.h"
#include "WizetScene.h"
#include "Boss_Stage1_Scene.h"
#include "Boss_Stage2_Scene.h"
#include "Boss_Enter_Scene.h"

std::vector<Scene*> SceneManager::mScenes = {};
Scene* SceneManager::mActiveScene = nullptr;

void SceneManager::Initialize()
{
	mScenes.resize((UINT)eSceneType::End);

	mScenes[(UINT)eSceneType::Start] = new WizetScene();

	mScenes[(UINT)eSceneType::Login] = new LoginScene(); // ·Î±×ÀÎ ¾À

	mScenes[(UINT)eSceneType::Henesys] = new HenesysScene(); //Çì³×½Ã½º ¾À

	mScenes[(UINT)eSceneType::Arcana] = new Arcana(); // ¾Æ¸£Ä«³ª ¾À

	mScenes[(UINT)eSceneType::Somyeol] = new SomyeolScene(); //¼Ò¸ê¿©·Î ¾À

	mScenes[(UINT)eSceneType::Boss_Enter] = new Boss_Enter_Scene(); //º¸½ºÀÔ±¸ ¾À

	mScenes[(UINT)eSceneType::Boss_Stage1] = new Boss_Stage1_Scene(); //º¸½º½ºÅ×ÀÌÁö1 ¾À

	mScenes[(UINT)eSceneType::Boss_Stage2] = new Boss_Stage2_Scene(); //º¸½º½ºÅ×ÀÌÁö2 ¾À

	mActiveScene = mScenes[(UINT)eSceneType::Henesys]; //·Î±×ÀÎ ¾À ½ÃÀÛ

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
	// ÇöÀç¾À
	mActiveScene->OnExit();

	CollisionManager::Clear();

	//´ÙÀ½¾À
	mActiveScene = mScenes[(UINT)type];
	mActiveScene->OnEnter();
}