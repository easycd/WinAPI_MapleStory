#include "MainChar.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"

MainChar::MainChar()
{
}

MainChar::~MainChar()
{
}

void MainChar::Initialize()
{
	m_Animator = AddComponent<Animator>();

	m_Animator->CreateAnimations(L"..\\Resources\\Char\\IdleLeft", Vector2::Zero, 0.8f);

	m_Animator->CreateAnimations(L"..\\Resources\\Char\\IdleRight", Vector2::Zero, 0.6f);

	m_Animator->CreateAnimations(L"..\\Resources\\Char\\moveLeft", Vector2::Zero, 0.3f);

	m_Animator->CreateAnimations(L"..\\Resources\\Char\\moveRight", Vector2::Zero, 0.3f);

	/*m_Animator->GetStartEvent(L"CharIdleRight") = std::bind(&MainChar::idleCompleteEvent, this);*/
	m_Animator->Play(L"CharIdleRight", true);

	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(125.0f, 5.0f));

	/*m_State = eMainCharState::Idle;*/
	GameObject::Initialize();
}

void MainChar::Update()
{
	GameObject::Update();

	switch (m_State)
	{
	case MainChar::eMainCharState::Move:
		move();
		break;
	case  MainChar::eMainCharState::Idle:
		idle();
		break;
	default:
		break;
	}
}

void MainChar::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void MainChar::Release()
{
	GameObject::Release();
}

void MainChar::move()
{
	/*if (Input::GetKeyUp(eKeyCode::A)
		|| Input::GetKeyUp(eKeyCode::D)
		|| Input::GetKeyUp(eKeyCode::S)
		|| Input::GetKeyUp(eKeyCode::W))
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleRight", true);
	}*/
	if (Input::GetKeyUp(eKeyCode::A))
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleLeft", true);
	}
	else if (Input::GetKeyUp(eKeyCode::D))
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleRight", true);
	}
	else if (Input::GetKeyUp(eKeyCode::W))
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleRight", true);
	}
	else if (Input::GetKeyUp(eKeyCode::S))
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleRight", true);
	}

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	if (Input::GetKey(eKeyCode::A))
		pos.x -= 150.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::D))
		pos.x += 150.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::W))
		pos.y -= 150.0f * Time::DeltaTime();

	if (Input::GetKey(eKeyCode::S))
		pos.y += 150.0f * Time::DeltaTime();

	tr->SetPos(pos);
}

void MainChar::idle()
{
	if (Input::GetKeyDown(eKeyCode::A)
		|| Input::GetKeyDown(eKeyCode::D)
		|| Input::GetKeyDown(eKeyCode::S)
		|| Input::GetKeyDown(eKeyCode::W))
	{
		m_State = eMainCharState::Move;
		m_Animator->Play(L"CharmoveRight", true);
	}
	if (Input::GetKeyDown(eKeyCode::A))
	{
		m_State = eMainCharState::Move;
		m_Animator->Play(L"CharmoveLeft", true);
	}
	else if (Input::GetKeyDown(eKeyCode::D))
	{
		m_State = eMainCharState::Move;
		m_Animator->Play(L"CharmoveRight", true);
	}
	else if (Input::GetKeyDown(eKeyCode::W))
	{
		m_State = eMainCharState::Move;
		m_Animator->Play(L"CharmoveRight", true);
	}
	else if (Input::GetKeyDown(eKeyCode::S))
	{
		m_State = eMainCharState::Move;
		m_Animator->Play(L"CharmoveRight", true);
	}
	
}

void MainChar::attack()
{

}

//애니메이션 1번 끝났을떄 호출되는 함수
void MainChar::idleCompleteEvent(/*const Cuphead* this*/)
{
	int a = 0;
	//mState =
	//Transform* tr = GetComponent<Transform>();
	//Scene* curScene = SceneManager::GetActiveScene();
	//BaseBullet* bullet = new BaseBullet();
	//bullet->GetComponent<Transform>()->SetPos(tr->GetPos());
	//curScene->AddGameObeject(bullet, eLayerType::Bullet);
}