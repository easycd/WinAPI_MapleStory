#pragma once
#include "Scene.h"
#include "Image.h"

class Sound;
class MainChar;
class LastMapScene : public Scene
{
public:
	LastMapScene();
	virtual ~LastMapScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;


private:
	Sound* mapSound;
	MainChar* mMainChar;
};
