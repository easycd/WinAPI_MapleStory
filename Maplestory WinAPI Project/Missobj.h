#pragma once
#include "GameObject.h"
#include "Image.h"

class Animation;
class Animator;
class Collider;
class Transform;
class MainChar;

class Missobj : public GameObject
{
public:
	Missobj();
	~Missobj();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnCollisionEnter(class Collider* other) override;
	virtual void OnCollisionStay(Collider* other) override;

	void play();
	void Destroy();

private:
	Animator* m_Animator;
	Transform* tr;
	MainChar* player;
	float div;
};