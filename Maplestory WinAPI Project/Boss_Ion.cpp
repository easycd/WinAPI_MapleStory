#include "Boss_Ion.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"
#include "BossIon_Attack1.h"
#include "BossIon_Attack2.h"

Boss_Ion::Boss_Ion()
	: m_Time(0.0f)
	, m_State(eBoss_IonState::Respawn)
	, attack_pattern(0)
{
}

Boss_Ion::~Boss_Ion()
{
}

void Boss_Ion::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(1000.0f, 800.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\respawn", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\standLeft", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\standRight", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\die_Left", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\die_Right", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\attack1_Left", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\attack1_Right", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\attack2_Left", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\attack2_Right", Vector2::Zero, 0.08f);


	m_Animator->GetCompleteEvent(L"Ionrespawn") = std::bind(&Boss_Ion::idle, this);
	m_Animator->GetCompleteEvent(L"Ionattack1_Right") = std::bind(&Boss_Ion::idle, this);
	m_Animator->GetCompleteEvent(L"Ionattack2_Right") = std::bind(&Boss_Ion::idle, this);
	//m_Animator->GetCompleteEvent(L"Ionstand") = std::bind(&Boss_Ion::attack1, this);

	//m_State = eBoss_IonState::Attack1;

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(300, 580)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-150.0f, -580.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void Boss_Ion::Update()
{
	GameObject::Update();
	switch (m_State)
	{
	case Boss_Ion::eBoss_IonState::Pattern:
		pattern();
		break;
	default:
		break;
	}

}

void Boss_Ion::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(207, 207, 207));
	GameObject::Render(hdc);
}

void Boss_Ion::Release()
{
	GameObject::Release();
}

void Boss_Ion::respawn()
{
	m_Animator->Play(L"Ionrespawn", true);
}

void Boss_Ion::pattern()
{
	m_Time += Time::DeltaTime();
	if (m_Time > 3.0f)
	{
		m_Time = 0.0f;
		attack_pattern = rand() % 2;

		switch (attack_pattern)
		{
		case 0:
			attack1();
			break;
		case 1:
			attack2();
			break;
		default:
			break;
		}
	}
}

void Boss_Ion::idle()
{
	m_State = eBoss_IonState::Pattern;
	m_Animator->Play(L"IonstandRight", true);

}

void Boss_Ion::dead()
{
	m_State = eBoss_IonState::Death;
	m_Animator->Play(L"Iondie", true);
}

void Boss_Ion::attack1()
{
	m_State = eBoss_IonState::Attack1;
	m_Animator->Play(L"Ionattack1_Right", true);

}

void Boss_Ion::attack2()
{
	m_State = eBoss_IonState::Attack2;
	m_Animator->Play(L"Ionattack2_Right", true);
}

void Boss_Ion::idleCompleteEvent()
{
}
