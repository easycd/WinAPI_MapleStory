#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class BossIon_Attack1 : public GameObject
{
public:
	enum class eBossIon_Attack1State
	{
		Respawn,
		Move,
		Death,
		Idle,
		Attack1,
		Attack2,
	};

	BossIon_Attack1();
	~BossIon_Attack1();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
	void attack1();

private:




private:
	eBossIon_Attack1State m_State;
	Animator* m_Animator;
	int direction = 0; //0이면 왼쪽 1이면 오른쪽
};