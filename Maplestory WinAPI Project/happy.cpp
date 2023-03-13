#include "happy.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"

happy::happy()
{
}

happy::~happy()
{
}

void happy::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(700.0f, 230.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Mob\\happymob\\move", Vector2::Zero, 0.2f);
	m_Animator->Play(L"happymobmove", true);

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(70, 70)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(0.0f, 0.0f)); // 히트박스 위치 조정

	/*m_State = ehappyState::Idle;*/
	GameObject::Initialize();
}

void happy::Update()
{
	GameObject::Update();

	switch (m_State)
	{
	case happy::ehappyState::Move:
		move();
		break;
	case  happy::ehappyState::Idle:
		idle();
		break;
	default:
		break;
	}
}

void happy::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void happy::Release()
{
	GameObject::Release();
}

void happy::move()
{
}

void happy::idle()
{
	m_State = ehappyState::Idle;
	m_Animator->Play(L"happymobmove", true);
}

void happy::dead()
{
}
