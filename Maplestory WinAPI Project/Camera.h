#pragma once
#include "MapleEngine.h"

class GameObject;
class Camera
{
public:
	Camera();
	~Camera();
	static void Initiailize();
	static void Update();

	static void SetTarget(GameObject* target) { mTarget = target; } // 카메라 기준 지정
	static const Vector2 CaluatePos(Vector2 pos) { return pos - mDistance; }



	static void SetLookRange(Vector2 range) { mLookRange = range; }



	Vector2 GetLookPosition()
	{
		return mLookPosition;
	}

	void SetLookPosition(Vector2 LookPosition)
	{
		mLookPosition = LookPosition;
	}

private:
	static Vector2 mResolution; // 화면 해상도
	static Vector2 mLookPosition; //카메라가 쳐다보고 있는 위치 
	static Vector2 mDistance; //거리
	static GameObject* mTarget;  // 카메라의 기준이 될 오브젝트


	static Vector2 mLookRange;
};

