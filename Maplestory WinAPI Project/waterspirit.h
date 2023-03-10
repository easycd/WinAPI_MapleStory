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

private:
	void move();
	void idle();

private:
	ewaterspiritState m_State;
	Animator* m_Animator;
};

