#include "HenesysBack.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"

HenesysBack::HenesysBack()
{
}

HenesysBack::~HenesysBack()
{
}

void HenesysBack::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetScale(Vector2(2.f, 2.f));
	mImage = RResources::Load<Image>(L"Henesys_Back", L"..\\Resources\\Map\\Henesys\\Henesys_Back.bmp");
	GameObject::Initialize();
} 

void HenesysBack::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}
void HenesysBack::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	pos = Camera::CaluatePos(pos);
	BitBlt(hdc, pos.x, pos.y , mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}
void HenesysBack::Release()
{
	GameObject::Release();
}