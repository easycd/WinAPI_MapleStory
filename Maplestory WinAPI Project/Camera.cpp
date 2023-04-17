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
	/*if (mTarget != nullptr)
	{
		mLookPosition.x = mTarget->GetComponent<Transform>()->GetPos().x + 500.f;
		mLookPosition.y = mTarget->GetComponent<Transform>()->GetPos().y + 100;
	}*/

	//if (mDistance.x < 0.0f || mDistance.x > 524.0f || mDistance.y < 0.0f || mDistance.y > 312.0f) //¸ÊX°ª - 1366, ¸ÊY°ª - 768 
	//{
	//	return;
	//}
	//else
	//{
	//	mDistance = mLookPosition - (mResolution / 2.0f);
	//}


	mDistance = mLookPosition - (mResolution / 2.0f);

}