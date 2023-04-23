#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class CircleObj;
class LeftFullSkill;
class CenterFullSkill;
class RightFullSkill;
class BlackChainSkill;

class Boss : public GameObject
{
public:
	enum class eBoss_State
	{
		Respawn,
		Pattern,
		Idle,
		FullLeft_Skill1,
		FullCenter_Skill2,
		FullRight_Skill3,
		Chain_Skill4,
		Obj_Circle
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
	void idle();
	void dead();
	void FullLeft_Skill1();
	void FullCenter_Skill2();
	void FullRight_Skill3();
	void Chain_Skill4();
	void Test();

	void Skill1_Obj();
	void Skill2_Obj();
	void Skill3_Obj();
	void Obj_Circle();


private:
	eBoss_State m_State;
	Animator* m_Animator;
	int attack_pattern;
	int cnt;

	float m_Time;
	float LoopTime;
	float FallTime;
	float T_Skill1;
	float TestTime;

	bool Skill1Loop;
	bool Skill2Loop;
	bool Skill3Loop;
	bool Skill4Loop;
	bool m_Test;

	LeftFullSkill* Skill1;
	CenterFullSkill* Skill2;
	RightFullSkill* Skill3;

	BlackChainSkill* BS0;
	BlackChainSkill* BS1;
	BlackChainSkill* BS2;
	BlackChainSkill* BS3;
	BlackChainSkill* BS4;
	BlackChainSkill* BS5;

	CircleObj* circleobj0;
	CircleObj* circleobj1;
	CircleObj* circleobj2;
	CircleObj* circleobj3;
	CircleObj* circleobj4;
	CircleObj* circleobj5;
	CircleObj* circleobj6;
	CircleObj* circleobj7;
};


