#include "Boss_Stage2_Back.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"

Boss_Stage2_Back::Boss_Stage2_Back()
{
}

Boss_Stage2_Back::~Boss_Stage2_Back()
{
}

void Boss_Stage2_Back::Initialize()
{
	mImage = RResources::Load<Image>(L"Boss_Stage2_Back", L"..\\Resources\\Map\\boss2.bmp");
	GameObject::Initialize();
}

void Boss_Stage2_Back::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}
void Boss_Stage2_Back::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	pos = Camera::CaluatePos(pos);
	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}
void Boss_Stage2_Back::Release()
{
	GameObject::Release();

}