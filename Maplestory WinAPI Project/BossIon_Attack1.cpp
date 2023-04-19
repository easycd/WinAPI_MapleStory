#include "BossIon_Attack1.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"

BossIon_Attack1::BossIon_Attack1()
{
}

BossIon_Attack1::~BossIon_Attack1()
{
}

void BossIon_Attack1::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(1000.0f, 800.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss_stage1\\Ion\\attack1", Vector2::Zero, 0.1f);
	m_Animator->Play(L"Ionattack1", true);


	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(300, 580)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-150.0f, -580.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void BossIon_Attack1::Update()
{
	GameObject::Update();

}

void BossIon_Attack1::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(255, 255, 255));
	GameObject::Render(hdc);
}

void BossIon_Attack1::Release()
{
	GameObject::Release();
}

void BossIon_Attack1::attack1()
{
}
