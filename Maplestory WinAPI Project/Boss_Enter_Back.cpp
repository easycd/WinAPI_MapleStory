#include "Boss_Enter_Back.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"

Boss_Enter_Back::Boss_Enter_Back()
{
}

Boss_Enter_Back::~Boss_Enter_Back()
{
}

void Boss_Enter_Back::Initialize()
{
	mImage = RResources::Load<Image>(L"Boss_Enter_Back", L"..\\Resources\\Map\\Boss\\boss_enter.bmp");
	GameObject::Initialize();
}

void Boss_Enter_Back::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}
void Boss_Enter_Back::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	pos = Camera::CaluatePos(pos);
	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}
void Boss_Enter_Back::Release()
{
	GameObject::Release();

}