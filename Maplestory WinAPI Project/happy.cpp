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

happy::happy()
	: m_Time(0.0f)
	, SetPosX(0.0f)
	, Direction(0)
	, Animation_Check(false)
	, Ground(false)
{
}

happy::~happy()
{
}

void happy::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(900.0f, 460.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\happymob\\moveLeft", Vector2::Zero, 0.2f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\happymob\\moveRight", Vector2::Zero, 0.2f);
	m_Animator->Play(L"happymobmoveLeft", true);

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(100, 200)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-45.0f, -200.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void happy::Update()
{
	GameObject::Update();

	switch (m_State)
	{
	case happy::ehappyState::Move:
		move();
		break;
	case  happy::ehappyState::Idle:
		idle();
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
}
