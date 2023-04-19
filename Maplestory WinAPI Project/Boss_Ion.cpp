#include "Boss_Ion.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"
#include "BossIon_Attack1.h"

Boss_Ion::Boss_Ion()
{
}

Boss_Ion::~Boss_Ion()
{
}

void Boss_Ion::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(1000.0f, 800.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\respawn", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\stand", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\die", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\attack1", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\attack2", Vector2::Zero, 0.1f);
	m_Animator->Play(L"Ionattack2", true);

	m_State = eBoss_IonState::Attack1;

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(300, 580)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-150.0f, -580.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void Boss_Ion::Update()
{
	GameObject::Update();
	//if (m_State == Boss_Ion::eBoss_IonState::Respawn)
	//{
	//	respawn();
	//}
	switch (m_State)
	{
	case Boss_Ion::eBoss_IonState::Respawn:
		respawn();
		break;
	case Boss_Ion::eBoss_IonState::Move:
		move();
		break;
	case  Boss_Ion::eBoss_IonState::Idle:
		idle();
		break;
	case  Boss_Ion::eBoss_IonState::Attack1:
		attack1();
		break;
	case  Boss_Ion::eBoss_IonState::Attack2:
		attack2();
		break;
	default:
		break;
	}
}

void Boss_Ion::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(255, 255, 255));
	GameObject::Render(hdc);
}

void Boss_Ion::Release()
{
	GameObject::Release();
}

void Boss_Ion::respawn()
{
	m_State = eBoss_IonState::Respawn;
	m_Animator->Play(L"Ionrespawn", true);
}

void Boss_Ion::move()
{
}

void Boss_Ion::idle()
{
	m_State = eBoss_IonState::Idle;
	m_Animator->Play(L"Ionstand", true);
}

void Boss_Ion::dead()
{
	m_State = eBoss_IonState::Death;
	m_Animator->Play(L"Iondie", true);
}

void Boss_Ion::attack1()
{
	//m_State = eBoss_IonState::Attack1;
	//m_Animator->Play(L"Ionattack1", true);
	BossIon_Attack1* at1 = new BossIon_Attack1();
	at1->Initialize();
}

void Boss_Ion::attack2()
{
	m_State = eBoss_IonState::Attack2;
	m_Animator->Play(L"Ionattack2", true);
}
