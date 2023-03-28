#include "HenesysObject.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"

HenesysObject::HenesysObject()
{
}

HenesysObject::~HenesysObject()
{
}

void HenesysObject::Initialize()
{
	mImage = RResources::Load<Image>(L"Henesys_Object", L"..\\Resources\\Map\\Henesys\\Henesys_Object.bmp");
	GameObject::Initialize();
}

void HenesysObject::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}
void HenesysObject::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	pos = Camera::CaluatePos(pos);
	//BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	TransparentBlt(hdc
		, pos.x, pos.y
		, mImage->GetWidth()
		, mImage->GetHeight()
		, mImage->GetHdc()
		, 0, 0
		, mImage->GetWidth(), mImage->GetHeight()
		, RGB(207, 207, 207));
}
void HenesysObject::Release()
{
	GameObject::Release();

}