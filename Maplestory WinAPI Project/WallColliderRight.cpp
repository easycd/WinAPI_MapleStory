#include "WallColliderRight.h"
#include "Collider.h"
#include "MainChar.h"
#include "Rigidbody.h"
#include "Transform.h"

WallColliderRight::WallColliderRight()
{
}

WallColliderRight::~WallColliderRight()
{
}

void WallColliderRight::Initialize()
{
	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(50.0f, 50.0f));
	collider->SetCenter(Vector2(0.0f, 0.0f));
	GameObject::Initialize();
}

void WallColliderRight::Update()
{
	GameObject::Update();
}

void WallColliderRight::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void WallColliderRight::Release()
{
	GameObject::Release();
}

void WallColliderRight::OnCollisionEnter(Collider* other)
{

}

void WallColliderRight::OnCollisionStay(Collider* other)
{
}

void WallColliderRight::OnCollisionExit(Collider* other)
{
}
