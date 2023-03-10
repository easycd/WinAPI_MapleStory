#include "Boss_Ion.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"

Boss_Ion::Boss_Ion()
{
}

Boss_Ion::~Boss_Ion()
{
}

void Boss_Ion::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(700.0f, 230.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\stand", Vector2::Zero, 0.1f);

	m_State = eBoss_IonState::Idle;

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(70, 70)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(0.0f, 0.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void Boss_Ion::Update()
{
	GameObject::Update();

	switch (m_State)
	{
	case Boss_Ion::eBoss_IonState::Move:
		move();
		break;
	case  Boss_Ion::eBoss_IonState::Idle:
		idle();
		break;
	default:
		break;
	}
}

void Boss_Ion::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Boss_Ion::Release()
{
	GameObject::Release();
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
}
