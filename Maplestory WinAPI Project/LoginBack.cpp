#include "LoginBack.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"

LoginBack::LoginBack()
{
}

LoginBack::~LoginBack()
{
}

void LoginBack::Initialize()
{
	mImage = RResources::Load<Image>(L"LoginBack", L"..\\Resources\\LoginUI\\Login.bmp");
	GameObject::Initialize();
}

void LoginBack::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}
void LoginBack::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}
void LoginBack::Release()
{
	GameObject::Release();

}
