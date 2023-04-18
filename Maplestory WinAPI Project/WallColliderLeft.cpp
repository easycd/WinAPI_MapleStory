#include "WallColliderLeft.h"
#include "Collider.h"
#include "MainChar.h"
#include "Rigidbody.h"
#include "Transform.h"

WallColliderLeft::WallColliderLeft()
{
}

WallColliderLeft::~WallColliderLeft()
{
}

void WallColliderLeft::Initialize()
{
	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(50.0f, 50.0f));
	collider->SetCenter(Vector2(0.0f, 0.0f));
	GameObject::Initialize();
}

void WallColliderLeft::Update()
{
	GameObject::Update();
}

void WallColliderLeft::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void WallColliderLeft::Release()
{
	GameObject::Release();
}

void WallColliderLeft::OnCollisionEnter(Collider* other)
{

}

void WallColliderLeft::OnCollisionStay(Collider* other)
{
}

void WallColliderLeft::OnCollisionExit(Collider* other)
{
}
