#include "CheckBoxCollider.h"
#include "Collider.h"
#include "MainChar.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "Scania.h"

CheckBoxCollider::CheckBoxCollider()
{
}

CheckBoxCollider::~CheckBoxCollider()
{
}

void CheckBoxCollider::Initialize()
{
	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(50.0f, 50.0f));
	collider->SetCenter(Vector2(0.0f, 0.0f));

	GameObject::Initialize();
}

void CheckBoxCollider::Update()
{
	GameObject::Update();
}

void CheckBoxCollider::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void CheckBoxCollider::Release()
{
	GameObject::Release();
}

void CheckBoxCollider::OnCollisionEnter(Collider* other)
{
}

void CheckBoxCollider::OnCollisionStay(Collider* other)
{
	MainChar* mc = dynamic_cast<MainChar*>(other->GetOwner());
	if (mc != nullptr)
	{
		int a = 0;
	}
}

void CheckBoxCollider::OnCollisionExit(Collider* other)
{
}
