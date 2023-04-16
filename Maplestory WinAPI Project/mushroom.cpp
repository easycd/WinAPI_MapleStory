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
	: m_Time(0.0f)
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
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\mushroom\\moveLeft", Vector2::Zero, 0.3f);
	m_Animator->Play(L"mushroommoveLeft", true);
	//m_State = emushroomState::Idle;

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(70, 70)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-35.0f, -65.0f)); // 히트박스 위치 조정

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
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	m_Time += Time::DeltaTime();
	float Setpos = pos.x;
	if(m_Time < 3.f)
	pos.x -= 100.0 * Time::DeltaTime();
	if (m_Time > 3.f)
		pos.x += 100.0 * Time::DeltaTime();

	tr->SetPos(pos);
}

void mushroom::idle()
{
	m_State = emushroomState::Idle;
	m_Animator->Play(L"mushroommove", true);
}

void mushroom::dead()
{
}

