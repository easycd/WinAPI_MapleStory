#pragma once
#include "Scene.h"
#include "Image.h"


class MainChar;
class ArcanaBack;
class ArcanaObject;
class waterspirit;

	class Arcana : public Scene
	{
	public:
		Arcana();
		~Arcana();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		MainChar* m_mainchar;
		ArcanaBack* m_arcanaback;
		ArcanaObject* m_arcanaobject;
		waterspirit* m_waterspirit;
	};

