#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class MainChar;
class Transform;

class Boss_Yaldabaoth : public GameObject
{
public:
	enum class eBoss_YaldabaothState
	{
		Respawn,
		Pattern,
		Death,
		Attack1,
		Attack2,
	};

	Boss_Yaldabaoth();
	~Boss_Yaldabaoth();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnCollisionEnter(class Collider* other) override;
	virtual void OnCollisionStay(Collider* other) override;

	void Yaldabaoth_respawn();

private:
	void pattern();
	void idle();
	void death();
	void attack1();
	void attack2();
	void Destroy();

private:
	eBoss_YaldabaothState m_State;
	Animator* m_Animator;
	Transform* tr;
	MainChar* player;

	Collider* Idle_collider;

	int Direction; //0이면 왼쪽 1이면 오른쪽
	int attack_pattern;
	int Hp;

	float m_Time;
	float attack2_Delay;

	bool SetMoveLeft;
	bool SetMoveRight;
	bool die_Check;
};

