#include "Boss_Yaldabaoth.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"

Boss_Yaldabaoth::Boss_Yaldabaoth()
{
}

Boss_Yaldabaoth::~Boss_Yaldabaoth()
{
}

void Boss_Yaldabaoth::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(300.0f, 230.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Yaldabaoth\\stand", Vector2::Zero, 0.1f);

	m_State = eBoss_YaldabaothState::Idle;

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(70, 70)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(0.0f, 0.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void Boss_Yaldabaoth::Update()
{
	GameObject::Update();

	switch (m_State)
	{
	case Boss_Yaldabaoth::eBoss_YaldabaothState::Move:
		move();
		break;
	case  Boss_Yaldabaoth::eBoss_YaldabaothState::Idle:
		idle();
		break;
	default:
		break;
	}
}

void Boss_Yaldabaoth::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Boss_Yaldabaoth::Release()
{
	GameObject::Release();
}

void Boss_Yaldabaoth::move()
{
}

void Boss_Yaldabaoth::idle()
{
	m_State = eBoss_YaldabaothState::Idle;
	m_Animator->Play(L"Yaldabaothstand", true);
}

void Boss_Yaldabaoth::dead()
{
}
