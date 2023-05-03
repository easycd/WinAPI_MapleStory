#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class MainChar;
class BsHit;

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
	virtual void OnCollisionStay(Collider* other) override;

	void idle();
private:
	void move();
	void death();
	void Delete();

private:
	emushroomState m_State;
	Animator* m_Animator;
	Rigidbody* mRigidbody;
	MainChar* Ch;
	Vector2 ChPos;
	Vector2 Speed;
	Transform* tr;

	BsHit* bshit;

	float m_Time;
	float SetPosX;

	int Direction; // 방향 변수, 왼쪽 = 0, 오른쪽 = 1
	int CompleteCnt;
	int Hp;

	bool Animation_Check;
	bool Ground;
	bool AnimationLoop;


	bool Check;
	bool Check2;
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


