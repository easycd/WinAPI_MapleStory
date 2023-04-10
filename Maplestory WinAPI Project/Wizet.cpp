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
	tr->SetPos(Vector2(670.0f, 450.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Wizet", Vector2::Zero, 0.1f);
	m_Animator->Play(L"ResourcesWizet", false);
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
