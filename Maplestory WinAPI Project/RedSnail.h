#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class RedSnail : public GameObject 
{
public:
	enum class eRedSnailState
	{
		Move,
		Shoot,
		Death,
		Idle,
	};

	RedSnail();
	~RedSnail();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void move();
	void idle();


private:
	eRedSnailState m_State;
	Animator* m_Animator;
};

