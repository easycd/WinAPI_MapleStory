#pragma once
#include "GameObject.h"

class Animator;

class BlackChainSkill : public GameObject
{
public:

	BlackChainSkill();
	~BlackChainSkill();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;


	void Attack();
private:
	void Destroy();
	Animator* m_Animator;
	float m_Time;
	float Check;
};

