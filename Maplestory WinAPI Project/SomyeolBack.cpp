#include "SomyeolBack.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"

SomyeolBack::SomyeolBack()
{
}

SomyeolBack::~SomyeolBack()
{
}

void SomyeolBack::Initialize()
{
	mImage = RResources::Load<Image>(L"SomyeolBack", L"..\\Resources\\Map\\Somyeol.bmp");
	GameObject::Initialize();
}

void SomyeolBack::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}
void SomyeolBack::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}
void SomyeolBack::Release()
{
	GameObject::Release();

}