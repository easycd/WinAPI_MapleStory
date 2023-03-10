#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Boss_Ion : public GameObject
{
public:
	enum class eBoss_IonState
	{
		Move,
		Death,
		Idle,
	};

	Boss_Ion();
	~Boss_Ion();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void move();
	void idle();
	void dead();

private:
	eBoss_IonState m_State;
	Animator* m_Animator;
};


