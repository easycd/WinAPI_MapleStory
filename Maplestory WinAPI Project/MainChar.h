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
		SoulEclipse,

	};

	MainChar();
	~MainChar();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnCollisionEnter(class Collider* other) override;
	virtual void OnCollisionExit(class Collider* other) override;

private:
	void move();
	void idle();
	void jump();
	void down();
	void downattack();
	void basic_attack();
	void cosmosSkill();
	void souleclipseSkill();

	void idleCompleteEvent();

	void SetPos(Vector2 pos) { mPos = pos; }
	Vector2 GetPos() { return mPos; }
	

private:
	eMainCharState m_State;
	Animator* m_Animator;
	Animator* attack;
	Rigidbody* mRigidbody;
	Vector2 mPos;
	int direction = 0; //0이면 왼쪽 1이면 오른쪽
	bool mGroundCheck;
	Camera* m_Camera;
	//HenesysBack* m_HenesysBack;
	int posx;
	int posy;
	bool m_PortalState;


	Collider* collider2;

public:
	void SetCharPosX(int x)
	{
		posx = x;
	}
	void SetCharPosY(int y)
	{
		posx = y;
	}
	int GetCharPosX()
	{
		return posx;
	}
	int GetCharPosY()
	{
		return posy;
	}
	bool GetPotalState()
	{
		return m_PortalState;
	}
	Collider GetCollider()
	{
		return *collider2;
	}
};

