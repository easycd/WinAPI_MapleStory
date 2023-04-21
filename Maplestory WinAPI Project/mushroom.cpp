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
#include "MainChar.h"

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
	, Check2(false)
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
	m_State = emushroomState::Move;
	m_Animator->Play(L"mushroommoveLeft", false);




	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(70, 70)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-35.0f, -65.0f)); // 히트박스 위치 조정


	GameObject::Initialize();
}

void mushroom::Update()
{
	GameObject::Update();


	Pattern = rand() % 2; // 0 ~ 1 랜덤 숫자 


	switch (m_State)
	{
	case mushroom::emushroomState::Move:
		move();
		break;
	case mushroom::emushroomState::Death:
		death();
		break;
	case mushroom::emushroomState::Idle:
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
			m_Animator->Play(L"mushroommoveLeft", true);
			Animation_Check = false;
		}
		
		pos.x -= 80.0 * Time::DeltaTime();
	}
	else if (Direction == 1)
	{
		if(Animation_Check == false)
		{
			m_Animator->Play(L"mushroommoveRight", true);
			Animation_Check = true;
		}
		
		pos.x += 80.0 * Time::DeltaTime();
	}

	//ChPos = Ch->GetComponent<Transform>()->GetPos(); 캐릭터 위치 가져오는건데 안됨.
	tr->SetPos(pos);
}

void mushroom::idle()
{
}

void mushroom::death()
{
}

