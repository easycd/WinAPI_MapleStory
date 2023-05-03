#include "HpBar.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"
#include "Animation.h"
#include "Animator.h"
#include "Collider.h"
#include "MousCollider.h"

HpBar::HpBar()
{
}

HpBar::~HpBar()
{
}

void HpBar::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetPos(Vector2(696.f,721.f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\HP", Vector2::Zero, 0.1f);
	m_Animator->Play(L"UIHP", true);
	m_Animator->SetIsCameraMove(false);
	GameObject::Initialize();
}

void HpBar::Update()
{
	GameObject::Update();

}

void HpBar::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void HpBar::Release()
{
	GameObject::Release();
}

void HpBar::OnCollisionEnter(Collider* other)
{
}

void HpBar::OnCollisionStay(Collider* other)
{
}
