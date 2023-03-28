#include "SomyeolObject.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"

SomyeolObject::SomyeolObject()
{
}

SomyeolObject::~SomyeolObject()
{
}

void SomyeolObject::Initialize()
{

	mImage = RResources::Load<Image>(L"SomyeolObject", L"..\\Resources\\Map\\Somyeol\\Somyeol_Object.bmp");
	GameObject::Initialize();
}

void SomyeolObject::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}
void SomyeolObject::Render(HDC hdc)
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
void SomyeolObject::Release()
{
	GameObject::Release();

}