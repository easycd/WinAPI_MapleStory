#include "Exbar.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"

Exbar::Exbar()
{
}

Exbar::~Exbar()
{
}

void Exbar::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(0.0, 758.0f));
	mImage = RResources::Load<Image>(L"Exbar", L"..\\Resources\\UI\\CharatorState\\game_exbar.bmp");
	GameObject::Initialize();
}

void Exbar::Update()
{
	GameObject::Update();
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}

void Exbar::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void Exbar::Release()
{
	GameObject::Release();
}
