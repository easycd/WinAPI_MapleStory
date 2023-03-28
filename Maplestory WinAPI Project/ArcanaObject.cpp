#include "ArcanaObject.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"

ArcanaObject::ArcanaObject()
{
}

ArcanaObject::~ArcanaObject()
{
}

void ArcanaObject::Initialize()
{
	mImage = RResources::Load<Image>(L"ArcanaObject", L"..\\Resources\\Map\\Arcana\\Arcana_Object.bmp");
	GameObject::Initialize();
}

void ArcanaObject::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}
void ArcanaObject::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	pos = Camera::CaluatePos(pos);
	//BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	TransparentBlt(hdc
		, pos.x, pos.y + 12
		, mImage->GetWidth()
		, mImage->GetHeight()
		, mImage->GetHdc()
		, 0, 0
		, mImage->GetWidth(), mImage->GetHeight()
		, RGB(207, 207, 207));
}
void ArcanaObject::Release()
{
	GameObject::Release();

}