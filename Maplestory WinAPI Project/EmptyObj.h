#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class EmptyObj : public GameObject
{
public:
	EmptyObj();
	virtual ~EmptyObj();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Animator* m_Animator;
	float mTime;
};
