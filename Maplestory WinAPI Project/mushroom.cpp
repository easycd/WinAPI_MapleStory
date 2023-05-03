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
#include "Object.h"

#include "BasicSkill.h"
#include "Cosmos.h"
#include "SolunaDivideStart.h"

#include "BsHit.h"

mushroom::mushroom()
	: m_Time(0.0f)
	, Speed(Vector2(50.0f, 0.0f))
	, SetPosX(0.0f)
	, Direction(0)
	, Animation_Check(false)
	, Ground(false)
	, CompleteCnt(0)
	, AnimationLoop(false)
	, Check(false)
	, Check2(false)
	, die_Check(true)
	, Hp(10)
	, m_State(emushroomState::Move)
{
}

mushroom::~mushroom()
{
}

void mushroom::Initialize()
{
	tr = GetComponent<Transform>();
	tr->SetPos(Vector2(800.0f, 600.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\mushroom\\IdleLeft", Vector2::Zero, 0.3f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\mushroom\\IdleRight", Vector2::Zero, 0.3f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\mushroom\\moveLeft", Vector2::Zero, 0.3f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\mushroom\\moveRight", Vector2::Zero, 0.3f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\mushroom\\dieLeft", Vector2::Zero, 0.15f);
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\mushroom\\dieRight", Vector2::Zero, 0.15f);

	m_Animator->GetCompleteEvent(L"mushroomdieLeft") = std::bind(&mushroom::Delete, this);
	m_Animator->GetCompleteEvent(L"mushroomdieRight") = std::bind(&mushroom::Delete, this);

	m_Animator->Play(L"mushroommoveLeft", true);

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(70, 70)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-35.0f, -65.0f)); // 히트박스 위치 조정


	GameObject::Initialize();
}

void mushroom::Update()
{
	GameObject::Update();

	if (Hp == 0)
		death();
	
		//death();

	//몬스터 일정범위 주위에 캐릭터가 있으면 추적하는 로직
	// 오류: 캐릭터 Y값이랑 몬스터 Y값의 오차가 커서 예외처리 불가.
	//if (m_State == emushroomState::Move)
	//{
	//MainChar* player = SceneManager::GetPlayer();
	//Vector2 playerPos = player->GetComponent<Transform>()->GetPos();
	//Vector2 playerX = Vector2(playerPos.x, 0.0f);
	//Vector2 playerY = Vector2(0.0, playerPos.y);
	//
	//Vector2 mobX = Vector2(tr->GetPos().x, 0.0f);
	//Vector2 mobY = Vector2(0.0f, tr->GetPos().y);
	//
	//Vector2 dr = math::Direction(mobX, playerX);
	//float disX = fabs(playerX.x - mobX.x);
	//float disY = fabs(playerY.y - mobY.y);
	// 
	//if(disX < 50.0f && disY < 145.0f && disY > 50)
	//{
	//	tr->AddPos(dr * Speed * Time::DeltaTime());
	//	if (dr.x > 0.0f)
	//	{
	//		Direction = 1;
	//	}
	//	else
	//	{
	//		Direction = 0;
	//	}
	//}
	//
	//}

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

void mushroom::OnCollisionStay(Collider* other)
{
	Cosmos* cosmos = dynamic_cast<Cosmos*>(other->GetOwner());
	if (cosmos != nullptr)
	{
		Hp -= 10;
	}
	SolunaDivideStart * divide = dynamic_cast<SolunaDivideStart*>(other->GetOwner());
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

void mushroom::move()
{
	m_State = emushroomState::Move;
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

	tr->SetPos(pos);
}

void mushroom::idle()
{
}

void mushroom::death()
{
	m_State = emushroomState::Death;

	if (Direction == 0)
	{
		if (die_Check == true)
		{
			m_Animator->Play(L"mushroomdieLeft", true);
			die_Check = false;
		}
	
	}
	else if (Direction == 1)
	{
		if (die_Check == true)
		{
			m_Animator->Play(L"mushroomdieRight", true);
			die_Check = false;
		}
	}
}

void mushroom::Delete()
{
	object::Destory(this);
}


