#pragma once
#include "Scene.h"

	class MainChar;

	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Destroy();
		static void Release();

		static void LoadScene(eSceneType type);
		static Scene* GetActiveScene() { return mActiveScene; }
		static MainChar* GetPlayer();

	private:
		static std::vector<Scene*> mScenes;
		static Scene* mActiveScene;
	};


