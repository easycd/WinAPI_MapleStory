#pragma once
#include "GameObject.h"

class MainChar;
class MainChar_GroundCollider : public GameObject
{
public:

	MainChar_GroundCollider();
	~MainChar_GroundCollider();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;


private:
	Vector2 mPos;
	MainChar* player;
	Transform* Pos;
	Scene*	mScene;
};