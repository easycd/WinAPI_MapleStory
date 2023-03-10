#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Boss_Yaldabaoth : public GameObject
{
public:
	enum class eBoss_YaldabaothState
	{
		Move,
		Death,
		Idle,
	};

	Boss_Yaldabaoth();
	~Boss_Yaldabaoth();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	void move();
	void idle();
	void dead();

private:
	eBoss_YaldabaothState m_State;
	Animator* m_Animator;
};


