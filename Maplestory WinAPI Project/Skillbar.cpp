#include "Skillbar.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"

Skillbar::Skillbar()
{
}

Skillbar::~Skillbar()
{
}

void Skillbar::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(1016.0f, 680.0f));
	mImage = RResources::Load<Image>(L"Skillbar", L"..\\Resources\\UI\\CharatorState\\SkillBar.bmp");
	GameObject::Initialize();
}

void Skillbar::Update()
{
	GameObject::Update();
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}

void Skillbar::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void Skillbar::Release()
{
	GameObject::Release();
}
