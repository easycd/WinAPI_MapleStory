#include "RedSnail.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"

RedSnail::RedSnail()
{
}

RedSnail::~RedSnail()
{
}

void RedSnail::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(900.0f, 550.0f));

	

	m_Animator = AddComponent<Animator>();

	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\redsnail\\move", Vector2::Zero, 0.6f);
	m_Animator->Play(L"redsnailmove", true);

	/*m_State = eRedSnailState::Idle;*/
	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(40, 40)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-20.0f, -40.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void RedSnail::Update()
{
	GameObject::Update();

	switch (m_State)
	{
	case RedSnail::eRedSnailState::Move:
		move();
		break;
	case  RedSnail::eRedSnailState::Idle:
		idle();
		break;
	default:
		break;
	}
}

void RedSnail::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void RedSnail::Release()
{
	GameObject::Release();
}

void RedSnail::move()
{
}

void RedSnail::idle()
{
		m_State = eRedSnailState::Idle;
		m_Animator->Play(L"redsnailmove", true);
}
