#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Boss_Ion : public GameObject
{
public:
	enum class eBoss_IonState
	{
		Respawn,
		Move,
		Death,
		Idle,
		Attack1,
		Attack2,
	};

	Boss_Ion();
	~Boss_Ion();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void respawn();
	void move();
	void idle();
	void dead();
	void attack1();
	void attack2();


private:
	eBoss_IonState m_State;
	Animator* m_Animator;
	int direction = 0; //0이면 왼쪽 1이면 오른쪽
};


