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
		Down,
		Idle,
		Death,
		DownAttack,
		Attack,
		CosmosSkill,

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
	void down();
	void downattack();
	void basic_attack();
	void cosmosSkill();

	void idleCompleteEvent();

	void SetPos(Vector2 pos) { mPos = pos; }
	Vector2 GetPos() { return mPos; }
	

private:
	eMainCharState m_State;
	Animator* m_Animator;
	Animator* attack;
	Rigidbody* mRigidbody;
	Vector2 mPos;
	int direction = 0; //0�̸� ���� 1�̸� ������
	bool mGroundCheck;

	Camera* m_Camera;
	//HenesysBack* m_HenesysBack;
};

