#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Boss : public GameObject
{
public:
	enum class eBoss_State
	{
		Respawn,
		Move,
		Death,
		Idle,
		Attack1,
		Attack2,
	};

	Boss();
	~Boss();

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
	Animator* m_Animator;
	int direction = 0; //0이면 왼쪽 1이면 오른쪽
};


