#include "Boss.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"
#include "CircleObj.h"
#include "Object.h"

#include "LeftFullSkill.h"
#include "CenterFullSkill.h"
#include "RightFullSkill.h"
#include "BlackChainSkill.h"


Boss::Boss()
	: m_Time(0.0f)
	, FallTime(0.0f)
	, LoopTime(0.0f)
	, T_Skill1(0.0f)
	, TestTime(0.0f)
	, m_State(eBoss_State::Respawn)
	, attack_pattern(3)
	, Skill1Loop(false)
	, Skill2Loop(false)
	, Skill3Loop(false)
	, Skill4Loop(false)
	, m_Test(false)
	,cnt(0)

{
}

Boss::~Boss()
{
}

void Boss::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(1000.0f, 800.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\BossImg\\stand", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\BossImg\\FullLeft_Skill1", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\BossImg\\FullCenter_Skill2", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\BossImg\\FullRight_Skill3", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\BossImg\\Chain_Skill4", Vector2::Zero, 0.1f);

	m_Animator->GetCompleteEvent(L"BossImgstand") = std::bind(&Boss::idle, this);
	m_Animator->GetCompleteEvent(L"BossImgFullLeft_Skill1") = std::bind(&Boss::idle, this);
	m_Animator->GetCompleteEvent(L"BossImgFullCenter_Skill2") = std::bind(&Boss::idle, this);
	m_Animator->GetCompleteEvent(L"BossImgFullRight_Skill3") = std::bind(&Boss::idle, this);
	m_Animator->GetCompleteEvent(L"BossImgChain_Skill4") = std::bind(&Boss::idle, this);

	circleobj0 = nullptr;
	circleobj1 = nullptr;
	circleobj2 = nullptr;
	circleobj3 = nullptr;
	circleobj4 = nullptr;
	circleobj5 = nullptr;
	circleobj6 = nullptr;
	circleobj7 = nullptr;



	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(300, 580)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-150.0f, -580.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void Boss::Update()
{
	GameObject::Update();

	switch (m_State)
	{
	case Boss::eBoss_State::Pattern:
		pattern();
		break;
	case Boss::eBoss_State::FullLeft_Skill1:
		break;
	case Boss::eBoss_State::FullCenter_Skill2:
		break;
	case Boss::eBoss_State::FullRight_Skill3:
		break;
	case Boss::eBoss_State::Chain_Skill4:
		break;

	default:
		break;
	}
}

void Boss::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(29, 29, 29));
	GameObject::Render(hdc);
}

void Boss::Release()
{
	GameObject::Release();
}

void Boss::respawn()
{
	m_Animator->Play(L"BossImgstand", true);
}

void Boss::pattern()
{
	FallTime += Time::DeltaTime(); //Circle 오브젝트 시간 간격
	T_Skill1 += Time::DeltaTime();
	m_Time += Time::DeltaTime(); // 패턴 시간 간격
	if (m_Time > 10.0f)
	{
		m_Time = 0.0f;
		//attack_pattern = rand() % 4;

		switch (attack_pattern)
		{
		case 0:
			FullLeft_Skill1();
			break;
		case 1:
			FullCenter_Skill2();
			break;
		case 2:
			FullRight_Skill3();
			break;
		case 3:
			Chain_Skill4();
			break;
		default:
			break;
		}
	}
}

void Boss::idle()
{
	Obj_Circle();
	Skill1_Obj();
	Skill2_Obj();
	Skill3_Obj();
	Test();

	Skill1Loop = false;
	Skill2Loop = false;
	Skill3Loop = false;
	Skill4Loop = false;

	m_State = eBoss_State::Pattern;
	m_Animator->Play(L"BossImgstand", true);
}



void Boss::FullLeft_Skill1()
{
	m_State = eBoss_State::FullLeft_Skill1;
	m_Animator->Play(L"BossImgFullLeft_Skill1", true);
	Skill1Loop = true;
}

void Boss::FullCenter_Skill2()
{
	m_State = eBoss_State::FullCenter_Skill2;
	m_Animator->Play(L"BossImgFullCenter_Skill2", true);
	Skill2Loop = true;
}

void Boss::FullRight_Skill3()
{
	m_State = eBoss_State::FullRight_Skill3;
	m_Animator->Play(L"BossImgFullRight_Skill3", true);
	Skill3Loop = true;
}

void Boss::Chain_Skill4()
{
	m_State = eBoss_State::Chain_Skill4;
	m_Animator->Play(L"BossImgChain_Skill4", true);
	Skill4Loop = true;
}

void Boss::Test()
{
	if (Skill4Loop == true)
	{
		TestTime += Time::DeltaTime();

		BS0 = object::Instantiate<BlackChainSkill>(eLayerType::BossObj);
		BS1 = object::Instantiate<BlackChainSkill>(eLayerType::BossObj);
		BS2 = object::Instantiate<BlackChainSkill>(eLayerType::BossObj);
		BS3 = object::Instantiate<BlackChainSkill>(eLayerType::BossObj);
		BS4 = object::Instantiate<BlackChainSkill>(eLayerType::BossObj);
		BS5 = object::Instantiate<BlackChainSkill>(eLayerType::BossObj);

		BS1->GetComponent<Transform>()->SetPos(Vector2(400.0f, 1600.0f));
		BS2->GetComponent<Transform>()->SetPos(Vector2(650.0f, 1600.0f));
		BS3->GetComponent<Transform>()->SetPos(Vector2(900.0f, 1600.0f));
		BS4->GetComponent<Transform>()->SetPos(Vector2(1150.0f, 1600.0f));
		BS5->GetComponent<Transform>()->SetPos(Vector2(1400.0f, 1600.0f));

		BS0->Attack();
		BS1->Attack();
		BS2->Attack();
		BS3->Attack();
		BS4->Attack();
		BS5->Attack();
	}

}

void Boss::Obj_Circle()
{
	if (FallTime > 10.0f)
	{
		LoopTime += Time::DeltaTime();
		circleobj0 = object::Instantiate<CircleObj>(eLayerType::BossObj);
		circleobj1 = object::Instantiate<CircleObj>(eLayerType::BossObj);
		circleobj2 = object::Instantiate<CircleObj>(eLayerType::BossObj);
		circleobj3 = object::Instantiate<CircleObj>(eLayerType::BossObj);
		circleobj4 = object::Instantiate<CircleObj>(eLayerType::BossObj);
		circleobj5 = object::Instantiate<CircleObj>(eLayerType::BossObj);
		circleobj6 = object::Instantiate<CircleObj>(eLayerType::BossObj);
		circleobj7 = object::Instantiate<CircleObj>(eLayerType::BossObj);

		circleobj1->GetComponent<Transform>()->SetPos(Vector2(400.0f, 200.0f));
		circleobj2->GetComponent<Transform>()->SetPos(Vector2(650.0f, 200.0f));
		circleobj3->GetComponent<Transform>()->SetPos(Vector2(900.0f, 200.0f));
		circleobj4->GetComponent<Transform>()->SetPos(Vector2(1150.0f, 200.0f));
		circleobj5->GetComponent<Transform>()->SetPos(Vector2(1400.0f, 200.0f));
		circleobj6->GetComponent<Transform>()->SetPos(Vector2(1650.0f, 200.0f));
		circleobj7->GetComponent<Transform>()->SetPos(Vector2(1900.0f, 200.0f));

		circleobj0->SetFallTiming(1);
		circleobj1->SetFallTiming(2);
		circleobj2->SetFallTiming(3);
		circleobj3->SetFallTiming(4);
		circleobj4->SetFallTiming(5);
		circleobj5->SetFallTiming(6);
		circleobj6->SetFallTiming(7);
		circleobj7->SetFallTiming(8);

		circleobj0->respawn();
		circleobj1->respawn();
		circleobj2->respawn();
		circleobj3->respawn();
		circleobj4->respawn();
		circleobj5->respawn();
		circleobj6->respawn();
		circleobj7->respawn();

		FallTime = 0.0f;
	}
}

void Boss::Skill1_Obj()
{
	if (Skill1Loop == true)
	{
	Skill1 = object::Instantiate<LeftFullSkill>(eLayerType::BossSkill);
	Skill1->P1_Start();
	}
}

void Boss::Skill2_Obj()
{
	if (Skill2Loop == true)
	{
		Skill2 = object::Instantiate<CenterFullSkill>(eLayerType::BossSkill);
		Skill2->P1_Start();
	}
}

void Boss::Skill3_Obj()
{
	if (Skill3Loop == true)
	{
		Skill3 = object::Instantiate<RightFullSkill>(eLayerType::BossSkill);
		Skill3->P1_Start();
	}
}

void Boss::dead()
{

}