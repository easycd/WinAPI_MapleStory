#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class CharacterMove : public GameObject
{
public:
	CharacterMove();
	virtual ~CharacterMove();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	float mTime;
	Animator* m_Animator;
};

