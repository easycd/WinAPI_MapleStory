#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class Wizet : public GameObject
{
public:
	Wizet();
	virtual ~Wizet();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Animator* m_Animator;
	float mTime;
};
