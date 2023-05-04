#include "LastMAp.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"

LastMAp::LastMAp()
{
}

LastMAp::~LastMAp()
{
}

void LastMAp::Initialize()
{
	mImage = RResources::Load<Image>(L"lastMap", L"..\\Resources\\Map\\LastMap\\LastMap.bmp");
	GameObject::Initialize();
}

void LastMAp::Update()
{
	GameObject::Update();
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}

void LastMAp::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	pos = Camera::CaluatePos(pos);
	BitBlt(hdc, pos.x - 100.f , pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void LastMAp::Release()
{
	GameObject::Release();
}
