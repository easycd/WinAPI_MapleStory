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
		Pattern,
		Move,
		Idle,
		FullLeft_Skill1,
		FullCenter_Skill2,
		FullRight_Skill3,
		Chain_Skill4,
	};

	Boss();
	~Boss();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void respawn();

private:
	void pattern();
	void move();
	void idle();
	void dead();
	void FullLeft_Skill1();
	void FullCenter_Skill2();
	void FullRight_Skill3();
	void Chain_Skill4();


private:
	eBoss_State m_State;
	Animator* m_Animator;
	float m_Time;
	int attack_pattern;
};


