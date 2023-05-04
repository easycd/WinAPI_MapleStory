#include "BossHP_State.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"

BossHP_State::BossHP_State()
{
}

BossHP_State::~BossHP_State()
{
}

void BossHP_State::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(330.0f, 0.0f));
	mImage = RResources::Load<Image>(L"boss_hp_bar", L"..\\Resources\\UI\\Boss\\HP_Bar\\boss_hp_bar.bmp");
	GameObject::Initialize();
}

void BossHP_State::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}

void BossHP_State::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	TransparentBlt(hdc
		, pos.x, pos.y 
		, mImage->GetWidth()
		, mImage->GetHeight()
		, mImage->GetHdc()
		, 0, 0
		, mImage->GetWidth(), mImage->GetHeight()
		, RGB(207, 207, 207));
}

void BossHP_State::Release()
{
	GameObject::Release();
}
