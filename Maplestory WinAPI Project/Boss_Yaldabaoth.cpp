#include "Boss_Yaldabaoth.h"
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


Boss_Yaldabaoth::Boss_Yaldabaoth()
	: m_Time(0.0f)
	, attack2_Delay(0.0f)
	, m_State(eBoss_YaldabaothState::Respawn)
	, attack_pattern(0)
	, Direction(0)
	, SetMoveLeft(false)
	, SetMoveRight(false)
	, die_Check(true)
	, Y_Die(false)
	, Hp(10)
{
}

Boss_Yaldabaoth::~Boss_Yaldabaoth()
{
}

void Boss_Yaldabaoth::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetPos(Vector2(1000.0f, 1000.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Yaldabaoth\\Y_respawn", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Yaldabaoth\\Y_stand_Left", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Yaldabaoth\\Y_stand_Right", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Yaldabaoth\\Y_die_Left", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Yaldabaoth\\Y_die_Right", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Yaldabaoth\\Y_attack1_Left", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Yaldabaoth\\Y_attack1_Right", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Yaldabaoth\\Y_attack2_Left", Vector2::Zero, 0.08f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Yaldabaoth\\Y_attack2_Right", Vector2::Zero, 0.08f);


	m_Animator->GetCompleteEvent(L"YaldabaothY_respawn") = std::bind(&Boss_Yaldabaoth::idle, this);
	m_Animator->GetCompleteEvent(L"YaldabaothY_attack1_Right") = std::bind(&Boss_Yaldabaoth::idle, this);
	m_Animator->GetCompleteEvent(L"YaldabaothY_attack1_Left") = std::bind(&Boss_Yaldabaoth::idle, this);
	m_Animator->GetCompleteEvent(L"YaldabaothY_attack2_Right") = std::bind(&Boss_Yaldabaoth::idle, this);
	m_Animator->GetCompleteEvent(L"YaldabaothY_attack2_Left") = std::bind(&Boss_Yaldabaoth::idle, this);
	m_Animator->GetCompleteEvent(L"YaldabaothY_die_Left") = std::bind(&Boss_Yaldabaoth::Destroy, this);
	m_Animator->GetCompleteEvent(L"YaldabaothY_die_Right") = std::bind(&Boss_Yaldabaoth::Destroy, this);

	Idle_collider = AddComponent<Collider>();
	Idle_collider->SetSize(Vector2(350, 600)); // 히트박스 크기 조정
	Idle_collider->SetCenter(Vector2(-70.0f, -690.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void Boss_Yaldabaoth::Update()
{
	GameObject::Update();

	if (Hp == 0)
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
	case Boss_Yaldabaoth::eBoss_YaldabaothState::Pattern:
		pattern();
		break;
	default:
		break;
	}
}

void Boss_Yaldabaoth::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(207, 207, 207));
	GameObject::Render(hdc);
}

void Boss_Yaldabaoth::Release()
{
	GameObject::Release();
}

void Boss_Yaldabaoth::OnCollisionEnter(Collider* other)
{
	BasicSkill* bs = dynamic_cast<BasicSkill*>(other->GetOwner());
	if (bs != nullptr)
	{
		//bshit = object::Instantiate<BsHit>(eLayerType::Skill_hit);
		//bshit->Hit();
		Hp -= 10;
	}
	SolunaDivideStart* divide = dynamic_cast<SolunaDivideStart*>(other->GetOwner());
	if (divide != nullptr)
	{
		Hp -= 10;
	}
	Cosmos* cosmos = dynamic_cast<Cosmos*>(other->GetOwner());
	if (cosmos != nullptr)
	{
		Hp -= 10;
	}
}

void Boss_Yaldabaoth::OnCollisionStay(Collider* other)
{
}

void Boss_Yaldabaoth::Yaldabaoth_respawn()
{
	m_Animator->Play(L"YaldabaothY_respawn", true);
}

void Boss_Yaldabaoth::pattern()
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

void Boss_Yaldabaoth::idle()
{
	m_State = eBoss_YaldabaothState::Pattern;
	attack2_Delay = 0.0f;

	if (Direction == 0)
		m_Animator->Play(L"YaldabaothY_stand_Left", true);
	if (Direction == 1)
		m_Animator->Play(L"YaldabaothY_stand_Right", true);

}

void Boss_Yaldabaoth::death()
{
	m_State = eBoss_YaldabaothState::Death;
	if (Direction == 0)
	{
		if (die_Check == true)
		{
			m_Animator->Play(L"YaldabaothY_die_Left", true);
			die_Check = false;
		}

	}
	else if (Direction == 1)
	{
		if (die_Check == true)
		{
			m_Animator->Play(L"YaldabaothY_die_Right", true);
			die_Check = false;
		}
	}
}

void Boss_Yaldabaoth::attack1()
{
	//사슬 휘두르기
	m_State = eBoss_YaldabaothState::Attack1;

	if (Direction == 0)
		m_Animator->Play(L"YaldabaothY_attack1_Left", true);
	if (Direction == 1)
		m_Animator->Play(L"YaldabaothY_attack1_Right", true);

}

void Boss_Yaldabaoth::attack2()
{
	//돌진기
	m_State = eBoss_YaldabaothState::Attack2;
	if (Direction == 0)
	{
		m_Animator->Play(L"YaldabaothY_attack2_Left", true);
		SetMoveLeft = true;
	}
	if (Direction == 1)
	{
		m_Animator->Play(L"YaldabaothY_attack2_Right", true);
		SetMoveRight = true;
	}

}

void Boss_Yaldabaoth::Destroy()
{
	Y_Die = true;
	object::Destory(this);
}
