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
	void SetR(WORD r) { WORD R = r; }
	void SetG(WORD g) { WORD G = g; }
	void SetB(WORD b) { WORD B = b; }
	void SetRGB(COLORREF rgb) { COLORREF Color = rgb; }

private:
	Animator* mAnimator;
	Image* mSheetImage;
	std::vector<Sprite> mSpriteSheet;
	float mTime;
	bool mbComplete;
	int mSpriteIndex;
	WORD R;
	WORD G;
	WORD B;
	COLORREF Color;
	};

