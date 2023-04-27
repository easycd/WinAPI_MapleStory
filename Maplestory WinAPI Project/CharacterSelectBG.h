#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class CharacterSelectBG : public GameObject
{
public:
	CharacterSelectBG();
	virtual ~CharacterSelectBG();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	float mTime;
	Animator* m_Animator;
};

