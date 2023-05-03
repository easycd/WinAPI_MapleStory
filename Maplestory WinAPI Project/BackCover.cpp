#include "BackCover.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"

BackCover::BackCover()
{
}

BackCover::~BackCover()
{
}

void BackCover::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(585.0, 680.0f));
	mImage = RResources::Load<Image>(L"hp/mp", L"..\\Resources\\UI\\HPBakcCover\\HP_Cover.bmp");
	GameObject::Initialize();
}

void BackCover::Update()
{
	GameObject::Update();
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}

void BackCover::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	BitBlt(hdc, 
		   pos.x, pos.y
		   , mImage->GetWidth()
		   , mImage->GetHeight()
		   , mImage->GetHdc()
		   , 0, 0
		   , SRCCOPY);
	
}

void BackCover::Release()
{
	GameObject::Release();
}
