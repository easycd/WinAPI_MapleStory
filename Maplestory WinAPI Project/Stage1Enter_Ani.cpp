#include "Stage1Enter_Ani.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"

Stage1Enter_Ani::Stage1Enter_Ani()
{
}

Stage1Enter_Ani::~Stage1Enter_Ani()
{
}

void Stage1Enter_Ani::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(900.0f, 1050.0f));
	tr->SetScale(Vector2(0.8f, 0.8f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\Enter_Ani\\phase1", Vector2::Zero, 0.03f);
	m_Animator->Play(L"Enter_Aniphase1", false);
	GameObject::Initialize();
}

void Stage1Enter_Ani::Update()
{
	GameObject::Update();
}

void Stage1Enter_Ani::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Stage1Enter_Ani::Release()
{
	GameObject::Release();
}
