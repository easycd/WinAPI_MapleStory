#include "BossHP_Bar.h"
#include "SceneManager.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"
#include "Animation.h"
#include "Animator.h"
#include "Collider.h"
#include "Object.h"
#include "Boss.h"
#include "Boss_Stage2_Scene.h"

BossHP_Bar::BossHP_Bar()
	: BossHP(0)
	, test(0)
{
}

BossHP_Bar::~BossHP_Bar()
{
}

void BossHP_Bar::Initialize()
{
	tr = GetComponent<Transform>();
	//tr->SetPos(Vector2(720.0, 40.0f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\HP\\0", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\HP\\10", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\HP\\20", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\HP\\30", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\HP\\50", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\HP\\60", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\HP\\80", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Boss\\HP\\100", Vector2::Zero, 0.1f);

	m_Animator->Play(L"HP100", false);
	m_Animator->SetIsCameraMove(false);
	GameObject::Initialize();
}

void BossHP_Bar::Update()
{
	test = BossHP;
	if (test == 0)
		m_Animator->Play(L"HP100", false);
	if (test == 1)
		m_Animator->Play(L"HP80", false);
	if (test == 2)
		m_Animator->Play(L"HP60", false);
	if (test == 3)
		m_Animator->Play(L"HP50", false);
	if (test == 4)
		m_Animator->Play(L"HP30", false);
	if (test == 5)
		m_Animator->Play(L"HP20", false);
	if (test == 6)
		m_Animator->Play(L"HP10", false);
	if (test == 7)
		m_Animator->Play(L"HP0", false);


	GameObject::Update();
}

void BossHP_Bar::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BossHP_Bar::Release()
{
	GameObject::Release();
}

void BossHP_Bar::OnCollisionEnter(Collider* other)
{
}

void BossHP_Bar::OnCollisionStay(Collider* other)
{
}
