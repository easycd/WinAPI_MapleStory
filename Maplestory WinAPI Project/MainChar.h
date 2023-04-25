#pragma once
#include "GameObject.h"
#include "Image.h"

class Rigidbody;
class Animator;
class Camera;
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
	Transform* tr;
	Camera* m_Camera;
	Collider* collider2;

	int direction = 0; //0�̸� ���� 1�̸� ������
	bool mGroundCheck;
	int posx;
	int posy;
	bool m_PortalState;



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

