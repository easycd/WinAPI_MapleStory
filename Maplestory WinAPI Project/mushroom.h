#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class MainChar;
class mushroom : public GameObject 
{
public:
	enum class emushroomState
	{
		Move,
		Death,
		Idle,
	};

	mushroom();
	~mushroom();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnCollisionEnter(class Collider* other) override;

private:
	void move();
	void idle();
	void death();

private:
	emushroomState m_State;
	Animator* m_Animator;
	Rigidbody* mRigidbody;
	MainChar* Ch;
	Vector2 ChPos;
	int Pattern;
	float m_Time;
	float SetPosX;
	int Direction; // ���� ����, ���� = 0, ������ = 1
	int CompleteCnt;
	bool Animation_Check;
	bool Ground;
	bool AnimationLoop;


	bool Check;
	bool Check2;
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


