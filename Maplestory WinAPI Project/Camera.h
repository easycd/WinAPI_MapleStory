#pragma once
#include "MapleEngine.h"

class GameObject;
class Camera
{
public:
	static void Initiailize();
	static void Update();

	static void SetTarget(GameObject* target) { mTarget = target; } // ī�޶� ���� ����
	static const Vector2 CaluatePos(Vector2 pos) { return pos - mDistance; }

private:
	static Vector2 mResolution; // ȭ�� �ػ�
	static Vector2 mLookPosition; //ī�޶� �Ĵٺ��� �ִ� ��ġ 
	static Vector2 mDistance; //�Ÿ�
	static GameObject* mTarget;  // ī�޶��� ������ �� ������Ʈ
};

