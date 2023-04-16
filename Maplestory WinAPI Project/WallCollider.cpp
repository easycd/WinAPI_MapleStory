#include "WallCollider.h"
#include "Collider.h"
#include "MainChar.h"
#include "Rigidbody.h"
#include "Transform.h"

WallCollider::WallCollider()
{
}

WallCollider::~WallCollider()
{
}

void WallCollider::Initialize()
{
	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(1700.0f, 50.0f));
	collider->SetCenter(Vector2(0.0f, 0.0f));
	GameObject::Initialize();
}

void WallCollider::Update()
{
	GameObject::Update();
}

void WallCollider::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void WallCollider::Release()
{
	GameObject::Release();
}

void WallCollider::OnCollisionEnter(Collider* other)
{

}

void WallCollider::OnCollisionStay(Collider* other)
{
}

void WallCollider::OnCollisionExit(Collider* other)
{
}
