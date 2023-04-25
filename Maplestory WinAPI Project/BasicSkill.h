#pragma once
#include "GameObject.h"

class Animator;
class Animation;
class Transform;

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
	void LeftAttack();

private:
	Animator* m_Animator;
	Transform* pos;
	float mTime;
	int posx;
	int posy;

public:
	const void SetPosX(int x)
	{
		posx = x;
	}
	const void SetPosY(int y)
	{
		posy = y;
	}
};

