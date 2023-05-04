#include "IonHP.h"
#include "SceneManager.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"
#include "Animation.h"
#include "Animator.h"
#include "Collider.h"
#include "Object.h"

IonHP::IonHP()
	: Ion_HP(0)
	, test(0)
{
}

IonHP::~IonHP()
{
}

void IonHP::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetPos(Vector2(720.0, 40.0f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\IonHP\\0", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\IonHP\\10", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\IonHP\\20", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\IonHP\\30", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\IonHP\\50", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\IonHP\\60", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\IonHP\\80", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\IonHP\\100", Vector2::Zero, 0.1f);

	m_Animator->Play(L"IonHP100", false);
	m_Animator->SetIsCameraMove(false);
	GameObject::Initialize();
}

void IonHP::Update()
{
	test = Ion_HP;
	if (test == 0)
	{
		m_Animator->Play(L"IonHP100", false);
		m_Animator->SetIsCameraMove(false);
	}
	if (test == 1)
	{
		m_Animator->Play(L"IonHP80", false);
		m_Animator->SetIsCameraMove(false);
	}
	if (test == 2)
	{
		m_Animator->Play(L"IonHP60", false);
		m_Animator->SetIsCameraMove(false);
	}
	if (test == 3)
	{
		m_Animator->Play(L"IonHP50", false);
		m_Animator->SetIsCameraMove(false);
	}
	if (test == 4)
	{
		m_Animator->Play(L"IonHP30", false);
		m_Animator->SetIsCameraMove(false);
	}
	if (test == 5)
	{
		m_Animator->Play(L"IonHP20", false);
		m_Animator->SetIsCameraMove(false);
	}
	if (test == 6)
	{	m_Animator->Play(L"IonHP10", false);
		m_Animator->SetIsCameraMove(false);
    }	
	if (test == 7)
	{
		m_Animator->Play(L"IonHP0", false);
		m_Animator->SetIsCameraMove(false);
	}

	GameObject::Update();
}

void IonHP::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void IonHP::Release()
{
	GameObject::Release();
}

void IonHP::OnCollisionEnter(Collider* other)
{
}

void IonHP::OnCollisionStay(Collider* other)
{
}
