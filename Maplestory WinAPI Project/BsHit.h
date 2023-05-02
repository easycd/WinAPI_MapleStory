#pragma once
#include "GameObject.h"
#include "Image.h"

class Animator;
class MainChar;

class BsHit : public GameObject
{
public:
	BsHit();
	~BsHit();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void Hit();
private:
	void Distroy();

	Animator* m_Animator;
	Transform* tr;
	MainChar* player;
};
