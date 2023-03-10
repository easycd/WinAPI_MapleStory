#pragma once
#include "Scene.h"
#include "Image.h"


class MainChar;
class HenesysBack;
class mushroom;
class RedSnail;

	class HenesysScene : public Scene
	{
	public:
		HenesysScene();
		~HenesysScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		HenesysBack* m_henesysBack;
		MainChar* mMainChar;
		mushroom* m_mushroom;
		RedSnail* m_redsnail;
	};

