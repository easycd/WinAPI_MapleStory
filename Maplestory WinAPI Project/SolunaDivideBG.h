#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Animation;

class SolunaDivideBG : public GameObject
{
public:
	SolunaDivideBG();
	~SolunaDivideBG();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;


private:
	Animator* m_Animator;

	float m_Time;
};

