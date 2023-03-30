#pragma once
#include "GameObject.h"

class Animator;
class BasicSkill : public GameObject
{
public:
	BasicSkill();
	~BasicSkill();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void RightAttack();

private:
	Animator* m_Animator;
	float mTime;
};

