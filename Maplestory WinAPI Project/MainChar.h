#pragma once
#include "GameObject.h"
#include "Image.h"

class Rigidbody;
class Animator;
class Camera;
class Sound;

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
		SolunaDivide,

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
	void solunadivide();

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

	Sound* S_Jump;
	Sound* S_BasicSkill;
	Sound* S_Blazing;
	Sound* S_Cosmos;
	Sound* S_Die;
	Sound* S_SolunaDivide;

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

