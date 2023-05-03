#include "Stage2Enter_Ani.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"

Stage2Enter_Ani::Stage2Enter_Ani()
{
}

Stage2Enter_Ani::~Stage2Enter_Ani()
{
}

void Stage2Enter_Ani::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(2670.0f, 1150.0f));
	tr->SetScale(Vector2(0.75f, 0.75f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\Enter_Ani\\phase2", Vector2::Zero, 0.03f);
	m_Animator->Play(L"Enter_Aniphase2", false);
	GameObject::Initialize();
}

void Stage2Enter_Ani::Update()
{
	GameObject::Update();
}

void Stage2Enter_Ani::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Stage2Enter_Ani::Release()
{
	GameObject::Release();
}
