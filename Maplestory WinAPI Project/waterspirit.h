#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class waterspirit : public GameObject
{
public:
	enum class ewaterspiritState
	{
		Move,
		Shoot,
		Death,
		Idle,
	};

	waterspirit();
	~waterspirit();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;


	virtual void OnCollisionEnter(class Collider* other) override;
	virtual void OnCollisionStay(Collider* other) override;

private:
	void move();
	void idle();
	void dead();
	void Delete();

private:
	ewaterspiritState m_State;
	Animator* m_Animator;
	float m_Time;
	float SetPosX;

	int Direction; // 방향 변수, 왼쪽 = 0, 오른쪽 = 1
	int Hp;

	bool Animation_Check;
	bool Ground;
	bool die_Check;

public:
	void SetInitialize_Direction(int dr)
	{
		Direction = dr;
	}
	void SetGround(bool set)
	{
		Ground = set;
	}
};

