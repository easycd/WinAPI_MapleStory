#include "BossPortal.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"

BossPortal::BossPortal()
{
}

BossPortal::~BossPortal()
{
}

void BossPortal::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(1000.0f, 800.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Object\\BossPortal", Vector2::Zero, 0.1f);
	m_Animator->Play(L"ObjectBossPortal", true);

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(100, 150)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-50.0f, -150.0f)); // 히트박스 위치 조정
}

void BossPortal::Update()
{
	m_Animator->SetRGB(RGB(207, 207, 207));
	GameObject::Update();
}

void BossPortal::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BossPortal::Release()
{
	GameObject::Release();
}
