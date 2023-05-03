#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Stage2Enter_Ani : public GameObject
{
public:
	Stage2Enter_Ani();
	virtual ~Stage2Enter_Ani();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	float mTime;
	Animator* m_Animator;
};

