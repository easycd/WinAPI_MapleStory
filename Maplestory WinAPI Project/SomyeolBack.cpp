#include "SomyeolBack.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"

SomyeolBack::SomyeolBack()
{
}

SomyeolBack::~SomyeolBack()
{
}

void SomyeolBack::Initialize()
{

	mImage = RResources::Load<Image>(L"SomyeolBack", L"..\\Resources\\Map\\Somyeol\\Somyeol_Back.bmp");
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
	pos = Camera::CaluatePos(pos);
	BitBlt(hdc, pos.x, pos.y + 50, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}
void SomyeolBack::Release()
{
	GameObject::Release();

}