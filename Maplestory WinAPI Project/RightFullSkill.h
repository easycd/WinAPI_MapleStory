#pragma once
#include "GameObject.h"

class Animator;

class RightFullSkill : public GameObject
{
public:

	RightFullSkill();
	~RightFullSkill();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void P1_Start();

private:
	void P1_Loop();
	void P2_Start();
	void P2_Loop();
	void End();
	void Destroy();
	Animator* m_Animator;
	float m_Time;
};

