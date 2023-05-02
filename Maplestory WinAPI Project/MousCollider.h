#pragma once
#include "GameObject.h"

class Collider;

class MousCollider : public GameObject
{
public:
	MousCollider();
	virtual ~MousCollider();

	virtual void Initialize();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual void OnCollisionEnter(class Collider* other);
	virtual void OnCollisionStay(class Collider* other);
	virtual void OnCollisionExit(class Collider* other);

private:
};

