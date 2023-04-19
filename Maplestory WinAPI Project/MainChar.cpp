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
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(posx, posy));
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
	/*m_Animator->Play(L"CharIdleLeft", false);
	m_Animator->Play(L"CharmoveLeft", false);
	m_Animator->Play(L"CharmoveRight", false);
	m_Animator->Play(L"CharattackLeft", false);
	m_Animator->Play(L"CharattackRight", false);
	m_Animator->Play(L"CharjumpLeft", false);
	m_Animator->Play(L"CharjumpRight", false);
	m_Animator->Play(L"CharDownLeft", false);
	m_Animator->Play(L"CharDownRight", false);
	m_Animator->Play(L"CharDownAttackLeft", false);
	m_Animator->Play(L"CharDownAttackRight", false);*/


	/*m_Animator->GetStartEvent(L"CharIdleRight") = std::bind(&MainChar::idleCompleteEvent, this);*/
	m_Animator->Play(L"CharIdleRight", true);
	direction = 1;

	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-30.0f, -220.0f));

	mRigidbody = AddComponent<Rigidbody>();
	mRigidbody->SetMass(1.0f);

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
	default:
		break;
	}
	//
	/*Vector2 velocity = mRigidbody->GetVelocity();
	velocity.y = 100.0f;

	mRigidbody->SetVelocity(velocity);
	mRigidbody->SetGround(false);*/

	/*Transform* tr = GetComponent<Transform>();
	if (tr->GetPos().x <= 0.f)
		tr->SetPos(Vector2(0.f, tr->GetPos().y));*/

	/*if (m_Camera->GetLookPosition().x <= 0.f)
		m_Camera->SetLookPosition(Vector2(0.f, m_Camera->GetLookPosition().y));*/

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
		Transform* tr = GetComponent<Transform>();
		Scene* curScene = SceneManager::GetActiveScene();
		BasicSkill* basicskill = new BasicSkill();
		basicskill->SetPosX(700);
		basicskill->RightAttack();
		//basicskill->GetComponent<Transform>()->SetPos(Vector2(tr->GetPos().x + 300.f, tr->GetPos().y)); // 캐릭터의 좌표를 가저옴
		curScene->AddGameObeject(basicskill, eLayerType::Skill);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
	}
	else if (Input::GetKeyDown(eKeyCode::F) && direction == 0)
	{
		m_State = eMainCharState::Attack;
		m_Animator->Play(L"CharattackLeft", true);
		direction = 0;
		Transform* tr = GetComponent<Transform>();
		Scene* curScene = SceneManager::GetActiveScene();
		BasicSkill* basicskill = new BasicSkill();
		basicskill->SetPosX(50);
		basicskill->LeftAttack();
		//basicskill->GetComponent<Transform>()->SetPos(Vector2(tr->GetPos())); // 캐릭터의 좌표를 가저옴
		curScene->AddGameObeject(basicskill, eLayerType::Skill);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
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
		Transform* tr = GetComponent<Transform>();
		Scene* curScene = SceneManager::GetActiveScene();
		BasicSkill* basicskill = new BasicSkill();
		basicskill->SetPosX(700);
		basicskill->RightAttack();
		basicskill->GetComponent<Transform>()->SetPos(Vector2(tr->GetPos().x + 300.f, tr->GetPos().y )); // 캐릭터의 좌표를 가저옴
		curScene->AddGameObeject(basicskill, eLayerType::Skill);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);

	}
	else if (Input::GetKeyDown(eKeyCode::F) && direction == 0)
	{
		m_State = eMainCharState::Attack;
		m_Animator->Play(L"CharattackLeft", true);
		direction = 0;
		Transform* tr = GetComponent<Transform>();
		Scene* curScene = SceneManager::GetActiveScene();
		BasicSkill* basicskill = new BasicSkill();
		basicskill->SetPosX(50);
		basicskill->LeftAttack();
		basicskill->GetComponent<Transform>()->SetPos(Vector2(tr->GetPos())); // 캐릭터의 좌표를 가저옴
		curScene->AddGameObeject(basicskill, eLayerType::Skill);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
	}
	else if (Input::GetKeyDown(eKeyCode::D))
	{
		m_State = eMainCharState::CosmosSkill;
		//m_Animator->Play(L"CharattackLeft", true);
		Transform* tr = GetComponent<Transform>();
		Scene* curScene = SceneManager::GetActiveScene();
		Cosmos* cosmos = new Cosmos();
		/*cosmos->SetPosX(-250);
		cosmos->SetPosY(-350);*/
		cosmos->SetPosX(250);
		cosmos->SetPosY(-350);
		cosmos->Initialize();
		cosmos->GetComponent<Transform>()->SetPos(tr->GetPos());
		curScene->AddGameObeject(cosmos, eLayerType::Skill);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
	}
	else if (Input::GetKeyDown(eKeyCode::S))
	{
		m_State = eMainCharState::SoulEclipse;
		//m_Animator->Play(L"CharattackLeft", true);
		Transform* tr = GetComponent<Transform>();
		Scene* curScene = SceneManager::GetActiveScene();
		SoulEclipseBackGround* SBG = new SoulEclipseBackGround();
		SoulEclipseStart* SS = new SoulEclipseStart();
		SoulEclipseEffect* SE = new SoulEclipseEffect();
		SBG->Initialize();
		SS->Initialize();
		//SE->Initialize();
		SS->SetPosX(240);
		SS->SetPosY(80);
		//SBG->GetComponent<Transform>()->SetPos(Vector2::Zero);
		//SBG->GetComponent<Transform>()->SetScale(Vector2(2.5f, 2.5f));
		//SBG->GetComponent<Transform>()->SetPos(Vector2(tr->GetPos())); // 캐릭터의 좌표를 가저옴
		//SS->GetComponent<Transform>()->SetPos(Vector2(tr->GetPos())); // 캐릭터의 좌표를 가저옴
		curScene->AddGameObeject(SBG, eLayerType::SoulEclipse);
		curScene->AddGameObeject(SS, eLayerType::SoulEclipse);
		//curScene->AddGameObeject(SE, eLayerType::SoulEclipseEffect);
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