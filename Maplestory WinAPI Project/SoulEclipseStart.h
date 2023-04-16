#pragma once
#include "GameObject.h"

class Animation;
class Animator;

class SoulEclipseStart : public GameObject
{
public:
	SoulEclipseStart();
	~SoulEclipseStart();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Animator* m_Animator;
	Animator* m_Animator1;
	float mTime;
	int posx;
	int posy;
	float m_Time;

public:
	const void SetPosX(int x)
	{
		posx = x;
	}
	const void SetPosY(int y)
	{
		posy = y;
	}
};

