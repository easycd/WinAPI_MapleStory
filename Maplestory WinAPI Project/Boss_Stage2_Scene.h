#pragma once
#include "Scene.h"
#include "Image.h"


class MainChar;
class Boss_Stage2_Back;

class Boss_Stage2_Scene : public Scene
{
public:
	Boss_Stage2_Scene();
	~Boss_Stage2_Scene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	MainChar* mMainChar;
	Boss_Stage2_Back* m_Boss_Stage2_Back;
};

