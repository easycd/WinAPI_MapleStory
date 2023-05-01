#include "SceneManager.h"
#include "CollisionManager.h"
#include "Arcana.h"
#include "HenesysScene.h"
#include "SomyeolScene.h"
#include "WizetScene.h"
#include "emptyScene.h"
#include "ChannelSelectScene.h"
#include "CharacterSelectScene.h"
#include "Boss_Stage1_Scene.h"
#include "Boss_Stage2_Scene.h"
#include "Boss_Enter_Scene.h"

std::vector<Scene*> SceneManager::mScenes = {};
Scene* SceneManager::mActiveScene = nullptr;

void SceneManager::Initialize()
{
	mScenes.resize((UINT)eSceneType::End);

	mScenes[(UINT)eSceneType::Loding] = new emptyScene();
	mScenes[(UINT)eSceneType::Start] = new WizetScene();
	mScenes[(UINT)eSceneType::ChannelSelect] = new ChannelSelectScene(); //ä�� ���� ��
	mScenes[(UINT)eSceneType::CharSelect] = new CharacterSelectScene(); //ĳ���� ���� ��
	mScenes[(UINT)eSceneType::Henesys] = new HenesysScene(); //��׽ý� ��
	mScenes[(UINT)eSceneType::Arcana] = new Arcana(); // �Ƹ�ī�� ��
	mScenes[(UINT)eSceneType::Somyeol] = new SomyeolScene(); //�Ҹ꿩�� ��
	mScenes[(UINT)eSceneType::Boss_Enter] = new Boss_Enter_Scene(); //�����Ա� ��
	mScenes[(UINT)eSceneType::Boss_Stage1] = new Boss_Stage1_Scene(); //������������1 ��
	mScenes[(UINT)eSceneType::Boss_Stage2] = new Boss_Stage2_Scene(); //������������2 ��

	mActiveScene = mScenes[(UINT)eSceneType::Start]; //�� ����

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

void SceneManager::Destroy()
{
	mActiveScene->Destroy();
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
	// �����
	mActiveScene->OnExit();

	CollisionManager::Clear();

	//������
	mActiveScene = mScenes[(UINT)type];
	mActiveScene->OnEnter();
}


MainChar* SceneManager::GetPlayer()
{
	return mActiveScene->GetPlayer();
}
