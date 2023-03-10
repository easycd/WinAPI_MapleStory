#pragma once
#include "Scene.h"
#include "Image.h"

class MainChar;
class SomyeolBack;
class happy;

	class SomyeolScene : public Scene
	{
	public:
		SomyeolScene();
		~SomyeolScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		SomyeolBack* m_somyeolBack;
		MainChar* mMainChar;
		happy* m_happy;
	};

