#include "MousCollider.h"
#include "Collider.h"
#include "MainChar.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "Scania.h"

MousCollider::MousCollider()
{
}

MousCollider::~MousCollider()
{
}

void MousCollider::Initialize()
{
	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(20.0f, 20.0f));
	collider->SetCenter(Vector2(0.0f, 0.0f));

	GameObject::Initialize();
}

void MousCollider::Update()
{
	GameObject::Update();
}

void MousCollider::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void MousCollider::Release()
{
	GameObject::Release();
}

void MousCollider::OnCollisionEnter(Collider* other)
{
	Scania* sc = dynamic_cast<Scania*>(other->GetOwner());
	if (sc != nullptr)
	{
		int a = 0;
	}
}

void MousCollider::OnCollisionStay(Collider* other)
{
	Scania* sc = dynamic_cast<Scania*>(other->GetOwner());
	if (sc != nullptr)
	{
		int a = 0;
	}
}

void MousCollider::OnCollisionExit(Collider* other)
{
}
