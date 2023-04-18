#include "mushroom.h"
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
#include "Rigidbody.h"

mushroom::mushroom()
	: m_Time(0.0f)
	, SetPosX(0.0f)
	, Direction(0)
	, Animation_Check(false)
	, Ground(false)
	, Pattern(0)
	, CompleteCnt(0)
	, AnimationLoop(false)
	, Check(false)
{
}

mushroom::~mushroom()
{
}

void mushroom::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(800.0f, 600.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\mushroom\\IdleLeft", Vector2::Zero, 0.3f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\mushroom\\IdleRight", Vector2::Zero, 0.3f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\mushroom\\moveLeft", Vector2::Zero, 0.3f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\mushroom\\moveRight", Vector2::Zero, 0.3f);
	m_Animator->Play(L"mushroommoveLeft", false);


	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(70, 70)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-35.0f, -65.0f)); // 히트박스 위치 조정

	//mRigidbody = AddComponent<Rigidbody>();
	//mRigidbody->SetMass(1.0f);


	GameObject::Initialize();

	//Vector2 velocity = mRigidbody->GetVelocity();
	//velocity.y -= 500.0f;
	//mRigidbody->SetVelocity(velocity);
	//mRigidbody->SetGround(false);
}

void mushroom::Update()
{
	GameObject::Update();



	if (m_Animator->IsComplte() == true && !Check)
	{
 		CompleteCnt++;
		Check = true;
	}

	Check = false;

	if (CompleteCnt == 3)
	{
		Pattern = rand() % 10; // 0 ~ 5개 랜덤 숫자 
		CompleteCnt = 0;
	}

	switch (Pattern)
	{
	case 0:
		move();
		break;
	case  1:
		idle();
		break;
	case  2:
		move();
		break;
	case  3:
		idle();
		break;
	case  4:
		move();
		break;
	case  5:
		idle();
		break;
	case  6:
		move();
		break;
	case  7:
		idle();
		break;
	case  8:
		move();
		break;
	case  9:
		idle();
		break;
	default:
		break;
	}
}

void mushroom::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void mushroom::Release()
{
	GameObject::Release();
}

void mushroom::OnCollisionEnter(Collider* other)
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

void mushroom::move()
{
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	AnimationLoop = false;

	if (Direction == 0)
	{
		if(Animation_Check)
		{
			m_Animator->Play(L"mushroommoveLeft", false);
			Animation_Check = false;
		}
		
		pos.x -= 80.0 * Time::DeltaTime();
	}
	else if (Direction == 1)
	{
		if(Animation_Check == false)
		{
			m_Animator->Play(L"mushroommoveRight", false);
			Animation_Check = true;
		}
		
		pos.x += 80.0 * Time::DeltaTime();
	}
	tr->SetPos(pos);
}

void mushroom::idle()
{
	if (AnimationLoop == false)
	{
	m_Animator->Play(L"mushroomIdleLeft", false);
	AnimationLoop = true;
	}
}

void mushroom::dead()
{
}

