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

waterspirit::waterspirit()
	: m_Time(0.0f)
	, SetPosX(0.0f)
	, Direction(0)
	, Animation_Check(false)
	, Ground(false)
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
	m_Animator->Play(L"waterspiritmoveLeft", true);

	/*m_State = ewaterspiritState::Idle;*/
	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(120, 160)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-65.0f, -155.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void waterspirit::Update()
{
	GameObject::Update();

	switch (m_State)
	{
	case waterspirit::ewaterspiritState::Move:
		move();
		break;
	case  waterspirit::ewaterspiritState::Idle:
		idle();
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
}
