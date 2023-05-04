#pragma once
#include "GameObject.h"
#include "Image.h"

class Animation;
class Animator;
class Collider;
class Boss;
class Boss_Stage2_Scene;

class BossHP_Bar : public GameObject
{
public:
	BossHP_Bar();
	~BossHP_Bar();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnCollisionEnter(class Collider* other) override;
	virtual void OnCollisionStay(Collider* other) override;

	
	int BossHP;

private:
	Animator* m_Animator;
	Transform* tr;
	Boss_Stage2_Scene* HPcnt;

	int test;
};