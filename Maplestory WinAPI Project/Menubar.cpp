#include "Menubar.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"


Menubar::Menubar()
{
}

Menubar::~Menubar()
{
}

void Menubar::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(800.0, 700.0f));
	mImage = RResources::Load<Image>(L"Menubar", L"..\\Resources\\UI\\CharatorState\\menubar.bmp");
	GameObject::Initialize();
}

void Menubar::Update()
{
	GameObject::Update();
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}

void Menubar::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
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

void Menubar::Release()
{
	GameObject::Release();
}
