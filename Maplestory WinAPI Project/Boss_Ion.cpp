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
#include "MainChar.h"

Boss_Ion::Boss_Ion()
	: m_Time(0.0f)
	, attack2_Delay(0.0f)
	, m_State(eBoss_IonState::Respawn)
	, attack_pattern(0)
	, Direction(1)
	, SetMoveLeft(false)
	, SetMoveRight(false)
{
}

Boss_Ion::~Boss_Ion()
{
}

void Boss_Ion::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetPos(Vector2(1000.0f, 1000.0f));

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
	m_Animator->GetCompleteEvent(L"Ionattack1_Left") = std::bind(&Boss_Ion::idle, this);
	m_Animator->GetCompleteEvent(L"Ionattack2_Right") = std::bind(&Boss_Ion::idle, this);
	m_Animator->GetCompleteEvent(L"Ionattack2_Left") = std::bind(&Boss_Ion::idle, this);

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(300, 580)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-150.0f, -580.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void Boss_Ion::Update()
{
	GameObject::Update();

	Vector2 pos = tr->GetPos();
	if (Direction == 1 && SetMoveRight == true)
	{
		attack2_Delay += Time::DeltaTime();

		if (attack2_Delay > 1.7f)
		{
			pos.x += 500.0 * Time::DeltaTime();
		}
	}
	else if (Direction == 0 && SetMoveLeft == true)
	{
		attack2_Delay += Time::DeltaTime();

		if (attack2_Delay > 1.7f)
		{
			pos.x -= 500.0 * Time::DeltaTime();
		}
	}
	tr->SetPos(pos);

	if (attack2_Delay > 3.f)
	{
		SetMoveRight = false;
		SetMoveLeft = false;
	}

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
	player = SceneManager::GetPlayer();
	Vector2 playerPos = player->GetComponent<Transform>()->GetPos();
	Vector2 playerX = Vector2(playerPos.x, 0.0f);
	Vector2 mobX = Vector2(tr->GetPos().x, 0.0f);
	Vector2 dr = math::Direction(mobX, playerX);

	if (dr.x > 0.0f)
	{
		Direction = 1;
	}
	else
	{
		Direction = 0;
	}

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
	attack2_Delay = 0.0f;
	//SetMoveRight = false;
	//SetMoveLeft = false;

	if (Direction == 0)
		m_Animator->Play(L"IonstandLeft", true);
	if (Direction == 1)
		m_Animator->Play(L"IonstandRight", true);

}

void Boss_Ion::death()
{
	m_State = eBoss_IonState::Death;
	m_Animator->Play(L"Iondie", true);
}

void Boss_Ion::attack1()
{
	//사슬 휘두르기
	m_State = eBoss_IonState::Attack1;

	if (Direction == 0)
		m_Animator->Play(L"Ionattack1_Left", true);
	if (Direction == 1)
		m_Animator->Play(L"Ionattack1_Right", true);

}

void Boss_Ion::attack2()
{
	//돌진기
	m_State = eBoss_IonState::Attack2;
	if (Direction == 0)
	{
		m_Animator->Play(L"Ionattack2_Left", true);
		SetMoveLeft = true;
	}
	if (Direction == 1)
	{
		m_Animator->Play(L"Ionattack2_Right", true);
		SetMoveRight = true;
	}

}

void Boss_Ion::idleCompleteEvent()
{

}
