#include "HenesysBack.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"

HenesysBack::HenesysBack()
{
}

HenesysBack::~HenesysBack()
{
}

void HenesysBack::Initialize()
{
	mImage = RResources::Load<Image>(L"Henesys", L"..\\Resources\\Map\\Henesys.bmp");
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
	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}
void HenesysBack::Release()
{
	GameObject::Release();

}