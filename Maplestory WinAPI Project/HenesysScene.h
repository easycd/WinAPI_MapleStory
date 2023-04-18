#pragma once
#include "Scene.h"
#include "Image.h"

class MainChar;
class HenesysBack;
class HenesysObject;
class mushroom;
class RedSnail;
class Portal;
class Ground;
class Camera;

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
		HenesysObject* m_henesysobject;
		MainChar* mMainChar;
		RedSnail* m_redsnail;
		Camera* Camera;
	};

