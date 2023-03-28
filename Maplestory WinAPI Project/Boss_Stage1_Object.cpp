#include "Boss_Stage1_Object.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"

Boss_Stage1_Object::Boss_Stage1_Object()
{
}

Boss_Stage1_Object::~Boss_Stage1_Object()
{
}

void Boss_Stage1_Object::Initialize()
{
	mImage = RResources::Load<Image>(L"Boss_Stage1_Object", L"..\\Resources\\Map\\Boss\\boss1_Object.bmp");
	GameObject::Initialize();
}

void Boss_Stage1_Object::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}
void Boss_Stage1_Object::Render(HDC hdc)
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
void Boss_Stage1_Object::Release()
{
	GameObject::Release();

}