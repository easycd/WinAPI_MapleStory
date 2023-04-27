#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Animation;

class SoulEclipseBackGround : public GameObject
{
public:
	SoulEclipseBackGround();
	~SoulEclipseBackGround();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;


private:
	Animator* m_Animator;

	float m_Time;
};

