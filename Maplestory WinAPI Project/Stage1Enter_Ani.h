#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Stage1Enter_Ani : public GameObject
{
public:
	Stage1Enter_Ani();
	virtual ~Stage1Enter_Ani();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	float mTime;
	Animator* m_Animator;
};

