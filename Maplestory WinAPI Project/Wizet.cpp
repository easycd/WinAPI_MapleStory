#include "Wizet.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"

Wizet::Wizet()
{
}

Wizet::~Wizet()
{
}

void Wizet::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	//tr->SetPos(Vector2(670.0f, 450.0f));
	tr->SetPos(Vector2(-700.f, 450.f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\StartUI\\Wizet", Vector2::Zero, 0.1f);
	m_Animator->Play(L"StartUIWizet", false);
	GameObject::Initialize();
}

void Wizet::Update()
{
	GameObject::Update();
}
void Wizet::Render(HDC hdc)
{
	GameObject::Render(hdc);
}
void Wizet::Release()
{
	GameObject::Release();
}
