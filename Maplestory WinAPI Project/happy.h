#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class happy : public GameObject
{
public:
	enum class ehappyState
	{
		Move,
		Death,
		Idle,
	};

	happy();
	~happy();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void move();
	void idle();
	void dead();

private:
	ehappyState m_State;
	Animator* m_Animator;
};


