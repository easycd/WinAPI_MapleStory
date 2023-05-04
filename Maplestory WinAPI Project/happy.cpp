#include "happy.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"
#include "WallColliderLeft.h"
#include "WallColliderRight.h"
#include "Object.h"

#include "BasicSkill.h"
#include "Cosmos.h"
#include "SolunaDivideStart.h"

happy::happy()
	: m_Time(0.0f)
	, SetPosX(0.0f)
	, Direction(0)
	, Animation_Check(false)
	, Ground(false)
	, Hp(10)
	, die_Check(true)
{
}

happy::~happy()
{
}

void happy::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(900.0f, 500.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\happymob\\moveLeft", Vector2::Zero, 0.2f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\happymob\\moveRight", Vector2::Zero, 0.2f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\happymob\\die_Left", Vector2::Zero, 0.2f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\happymob\\die_Right", Vector2::Zero, 0.2f);

	m_Animator->GetCompleteEvent(L"happymobdie_Right") = std::bind(&happy::Delete, this);
	m_Animator->GetCompleteEvent(L"happymobdie_Left") = std::bind(&happy::Delete, this);

	m_Animator->Play(L"happymobmoveLeft", true);

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(100, 200)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-50.0f, -440.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void happy::Update()
{
	GameObject::Update();
	
	if (Hp == 0)
		m_State = happy::ehappyState::Die;


	switch (m_State)
	{
	case happy::ehappyState::Move:
		move();
		break;
	case  happy::ehappyState::Idle:
		idle();
		break;
	case  happy::ehappyState::Die:
		dead();
		break;
	default:
		break;
	}
}

void happy::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void happy::Release()
{
	GameObject::Release();
}

void happy::OnCollisionEnter(Collider* other)
{
	WallColliderLeft* wallcolliderLeft = dynamic_cast<WallColliderLeft*>(other->GetOwner());
	WallColliderRight* wallcolliderRight = dynamic_cast<WallColliderRight*>(other->GetOwner());
	if (wallcolliderLeft != nullptr)
	{
		if (Direction == 0)
		{
			Direction = 1;
		}
	}
	if (wallcolliderRight != nullptr)
	{
		if (Direction == 1)
		{
			Direction = 0;
		}
	}

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
}

void happy::OnCollisionStay(Collider* other)
{
	Cosmos* cosmos = dynamic_cast<Cosmos*>(other->GetOwner());
	if (cosmos != nullptr)
	{
		Hp -= 10;
	}
	SolunaDivideStart* divide = dynamic_cast<SolunaDivideStart*>(other->GetOwner());
	if (divide != nullptr)
	{
		Hp -= 10;
	}
	BasicSkill* bs = dynamic_cast<BasicSkill*>(other->GetOwner());
	if (bs != nullptr)
	{
		//bshit = object::Instantiate<BsHit>(eLayerType::Skill_hit);
		//bshit->Hit();
		Hp -= 10;
	}
}

void happy::move()
{
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	m_Time += Time::DeltaTime();

	if (Direction == 0)
	{
		if (Animation_Check)
		{
			m_Animator->Play(L"happymobmoveLeft", true);
			Animation_Check = false;
		}

		pos.x -= 60.0 * Time::DeltaTime();
	}
	else if (Direction == 1)
	{
		if (Animation_Check == false)
		{
			m_Animator->Play(L"happymobmoveRight", true);
			Animation_Check = true;
		}

		pos.x += 60.0 * Time::DeltaTime();
	}
	tr->SetPos(pos);
}

void happy::idle()
{
	m_State = ehappyState::Idle;
	m_Animator->Play(L"happymobmove", true);
}

void happy::dead()
{
	if (Direction == 0)
	{
		if (die_Check)
		{
			m_Animator->Play(L"happymobdie_Left", true);
			die_Check = false;
		}

	}
	else if (Direction == 1)
	{
		if (die_Check)
		{
			m_Animator->Play(L"happymobdie_Right", true);
			die_Check = false;
		}
	}
}

void happy::Delete()
{
	object::Destory(this);
}
