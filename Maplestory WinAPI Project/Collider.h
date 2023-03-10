#pragma once
#include "Component.h"

class Collider : public Component
{
public:
	Collider();
	~Collider();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void SetCenter(Vector2 center) { mCenter = center; };
	void SetSize(Vector2 size) { mSize = size; };
	void SetScale(Vector2 scale) { mScale = scale; };

	/*Vector2 SetSize() { return mSize; }
	Vector2 SetCenter() { return mCenter; }
	Vector2 SetScale() { return mScale; }*/

private:
	Vector2 mCenter;
	Vector2 mSize;
	Vector2 mScale;
	Vector2 mPos;
};

