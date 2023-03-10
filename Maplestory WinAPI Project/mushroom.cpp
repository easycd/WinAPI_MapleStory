#include "mushroom.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"

mushroom::mushroom()
{
}

mushroom::~mushroom()
{
}

void mushroom::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(700.0f, 482.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\mushroom\\move", Vector2::Zero, 0.4f);

	m_State = emushroomState::Idle;

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(70, 70)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(0.0f, 0.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void mushroom::Update()
{
	GameObject::Update();

	switch (m_State)
	{
	case mushroom::emushroomState::Move:
		move();
		break;
	case  mushroom::emushroomState::Idle:
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

void mushroom::move()
{
}

void mushroom::idle()
{
	m_State = emushroomState::Idle;
	m_Animator->Play(L"mushroommove", true);
}

void mushroom::dead()
{
}
