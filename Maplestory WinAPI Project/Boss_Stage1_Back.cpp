#include "Boss_Stage1_Back.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"

Boss_Stage1_Back::Boss_Stage1_Back()
{
}

Boss_Stage1_Back::~Boss_Stage1_Back()
{
}

void Boss_Stage1_Back::Initialize()
{
	mImage = RResources::Load<Image>(L"Boss_Stage1_Back", L"..\\Resources\\Map\\boss1.bmp");
	GameObject::Initialize();
}

void Boss_Stage1_Back::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}
void Boss_Stage1_Back::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}
void Boss_Stage1_Back::Release()
{
	GameObject::Release();

}