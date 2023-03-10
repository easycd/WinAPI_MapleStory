#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
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

private:
	void move();
	void idle();
	void dead();

private:
	emushroomState m_State;
	Animator* m_Animator;
};


