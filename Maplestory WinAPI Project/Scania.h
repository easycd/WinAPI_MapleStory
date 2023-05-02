#pragma once
#include "GameObject.h"
#include "Image.h"

class Animation;
class Animator;
class Collider;

class Scania : public GameObject
{
public:
	Scania();
	~Scania();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnCollisionEnter(class Collider* other) override;
	virtual void OnCollisionStay(Collider* other) override;

private:
	Animator* m_Animator;
	
};
