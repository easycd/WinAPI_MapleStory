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


Vector2 Camera::mLookRange = Vector2::Zero;

GameObject* Camera::mTarget = nullptr;

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
	mLookPosition = (mResolution / 2.0f); //Å¸°Ù±âÁØ À§Ä¡

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
	if (mLookPosition.x >= mLookRange.x - mResolution.x / 2.0f)
		mLookPosition.x = mLookRange.x - mResolution.x / 2.0f;
	if (mLookPosition.y >= mLookRange.y - mResolution.y / 2.0f)
		mLookPosition.y = mLookRange.y - mResolution.y / 2.0f;
	if (mLookPosition.y <= (mResolution.y / 2.0f))
		mLookPosition.y = (mResolution.y / 2.0f);

	//if (mTarget != nullptr)
	//{
	//	mLookPosition.x = mTarget->GetComponent<Transform>()->GetPos().x + 200.f;
	//	mLookPosition.y = mTarget->GetComponent<Transform>()->GetPos().y - 500.f;
	//}

	//if (mDistance.x < 0.0f || mDistance.x > 524.0f || mDistance.y < 0.0f || mDistance.y > 312.0f) //¸ÊX°ª - 1366, ¸ÊY°ª - 768 
	//{
	//	return;
	//}
	//else
	//{
	//	mDistance = mLookPosition - (mResolution / 2.0f);
	//}
  //

	mDistance = mLookPosition - (mResolution / 2.0f);

}