#include "MainChar.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"
#include "BasicSkill.h"
#include "Rigidbody.h"

MainChar::MainChar()
{
}

MainChar::~MainChar()
{
}

void MainChar::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(300.0f, 300.0f));
	m_Animator = AddComponent<Animator>();

	m_Animator->CreateAnimations(L"..\\Resources\\Char\\IdleLeft", Vector2::Zero, 0.8f); //왼쪽 아이들
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\IdleRight", Vector2::Zero, 0.6f); // 오른쪽 아이들
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\moveLeft", Vector2::Zero, 0.3f); // 왼쪽 걷기
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\moveRight", Vector2::Zero, 0.3f); // 오른쪽 걷기
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\attackLeft", Vector2::Zero, 0.2f); // 왼쪽 공격모션
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\attackRight", Vector2::Zero, 0.2f); // 오른쪽 공격모션
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\jumpLeft", Vector2::Zero, 0.2f); // 왼쪽 점프
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\jumpRight", Vector2::Zero, 0.2f); // 오른쪽 점프
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\DownLeft", Vector2::Zero, 0.2f); // 왼쪽 눕기
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\DownRight", Vector2::Zero, 0.2f); // 오른쪽 눕기
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\DownAttackLeft", Vector2::Zero, 0.2f); // 왼쪽 아래 공격
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\DownAttackRight", Vector2::Zero, 0.2f); // 오른쪽 아래 공격


	/*m_Animator->GetStartEvent(L"CharIdleRight") = std::bind(&MainChar::idleCompleteEvent, this);*/
	m_Animator->Play(L"CharIdleRight", true);
	direction = 1;

	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-30.0f, -220.0f));

	mRigidbody = AddComponent<Rigidbody>();
	mRigidbody->SetMass(1.0f);

	m_State = eMainCharState::Idle;
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
	case  MainChar::eMainCharState::Attack:
		basic_attack();
		break;
	case  MainChar::eMainCharState::Jump:
		jump();
		break;
	case  MainChar::eMainCharState::Down:
		down();
		break;
	case  MainChar::eMainCharState::DownAttack:
		downattack();
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
	if (Input::GetKeyUp(eKeyCode::LEFT))
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleLeft", true);
		direction = 0;
	}
	else if (Input::GetKeyUp(eKeyCode::RIGHT))
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleRight", true);
		direction = 1;
	}
	else if (Input::GetKeyUp(eKeyCode::UP))
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleRight", true);
	}
	else if (direction == 0 && Input::GetKeyDown(eKeyCode::DOWN))
	{
		m_State = eMainCharState::Down;
		m_Animator->Play(L"CharDownLeft", true);
		direction == 0;
	}
	else if (direction == 1 && Input::GetKeyDown(eKeyCode::DOWN))
	{
		m_State = eMainCharState::Down;
		m_Animator->Play(L"CharDownRight", true);
		direction == 1;
	}
	else if (direction == 1 && Input::GetKeyDown(eKeyCode::F))
	{
		m_State = eMainCharState::Attack;
		m_Animator->Play(L"CharattackRight", true);
	}
	else if (direction == 0 && Input::GetKeyDown(eKeyCode::F))
	{
		m_State = eMainCharState::Attack;
		m_Animator->Play(L"CharattackLeft", true);
	}
	else if (direction == 0 && Input::GetKeyDown(eKeyCode::SPACE))
	{
		m_Animator->Play(L"CharjumpLeft", true);
		Vector2 velocity = mRigidbody->GetVelocity();
		velocity.y -= 500.0f;

		mRigidbody->SetVelocity(velocity);
		mRigidbody->SetGround(false);
	}
	else if (direction == 1 && Input::GetKeyDown(eKeyCode::SPACE))
	{
		m_Animator->Play(L"CharjumpRight", true);
		Vector2 velocity = mRigidbody->GetVelocity();
		velocity.y -= 500.0f;

		mRigidbody->SetVelocity(velocity);
		mRigidbody->SetGround(false);
	}

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();


	if (Input::GetKey(eKeyCode::LEFT))
	{
		//mRigidbody->AddForce(Vector2(-200.0f, 0.0f));
		direction = 0;
		pos.x -= 200.0 * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::RIGHT))
	{
		//mRigidbody->AddForce(Vector2(200.0f, 0.0f));
		direction = 1;
		pos.x += 200.0 * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::UP))
	{
		//mRigidbody->AddForce(Vector2(0.0f, -200.0f));
		//pos.y -= 200.0 * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::DOWN))
	{
		//mRigidbody->AddForce(Vector2(0.0f, +200.0f));
		//pos.y += 200.0 * Time::DeltaTime();
	}

	tr->SetPos(pos);
}

void MainChar::idle()
{
	if (Input::GetKeyDown(eKeyCode::LEFT))
	{
		m_State = eMainCharState::Move;
		m_Animator->Play(L"CharmoveLeft", true);
		direction = 0;
	}
	else if (Input::GetKeyDown(eKeyCode::RIGHT))
	{
		m_State = eMainCharState::Move;
		m_Animator->Play(L"CharmoveRight", true);
		direction = 1;
	}
	else if (Input::GetKeyDown(eKeyCode::UP))
	{
		m_State = eMainCharState::Move;
		m_Animator->Play(L"CharmoveRight", true);
	}
	else if (direction == 0 && Input::GetKeyDown(eKeyCode::DOWN))
	{
		m_State = eMainCharState::Down;
		m_Animator->Play(L"CharDownLeft", true);
		direction == 0;
	}
	else if (direction == 1 && Input::GetKeyDown(eKeyCode::DOWN))
	{
		m_State = eMainCharState::Down;
		m_Animator->Play(L"CharDownRight", true);
		direction == 1;
	}
	else if (Input::GetKeyDown(eKeyCode::F) && direction == 1)
	{
		m_State = eMainCharState::Attack;
		m_Animator->Play(L"CharattackRight", true);
		direction == 1;
	}
	else if (Input::GetKeyDown(eKeyCode::F) && direction == 0)
	{
		m_State = eMainCharState::Attack;
		m_Animator->Play(L"CharattackLeft", true);
		direction == 0;
	}
	else if (direction == 0 && Input::GetKeyDown(eKeyCode::SPACE))
	{
		m_Animator->Play(L"CharjumpLeft", true);
		Vector2 velocity = mRigidbody->GetVelocity();
		velocity.y -= 500.0f;

		mRigidbody->SetVelocity(velocity);
		mRigidbody->SetGround(false);
	}
	else if (direction == 1 && Input::GetKeyDown(eKeyCode::SPACE))
	{
		m_Animator->Play(L"CharjumpRight", true);
		Vector2 velocity = mRigidbody->GetVelocity();
		velocity.y -= 500.0f;

		mRigidbody->SetVelocity(velocity);
		mRigidbody->SetGround(false);
	}
	
}

void MainChar::jump()
{
	if (direction == 0 && Input::GetKeyUp(eKeyCode::SPACE))
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleLeft", true);
		direction = 0;
	}
	else if (direction == 1 && Input::GetKeyUp(eKeyCode::SPACE))
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleRight", true);
		direction = 1;
	}
}

void MainChar::basic_attack()
{
	Transform* tr = GetComponent<Transform>();
	if (Input::GetKey(eKeyCode::F))
	{
		Scene* curScene = SceneManager::GetActiveScene();
		BasicSkill* basicskill = new BasicSkill();
		basicskill->RightAttack();
		basicskill->GetComponent<Transform>()->SetPos(tr->GetPos());
		curScene->AddGameObeject(basicskill, eLayerType::Skill);

	}
	else if (Input::GetKeyUp(eKeyCode::F) && direction == 0)
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleLeft", true);
	}
	else if (Input::GetKeyUp(eKeyCode::F) && direction == 1)
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleRight", true);
	}

	
}

void MainChar::down()
{
	if (Input::GetKeyUp(eKeyCode::DOWN) && direction == 1)
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleRight", true);
	}
	else if (Input::GetKeyUp(eKeyCode::DOWN) && direction == 0)
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleLeft", true);
	}
	else if (Input::GetKeyDown(eKeyCode::LEFT))
	{
		m_State = eMainCharState::Move;
		m_Animator->Play(L"CharmoveLeft", true);
		direction = 0;
	}
	else if (Input::GetKeyDown(eKeyCode::RIGHT))
	{
		m_State = eMainCharState::Move;
		m_Animator->Play(L"CharmoveRight", true);
		direction = 1;
	}
	else if (direction == 0 && Input::GetKey(eKeyCode::F))
	{
		m_State = eMainCharState::DownAttack;
		m_Animator->Play(L"CharDownAttackLeft", true);
		direction == 0;
	}
	else if (direction == 1 && Input::GetKey(eKeyCode::F))
	{
		m_State = eMainCharState::DownAttack;
		m_Animator->Play(L"CharDownAttackRight", true);
		direction == 1;
	}
}

void MainChar::downattack()
{
	if (Input::GetKeyUp(eKeyCode::DOWN) && direction == 1)
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleRight", true);
	}
	else if (Input::GetKeyUp(eKeyCode::DOWN) && direction == 0)
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleLeft", true);
	}
	else if (direction == 0 && Input::GetKeyUp(eKeyCode::F))
	{
		m_State = eMainCharState::Down;
		m_Animator->Play(L"CharDownLeft", true);
		direction == 0;
	}
	else if (direction == 1 && Input::GetKeyUp(eKeyCode::F))
	{
		m_State = eMainCharState::Down;
		m_Animator->Play(L"CharDownRight", true);
		direction == 1;
	}
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