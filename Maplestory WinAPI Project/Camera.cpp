#include "Camera.h"
#include "Application.h"
#include "GameObject.h"
#include "Transform.h"
#include "Input.h"
#include "Time.h"

extern Application application;

Vector2 Camera::mResolution = Vector2::Zero;
Vector2 Camera::mLookPosition = Vector2::Zero;
Vector2 Camera::mDistance = Vector2::Zero;
GameObject* Camera::mTarget = nullptr;

void Camera::Initiailize()
{
	mResolution.x = application.GetWidth();
	mResolution.y = application.GetHeight();
	mLookPosition = (mResolution / 2.0f); //타겟기준 위치
}

void Camera::Update()
{


	if (mTarget != nullptr)
	{
		mLookPosition
			= mTarget->GetComponent<Transform>()->GetPos();
	}

	mDistance = mLookPosition - (mResolution / 2.0f);


}