#pragma once
#include "GameObject.h"
#include "Image.h"

class Rigidbody;
class Animator;
class MainChar : public GameObject 
{
public:
	enum class eMainCharState
	{
		Move,
		Jump,
		Attack,
		Death,
		Idle,
	};

	MainChar();
	~MainChar();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void move();
	void idle();
	void jump();
	void basic_attack();

	void idleCompleteEvent();

private:
	eMainCharState m_State;
	Animator* m_Animator;
	Animator* attack;
	Rigidbody* mRigidbody;
	int direction = 0; //0이면 왼쪽 1이면 오른쪽
};

