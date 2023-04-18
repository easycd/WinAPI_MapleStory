#include "Boss.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"

Boss::Boss()
{
}

Boss::~Boss()
{
}

void Boss::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(1000.0f, 800.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\stand", Vector2::Zero, 0.1f);
	m_Animator->Play(L"bossstand", true);


	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(300, 580)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-150.0f, -580.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void Boss::Update()
{
	GameObject::Update();
	//if ()
	//{
	//	respawn();
	//}
	/*switch (m_State)
	{
	case Boss::eBoss_IonState::Respawn:
		respawn();
		break;
	case Boss::eBoss_IonState::Move:
		move();
		break;
	case  Boss::eBoss_IonState::Idle:
		idle();
		break;
	case  Boss::eBoss_IonState::Attack1:
		attack1();
		break;
	case  Boss::eBoss_IonState::Attack2:
		attack2();
		break;
	default:
		break;
	}*/
}

void Boss::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(29, 29, 29));
	GameObject::Render(hdc);
}

void Boss::Release()
{
	GameObject::Release();
}

void Boss::respawn()
{
	
}

void Boss::move()
{
}

void Boss::idle()
{
}

void Boss::dead()
{
	
}

void Boss::attack1()
{

}

void Boss::attack2()
{
}
