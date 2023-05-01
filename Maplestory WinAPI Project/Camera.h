#pragma once
#include "MapleEngine.h"

class GameObject;
class Camera
{
public:
	Camera();
	~Camera();
	enum class eCameraEffectType
	{
		None,
		FadeIn,
		FadeOut,
		//Shake,
		End,
	};

	static void Initiailize();
	static void Update();
	static void Render(HDC hdc);
	static void Clear();

	static void SetTarget(GameObject* target) { mTarget = target; } // ī�޶� ���� ����
	static const Vector2 CaluatePos(Vector2 pos) { return pos - mDistance; }
	static void SetImgResolution(Vector2 Resolution) { ImgR = Resolution; } //��� ũ��Set

	Vector2 GetLookPosition()
	{
		return mLookPosition;
	}

	void SetLookPosition(Vector2 LookPosition)
	{
		mLookPosition = LookPosition;
	}

private:
	static Vector2 mResolution; // ȭ�� �ػ�
	static Vector2 mLookPosition; //ī�޶� �Ĵٺ��� �ִ� ��ġ 
	static Vector2 mDistance; //�Ÿ�
	static GameObject* mTarget;  // ī�޶��� ������ �� ������Ʈ
	static Vector2 ImgR; // ��� ũ��

	static eCameraEffectType mType;
	static class Image* mCutton; //ȭ���� ���� �������̹���
	static float mCuttonAlpha;
	static float mAlphaTime;
	static float mEndTime;
};

