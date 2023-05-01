#include "Camera.h"
#include "Application.h"
#include "GameObject.h"
#include "Transform.h"
#include "Input.h"
#include "Time.h"
#include "HenesysBack.h"

extern Application application;

Vector2 Camera::mResolution = Vector2::Zero;
Vector2 Camera::mLookPosition = Vector2::Zero;
Vector2 Camera::mDistance = Vector2::Zero;
Vector2 Camera::ImgR = Vector2::Zero;
GameObject* Camera::mTarget = nullptr;

Camera::eCameraEffectType Camera::mType = Camera::eCameraEffectType::None;
class Image* Camera::mCutton = nullptr;
float Camera::mCuttonAlpha = 1.0f;
float Camera::mAlphaTime = 0.0f;
float Camera::mEndTime = 10.0f;

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Initiailize()
{
	mResolution.x = application.GetWidth();
	mResolution.y = application.GetHeight();
	mLookPosition = (mResolution / 2.0f); //타겟기준 위치

	//mType = eCameraEffectType::FadeIn;
	mType = eCameraEffectType::FadeOut;
	mCutton = Image::Create(L"Cutton", mResolution.x, mResolution.y);
}

void Camera::Update()
{

	if (mTarget != nullptr)
	{
		mLookPosition
			= mTarget->GetComponent<Transform>()->GetPos();
	}

	if (mLookPosition.x <= (mResolution.x / 2.0f))
		mLookPosition.x = (mResolution.x / 2.0f);
	if (mLookPosition.x >= ImgR.x - mResolution.x / 2.0f)
		mLookPosition.x = ImgR.x - mResolution.x / 2.0f;
	if (mLookPosition.y >= ImgR.y - mResolution.y / 2.0f)
		mLookPosition.y = ImgR.y - mResolution.y / 2.0f;
	if (mLookPosition.y <= (mResolution.y / 2.0f))
		mLookPosition.y = (mResolution.y / 2.0f);

	mDistance = mLookPosition - (mResolution / 2.0f);

	if (mAlphaTime < mEndTime)
	{
		//255 - > 1
		mAlphaTime += Time::DeltaTime();
		float ratio = (mAlphaTime / mEndTime);
	
		if (mType == eCameraEffectType::FadeIn)
		{
			mCuttonAlpha = 1.0f - ratio;
		}
		else if (mType == eCameraEffectType::FadeOut)
		{
			mCuttonAlpha = ratio;
		}
		else
		{
	
		}
	}
}

void Camera::Render(HDC hdc)
{
	if (mAlphaTime < mEndTime
		&& mType == eCameraEffectType::FadeIn)
	{
		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = 0;
		func.SourceConstantAlpha = (BYTE)(255.0f * mCuttonAlpha);
	
		AlphaBlend(hdc, 0, 0
			, mResolution.x, mResolution.y
			, mCutton->GetHdc()
			, 0, 0
			, mCutton->GetWidth(), mCutton->GetHeight()
			, func);
	}
}

void Camera::Clear()
{
	mResolution.x = application.GetWidth();
	mResolution.y = application.GetHeight();
	mLookPosition = (mResolution / 2.0f);
	mDistance = Vector2::Zero;
}
