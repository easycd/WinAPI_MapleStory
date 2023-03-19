#pragma once
#include "GameObject.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Transform.h"

	//������Ʈ �����ϰ� �ҷ���
	template <typename T>
	static inline T* Instantiate(eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObeject(gameObj, type);
		gameObj->Initialize();
		return gameObj;
	}

	//������Ʈ ��ġ �����ϰ� ����
	template <typename T>
	static inline T* Instantiate(Vector2 pos, eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObeject(gameObj, type);
		gameObj->Initialize();
		gameObj->GameObject::GetComponent<Transform>()->SetPos(pos);
		return gameObj;
	}


	static void Destory(GameObject* obj)
	{
		obj->SetState(GameObject::eState::Death);
	}
