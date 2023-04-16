#pragma once
#include "GameObject.h"

class Animator;
class Animation;

class SoulEclipseEffect : public GameObject
{
public:
	SoulEclipseEffect();
	~SoulEclipseEffect();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Animator* m_Animator;
	float m_Time;
};