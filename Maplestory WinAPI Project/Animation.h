#pragma once
#include "Entity.h"

class Image;
class Animator;

class Animation : public Entity
{
public:
	struct Sprite
	{
		Vector2 leftTop;
		Vector2 size;
		Vector2 offset;
		float duration;

		Sprite()
			: leftTop(Vector2::Zero)
			, size(Vector2::Zero)
			, offset(Vector2::Zero)
			, duration(0.0f)
		{

		}
	};

	Animation();
	~Animation();

	void Initialize();
	void Update();
	void Render(HDC hdc);
	void Create(Image* sheet, Vector2 leftTop, UINT coulmn, UINT row, UINT spriteLength, Vector2 offset, float duration);
	void Reset();

	bool IsComplete() { return mbComplete; }
	void SetAnimator(Animator* animator) { mAnimator = animator; }

private:
	Animator* mAnimator;
	Image* mSheetImage;
	std::vector<Sprite> mSpriteSheet;
	float mTime;
	bool mbComplete;
	int mSpriteIndex;
	//WORD R;
	//WORD G;
	//WORD B;
	COLORREF m_Color;
	bool m_IsCameraMove;
	int m_nullcameraX;
	int m_nullcameraY;

public:
	void SetIsCameraMove(bool IsCameraMove) //카메라 설정
	{
		m_IsCameraMove = IsCameraMove;
	}

	bool GetIsCameraMove()
	{
		return m_IsCameraMove;
	}

	void SetRGB(COLORREF rgb) //이미지 색 제거 설정
	{
		m_Color = rgb;
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

