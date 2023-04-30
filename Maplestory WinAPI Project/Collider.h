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

	virtual void OnCollisionEnter(Collider* other);
	virtual void OnCollisionStay(Collider* other);
	virtual void OnCollisionExit(Collider* other);

	void SetCenter(Vector2 center) { mCenter = center; };
	void SetSize(Vector2 size) { mSize = size; };
	Vector2 GetPos() { return mPos; }
	Vector2 GetSize() { return mSize; }
	Vector2 GetCenter() { return mCenter; }

private:
	static UINT ColliderNumber;
	UINT mCollisionCount;
	UINT mID;
	Vector2 mCenter;
	Vector2 mSize;
	Vector2 mScale;
	Vector2 mPos;
	bool m_IsCameraMove;
	int m_nullcameraX;
	int m_nullcameraY;

public:
	void SetIsColliderMove(bool IsColliderMove) //카메라 설정
	{
		m_IsCameraMove = IsColliderMove;
	}

	void SetNullCameraPosX(int x)
	{
		m_nullcameraX = x;
	}
	void SetNullCameraPosY(int y)
	{
		m_nullcameraY = y;
	}
};

