
#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Portal : public GameObject
{
public:
	Portal();
	~Portal();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Animator* m_Animator;
};


