#include "Hp_Mp.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"

Hp_Mp::Hp_Mp()
{
}

Hp_Mp::~Hp_Mp()
{
}

void Hp_Mp::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(585.0, 680.0f));
	mImage = RResources::Load<Image>(L"hp/mp", L"..\\Resources\\UI\\CharatorState\\hp.mp_status.bmp");
	GameObject::Initialize();
}

void Hp_Mp::Update()
{
	GameObject::Update();
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}

void Hp_Mp::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	
	//BitBlt(hdc, 
	//	pos.x, pos.y
	//	, mImage->GetWidth()
	//	, mImage->GetHeight()
	//	, mImage->GetHdc()
	//	, 0, 0
	//	, SRCCOPY);
	TransparentBlt(hdc
		, pos.x, pos.y
		, mImage->GetWidth()
		, mImage->GetHeight()
		, mImage->GetHdc()
		, 0, 0
		, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 0, 255));
}

void Hp_Mp::Release()
{
	GameObject::Release();
}
