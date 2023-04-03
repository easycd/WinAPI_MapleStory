#pragma once
#include "Scene.h"
#include "Image.h"

class MainChar;
class Boss_Enter_Back;

class Boss_Enter_Scene : public Scene
{
public:
	Boss_Enter_Scene();
	~Boss_Enter_Scene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	MainChar* mMainChar;
	Boss_Enter_Back* boss_enter_back;
};

