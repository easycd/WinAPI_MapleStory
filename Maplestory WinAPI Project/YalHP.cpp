#include "YalHP.h"
#include "SceneManager.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"
#include "Animation.h"
#include "Animator.h"
#include "Collider.h"
#include "Object.h"
#include "MainChar.h"

YalHP::YalHP()
	: Yal_HP(0)
	, test(0)
{
}

YalHP::~YalHP()
{
}

void YalHP::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetPos(Vector2(720.0, 75.0f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\YalHP\\0", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\YalHP\\20", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\YalHP\\30", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\YalHP\\40", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\YalHP\\60", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\YalHP\\80", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\YalHP\\100", Vector2::Zero, 0.1f);
	
	m_Animator->Play(L"YalHP100", false);
	m_Animator->SetIsCameraMove(false);
	GameObject::Initialize();
}

void YalHP::Update()
{

	test = Yal_HP;
	if (test == 0)
	{
		m_Animator->Play(L"YalHP100", false);
		m_Animator->SetIsCameraMove(false);
	}
	if (test == 1)
	{
		m_Animator->Play(L"YalHP80", false);
		m_Animator->SetIsCameraMove(false);
	}
	if (test == 2)
	{
		m_Animator->Play(L"YalHP60", false);
		m_Animator->SetIsCameraMove(false);
	}
	if (test == 3)
	{
		m_Animator->Play(L"YalHP40", false);
		m_Animator->SetIsCameraMove(false);
	}
	if (test == 4)
	{
		m_Animator->Play(L"YalHP30", false);
		m_Animator->SetIsCameraMove(false);
	}
	if (test == 5)
	{
		m_Animator->Play(L"YalHP20", false);
		m_Animator->SetIsCameraMove(false);
	}
	if (test == 6)
	{
		m_Animator->Play(L"YalHP0", false);
		m_Animator->SetIsCameraMove(false);
	}


	GameObject::Update();
}

void YalHP::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void YalHP::Release()
{
	GameObject::Release();
}

void YalHP::OnCollisionEnter(Collider* other)
{
}

void YalHP::OnCollisionStay(Collider* other)
{
}
