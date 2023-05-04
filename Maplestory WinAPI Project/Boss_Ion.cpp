#include "Boss_Ion.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"
#include "MainChar.h"
#include "Object.h"

#include "BasicSkill.h"
#include "Cosmos.h"
#include "SolunaDivideStart.h"

#include "Sound.h"

Boss_Ion::Boss_Ion()
	: m_Time(0.0f)
	, attack2_Delay(0.0f)
	, m_State(eBoss_IonState::Respawn)
	, attack_pattern(0)
	, Direction(1)
	, SetMoveLeft(false)
	, SetMoveRight(false)
	, die_Check(true)
	, I_Die(false)
	, Hp(0)
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
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\die_Left", Vector2::Zero, 0.09f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\die_Right", Vector2::Zero, 0.09f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\attack1_Left", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\attack1_Right", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\attack2_Left", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\attack2_Right", Vector2::Zero, 0.08f);

	skill1 = RResources::Load<Sound>(L"skill1", L"..\\Resources\\Sound\\Boss_Sound\\ion_attack1.wav");
	skill2 = RResources::Load<Sound>(L"sikll2", L"..\\Resources\\Sound\\Boss_Sound\\ion_attack2.wav");
	respawn = RResources::Load<Sound>(L"respawn", L"..\\Resources\\Sound\\Boss_Sound\\ion_respawn.wav");
	die = RResources::Load<Sound>(L"die", L"..\\Resources\\Sound\\Boss_Sound\\ion_Die.wav");



	m_Animator->GetCompleteEvent(L"Ionrespawn") = std::bind(&Boss_Ion::idle, this);
	m_Animator->GetCompleteEvent(L"Ionattack1_Right") = std::bind(&Boss_Ion::idle, this);
	m_Animator->GetCompleteEvent(L"Ionattack1_Left") = std::bind(&Boss_Ion::idle, this);
	m_Animator->GetCompleteEvent(L"Ionattack2_Right") = std::bind(&Boss_Ion::idle, this);
	m_Animator->GetCompleteEvent(L"Ionattack2_Left") = std::bind(&Boss_Ion::idle, this);
	m_Animator->GetCompleteEvent(L"Iondie_Left") = std::bind(&Boss_Ion::Destroy, this);
	m_Animator->GetCompleteEvent(L"Iondie_Right") = std::bind(&Boss_Ion::Destroy, this);

	Idle_collider = AddComponent<Collider>();
	Idle_collider->SetSize(Vector2(350, 600)); // 히트박스 크기 조정
	Idle_collider->SetCenter(Vector2(-100.f, -650.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void Boss_Ion::Update()
{
	GameObject::Update();

	if (Hp == 7)
		death();

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

void Boss_Ion::OnCollisionEnter(Collider* other)
{
	BasicSkill* bs = dynamic_cast<BasicSkill*>(other->GetOwner());
	if (bs != nullptr)
	{
		Hp += 1;
	}
	SolunaDivideStart* divide = dynamic_cast<SolunaDivideStart*>(other->GetOwner());
	if (divide != nullptr)
	{
		Hp += 1;
	}
	Cosmos* cosmos = dynamic_cast<Cosmos*>(other->GetOwner());
	if (cosmos != nullptr)
	{
		Hp += 1;
	}
}

void Boss_Ion::OnCollisionStay(Collider* other)
{
	
}

void Boss_Ion::Ion_respawn()
{
	respawn->Play(false);
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

	if (Direction == 0)
		m_Animator->Play(L"IonstandLeft", true);
	if (Direction == 1)
		m_Animator->Play(L"IonstandRight", true);

}

void Boss_Ion::death()
{
	m_State = eBoss_IonState::Death;
	if (Direction == 0)
	{
		if (die_Check == true)
		{
			die->Play(false);
			m_Animator->Play(L"Iondie_Left", true);
			die_Check = false;
		}

	}
	else if (Direction == 1)
	{
		if (die_Check == true)
		{
			die->Play(false);
			m_Animator->Play(L"Iondie_Right", true);
			die_Check = false;
		}
	}
}

void Boss_Ion::attack1()
{
	//사슬 휘두르기
	m_State = eBoss_IonState::Attack1;
	
	skill1->Play(false);
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
		skill2->Play(false);
		m_Animator->Play(L"Ionattack2_Left", true);
		SetMoveLeft = true;
	}
	if (Direction == 1)
	{
		skill2->Play(false);
		m_Animator->Play(L"Ionattack2_Right", true);
		SetMoveRight = true;
	}

}

void Boss_Ion::Destroy()
{
	I_Die = true;
	object::Destory(this);
}
