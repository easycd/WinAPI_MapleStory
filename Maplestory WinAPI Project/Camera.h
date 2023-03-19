#pragma once
#include "MapleEngine.h"

class GameObject;
class Camera
{
public:
	static void Initiailize();
	static void Update();

	static void SetTarget(GameObject* target) { mTarget = target; }
	static const Vector2 CaluatePos(Vector2 pos) { return pos - mDistance; }

private:
	static Vector2 mResolution;
	static Vector2 mLookPosition;
	static Vector2 mDistance;
	static GameObject* mTarget;
};

