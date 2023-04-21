#include "Boss.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"

Boss::Boss()
	: m_Time(0.0f)
	, m_State(eBoss_State::Respawn)
	, attack_pattern(0)
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
	default:
		break;
	}
}

void Boss::Render(HDC hdc)
{
	//m_Animator->SetRGB(RGB(29, 29, 29));
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
	m_Time += Time::DeltaTime();
	if (m_Time > 5.0f)
	{
		m_Time = 0.0f;
		attack_pattern = rand() % 4;

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
	m_State = eBoss_State::Pattern;
	m_Animator->Play(L"BossImgstand", true);
}



void Boss::FullLeft_Skill1()
{
	m_State = eBoss_State::FullLeft_Skill1;
	m_Animator->Play(L"BossImgFullLeft_Skill1", true);
}

void Boss::FullCenter_Skill2()
{
	m_State = eBoss_State::FullCenter_Skill2;
	m_Animator->Play(L"BossImgFullCenter_Skill2", true);
}

void Boss::FullRight_Skill3()
{
	m_State = eBoss_State::FullRight_Skill3;
	m_Animator->Play(L"BossImgFullRight_Skill3", true);
}

void Boss::Chain_Skill4()
{
	m_State = eBoss_State::Chain_Skill4;
	m_Animator->Play(L"BossImgChain_Skill4", true);
}

void Boss::dead()
{

}