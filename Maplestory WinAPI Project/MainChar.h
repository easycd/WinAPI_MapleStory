#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class MainChar : public GameObject 
{
public:
	enum class eMainCharState
	{
		Move,
		Shoot,
		Death,
		Idle,
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

private:
	eMainCharState m_State;
	Animator* m_Animator;
};

