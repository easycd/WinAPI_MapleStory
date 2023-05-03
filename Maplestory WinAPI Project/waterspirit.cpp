#include "waterspirit.h"
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

waterspirit::waterspirit()
	: m_Time(0.0f)
	, SetPosX(0.0f)
	, Direction(0)
	, Animation_Check(false)
	, Ground(false)
	, die_Check(true)
	, Hp(10)
{
}

waterspirit::~waterspirit()
{
}

void waterspirit::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(900.0f, 605.0f));

	m_Animator = AddComponent<Animator>();

	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\waterspirit\\moveLeft", Vector2::Zero, 0.2f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\waterspirit\\moveRight", Vector2::Zero, 0.2f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\waterspirit\\dieRight", Vector2::Zero, 0.13f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\waterspirit\\dieLeft", Vector2::Zero, 0.13f);

	m_Animator->GetCompleteEvent(L"waterspiritdieRight") = std::bind(&waterspirit::Delete, this);
	m_Animator->GetCompleteEvent(L"waterspiritdieLeft") = std::bind(&waterspirit::Delete, this);

	m_Animator->Play(L"waterspiritmoveLeft", true);

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(120, 160)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-65.0f, -380.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void waterspirit::Update()
{
	GameObject::Update();

	if (Hp == 0)
		dead();

	switch (m_State)
	{
	case waterspirit::ewaterspiritState::Move:
		move();
		break;
	case  waterspirit::ewaterspiritState::Idle:
		idle();
		break;
	case  waterspirit::ewaterspiritState::Death:
		dead();
		break;
	default:
		break;
	}
}

void waterspirit::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void waterspirit::Release()
{
	GameObject::Release();
}

void waterspirit::OnCollisionEnter(Collider* other)
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

void waterspirit::OnCollisionStay(Collider* other)
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

void waterspirit::move()
{
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	m_Time += Time::DeltaTime();

	if (Direction == 0)
	{
		if (Animation_Check)
		{
			m_Animator->Play(L"waterspiritmoveLeft", true);
			Animation_Check = false;
		}
	
		pos.x -= 60.0 * Time::DeltaTime();
	}
	else if (Direction == 1)
	{
		if (Animation_Check == false)
		{
			m_Animator->Play(L"waterspiritmoveRight", true);
			Animation_Check = true;
		}
	
		pos.x += 60.0 * Time::DeltaTime();
	}
	tr->SetPos(pos);
}

void waterspirit::idle()
{
	m_State = ewaterspiritState::Idle;
	m_Animator->Play(L"waterspiritmove", true);
}

void waterspirit::dead()
{
	m_State = ewaterspiritState::Death;

	if (Direction == 0)
	{
		if (die_Check == true)
		{
			m_Animator->Play(L"waterspiritdieLeft", true);
			die_Check = false;
		}

	}
	else if (Direction == 1)
	{
		if (die_Check == true)
		{
			m_Animator->Play(L"waterspiritdieRight", true);
			die_Check = false;
		}
	}
}

void waterspirit::Delete()
{
	object::Destory(this);
}