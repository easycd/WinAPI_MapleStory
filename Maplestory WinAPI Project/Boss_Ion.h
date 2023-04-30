#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class MainChar;
class Transform;

class Boss_Ion : public GameObject
{
public:
	enum class eBoss_IonState
	{
		Respawn,
		Pattern,
		Death,
		Attack1,
		Attack2,
	};

	Boss_Ion();
	~Boss_Ion();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void Ion_respawn();

private:
	void pattern();
	void idle();
	void death();
	void attack1();
	void attack2();
	void idleCompleteEvent();

private:
	eBoss_IonState m_State;
	Animator* m_Animator;
	Transform* tr;
	MainChar* player;

	Collider* Idle_collider;

	int Direction; //0이면 왼쪽 1이면 오른쪽
	int attack_pattern;

	float m_Time;
	float attack2_Delay;

	bool SetMoveLeft;
	bool SetMoveRight;
};


