#include "MainChar.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "CollisionManager.h"
#include "BasicSkill.h"
#include "Cosmos.h"
#include "SoulEclipseStart.h"
#include "SoulEclipseBackGround.h"
#include "SoulEclipseEffect.h"
#include "SolunaDivideStart.h"
#include "SolunaDivideBG.h"

#include "Camera.h"
#include "HenesysBack.h"
#include "Portal.h"
#include "MainChar_GroundCollider.h"

MainChar::MainChar()
	: posx(0)
	, posy(0)
	, m_PortalState(false)
{
}

MainChar::~MainChar()
{
}

void MainChar::Initialize()
{
	tr = GetComponent<Transform>();
	m_Animator = AddComponent<Animator>();

	m_Animator->CreateAnimations(L"..\\Resources\\Char\\IdleLeft", Vector2::Zero, 0.8f); //왼쪽 아이들
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\IdleRight", Vector2::Zero, 0.6f); // 오른쪽 아이들
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\moveLeft", Vector2::Zero, 0.3f); // 왼쪽 걷기
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\moveRight", Vector2::Zero, 0.3f); // 오른쪽 걷기
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\attackLeft", Vector2::Zero, 0.18f); // 왼쪽 공격모션
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\attackRight", Vector2::Zero, 0.18f); // 오른쪽 공격모션
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\jumpLeft", Vector2::Zero, 0.2f); // 왼쪽 점프
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\jumpRight", Vector2::Zero, 0.2f); // 오른쪽 점프
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\DownLeft", Vector2::Zero, 0.2f); // 왼쪽 눕기
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\DownRight", Vector2::Zero, 0.2f); // 오른쪽 눕기
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\DownAttackLeft", Vector2::Zero, 0.2f); // 왼쪽 아래 공격
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\DownAttackRight", Vector2::Zero, 0.2f); // 오른쪽 아래 공격

	m_Animator->Play(L"CharIdleRight", true);
	direction = 1;

	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-30.0f, -150.0f));

	mRigidbody = AddComponent<Rigidbody>();
	mRigidbody->SetMass(1.f);

	m_State = eMainCharState::Idle;
	GameObject::Initialize();


	Vector2 velocity = mRigidbody->GetVelocity();
	velocity.y -= 500.0f;

	mRigidbody->SetVelocity(velocity);
	mRigidbody->SetGround(false);

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
	case  MainChar::eMainCharState::Jump:
		jump();
		break;
	case  MainChar::eMainCharState::Down:
		down();
		break;
	case  MainChar::eMainCharState::DownAttack:
		downattack();
		break;
	case  MainChar::eMainCharState::Attack:
		basic_attack();
		break;
	case  MainChar::eMainCharState::CosmosSkill:
		cosmosSkill();
		break;
	case  MainChar::eMainCharState::SoulEclipse:
		souleclipseSkill();
		break;
	case  MainChar::eMainCharState::SolunaDivide:
		solunadivide();
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

void MainChar::OnCollisionEnter(Collider* other)
{
	//포탈에 부딛혔을때 걸리는 함수
	Portal* potal = dynamic_cast<Portal*>(other->GetOwner());
	if (potal != nullptr)
	{
		m_PortalState = true;
	}
}

void MainChar::OnCollisionExit(Collider* other)
{
	Portal* potal = dynamic_cast<Portal*>(other->GetOwner());
	if (potal != nullptr)
	{
		m_PortalState = false;
	}
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
		direction = 0;
	}
	else if (direction == 1 && Input::GetKeyDown(eKeyCode::DOWN))
	{
		m_State = eMainCharState::Down;
		m_Animator->Play(L"CharDownRight", true);
		direction = 1;
	}
	else if (Input::GetKeyDown(eKeyCode::F) && direction == 1)
	{
		m_State = eMainCharState::Attack;
		m_Animator->Play(L"CharattackRight", true);
		direction = 1;
		Scene* curScene = SceneManager::GetActiveScene();
		BasicSkill* Rbasicskill = new BasicSkill();
		Vector2 bsPos = tr->GetPos();
		Rbasicskill->GetComponent<Transform>()->SetPos(Vector2(bsPos.x + 280.f, bsPos.y - 100.f));
		Rbasicskill->RightAttack();
		curScene->AddGameObeject(Rbasicskill, eLayerType::Skill);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
	}
	else if (Input::GetKeyDown(eKeyCode::F) && direction == 0)
	{
		m_State = eMainCharState::Attack;
		m_Animator->Play(L"CharattackLeft", true);
		direction = 0;
		Scene* curScene = SceneManager::GetActiveScene();
		BasicSkill* Rbasicskill = new BasicSkill();
		Vector2 bsPos = tr->GetPos();
		Rbasicskill->GetComponent<Transform>()->SetPos(Vector2(bsPos.x + 280.f, bsPos.y - 100.f));
		Rbasicskill->LeftAttack();
		curScene->AddGameObeject(Rbasicskill, eLayerType::Skill);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
	}
	else if (direction == 0 && Input::GetKeyDown(eKeyCode::SPACE))
	{
		m_Animator->Play(L"CharjumpLeft", true);
		Vector2 velocity = mRigidbody->GetVelocity();
		velocity.y -= 400.0f;

		mRigidbody->SetVelocity(velocity);
		mRigidbody->SetGround(false);
	}
	else if (direction == 1 && Input::GetKeyDown(eKeyCode::SPACE))
	{
		m_Animator->Play(L"CharjumpRight", true);
		Vector2 velocity = mRigidbody->GetVelocity();
		velocity.y -= 400.0f;

		mRigidbody->SetVelocity(velocity);
		mRigidbody->SetGround(false);
	}

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();


	if (Input::GetKey(eKeyCode::LEFT))
	{
		direction = 0;
		pos.x -= 200.0 * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::RIGHT))
	{
		direction = 1;
		pos.x += 200.0 * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::UP))
	{
	}
	if (Input::GetKey(eKeyCode::DOWN))
	{
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
		direction = 0;
	}
	else if (direction == 1 && Input::GetKeyDown(eKeyCode::DOWN))
	{
		m_State = eMainCharState::Down;
		m_Animator->Play(L"CharDownRight", true);
		direction = 1;
	}
	else if (direction == 0 && Input::GetKeyDown(eKeyCode::SPACE))
	{
		m_State = eMainCharState::Jump;
		m_Animator->Play(L"CharjumpLeft", true);
		Vector2 velocity = mRigidbody->GetVelocity();
		velocity.y -= 400.0f;

		mRigidbody->SetVelocity(velocity);
		mRigidbody->SetGround(false);
		mGroundCheck = false;
		
	}
	else if (direction == 1 && Input::GetKeyDown(eKeyCode::SPACE))
	{
		m_State = eMainCharState::Jump;
		m_Animator->Play(L"CharjumpRight", true);
		Vector2 velocity = mRigidbody->GetVelocity();
		velocity.y -= 400.0f;

		mRigidbody->SetVelocity(velocity);
		mRigidbody->SetGround(false);
	}
	else if (Input::GetKeyDown(eKeyCode::F) && direction == 1)
	{
		m_State = eMainCharState::Attack; 
		m_Animator->Play(L"CharattackRight", true);
		direction = 1;
		Transform* BsR = GetComponent<Transform>();
		Scene* curScene = SceneManager::GetActiveScene();
		BasicSkill* Rbasicskill = new BasicSkill();
		Rbasicskill->RightAttack();
		Vector2 bsPos = tr->GetPos();
		Rbasicskill->GetComponent<Transform>()->SetPos(Vector2(bsPos.x + 280.f, bsPos.y - 100.f));
		curScene->AddGameObeject(Rbasicskill, eLayerType::Skill);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);

	}
	else if (Input::GetKeyDown(eKeyCode::F) && direction == 0)
	{
		m_State = eMainCharState::Attack;
		Transform* BsL = GetComponent<Transform>();
		m_Animator->Play(L"CharattackLeft", true);
		direction = 0;
		Scene* curScene = SceneManager::GetActiveScene();
		BasicSkill* Lbasicskill = new BasicSkill();
		Lbasicskill->LeftAttack();
		Vector2 bsPos = tr->GetPos();
		Lbasicskill->GetComponent<Transform>()->SetPos(Vector2(bsPos.x - 280.f, bsPos.y - 100.f));
		curScene->AddGameObeject(Lbasicskill, eLayerType::Skill);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
	}
	else if (Input::GetKeyDown(eKeyCode::D))
	{
		m_State = eMainCharState::CosmosSkill;
		Scene* curScene = SceneManager::GetActiveScene();
		Cosmos* cosmos = new Cosmos();
		cosmos->Initialize();
		Vector2 CsPos = tr->GetPos();
		cosmos->GetComponent<Transform>()->SetPos(CsPos);
		curScene->AddGameObeject(cosmos, eLayerType::Skill);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
	}
	else if (Input::GetKeyDown(eKeyCode::S))
	{
		m_State = eMainCharState::SoulEclipse;
		Transform* tr = GetComponent<Transform>();
		Scene* curScene = SceneManager::GetActiveScene();
		SoulEclipseBackGround* SBG = new SoulEclipseBackGround();
		SoulEclipseStart* SS = new SoulEclipseStart();
		SBG->Initialize();
		SS->Initialize();
		SS->GetComponent<Transform>()->SetPos(Vector2(780.f, 660.f));
		curScene->AddGameObeject(SBG, eLayerType::SoulEclipse);
		curScene->AddGameObeject(SS, eLayerType::SoulEclipse);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
	}
	else if (Input::GetKeyDown(eKeyCode::A))
	{
		m_State = eMainCharState::SolunaDivide;
		Transform* tr = GetComponent<Transform>();
		Scene* curScene = SceneManager::GetActiveScene();
		SolunaDivideStart* SD = new SolunaDivideStart();
		SolunaDivideBG* BG = new SolunaDivideBG();
		BG->Initialize();
		SD->Initialize();
		SD->GetComponent<Transform>()->SetPos(Vector2(780.f, 660.f));
		curScene->AddGameObeject(BG, eLayerType::SoulEclipse);
		curScene->AddGameObeject(SD, eLayerType::SoulEclipse);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
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
	if (Input::GetKeyUp(eKeyCode::F) && direction == 0)
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

void MainChar::cosmosSkill()
{
	if (Input::GetKeyUp(eKeyCode::D) && direction == 0)
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleLeft", true);
	}
	else if (Input::GetKeyUp(eKeyCode::D) && direction == 1)
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleRight", true);
	}
}

void MainChar::souleclipseSkill()
{
	if (Input::GetKeyUp(eKeyCode::S) && direction == 0)
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleLeft", true);
	}
	else if (Input::GetKeyUp(eKeyCode::S) && direction == 1)
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleRight", true);
	}
}

void MainChar::solunadivide()
{
	if (Input::GetKeyUp(eKeyCode::A) && direction == 0)
	{
		m_State = eMainCharState::Idle;
		m_Animator->Play(L"CharIdleLeft", true);
	}
	else if (Input::GetKeyUp(eKeyCode::A) && direction == 1)
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
		direction = 0;
	}
	else if (direction == 1 && Input::GetKey(eKeyCode::F))
	{
		m_State = eMainCharState::DownAttack;
		m_Animator->Play(L"CharDownAttackRight", true);
		direction = 1;
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
		direction = 0;
	}
	else if (direction == 1 && Input::GetKeyUp(eKeyCode::F))
	{
		m_State = eMainCharState::Down;
		m_Animator->Play(L"CharDownRight", true);
		direction = 1;
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