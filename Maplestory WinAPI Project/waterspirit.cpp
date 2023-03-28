#include "waterspirit.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"

waterspirit::waterspirit()
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

	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\waterspirit\\move", Vector2::Zero, 0.2f);
	m_Animator->Play(L"waterspiritmove", true);

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

void waterspirit::move()
{
}

void waterspirit::idle()
{
	m_State = ewaterspiritState::Idle;
	m_Animator->Play(L"waterspiritmove", true);
}
