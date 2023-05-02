#include "Scania.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"
#include "Animation.h"
#include "Animator.h"
#include "Collider.h"
#include "MousCollider.h"

Scania::Scania()
{
}

Scania::~Scania()
{
}

void Scania::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(-420.f, 70.f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\StartUI\\Scania", Vector2::Zero, 0.1f);
	m_Animator->Play(L"StartUIScania", true);
	
	

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(100.0f, 50.0f));
	collider->SetCenter(Vector2(-50.0f, -50.0f));

	GameObject::Initialize();
}

void Scania::Update()
{
	GameObject::Update();
}

void Scania::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Scania::Release()
{
	GameObject::Release();
}

void Scania::OnCollisionEnter(Collider* other)
{
}

void Scania::OnCollisionStay(Collider* other)
{

}
