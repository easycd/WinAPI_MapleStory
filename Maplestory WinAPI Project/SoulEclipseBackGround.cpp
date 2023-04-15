#include "SoulEclipseBackGround.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"

SoulEclipseBackGround::SoulEclipseBackGround()
{
}

SoulEclipseBackGround::~SoulEclipseBackGround()
{
}

void SoulEclipseBackGround::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetScale(Vector2(5.0f, 5.0f));
	mImage = RResources::Load<Image>(L"SoulEclipseBG", L"..\\Resources\\Skill\\SoulEclipse\\BackGround\\BackGround.bmp");
	GameObject::Initialize();
}

void SoulEclipseBackGround::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}

void SoulEclipseBackGround::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void SoulEclipseBackGround::Release()
{
	GameObject::Release();
}
