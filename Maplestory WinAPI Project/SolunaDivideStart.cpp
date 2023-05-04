#include "SolunaDivideStart.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "Time.h"

#include "SolunaDivideEffect.h"

SolunaDivideStart::SolunaDivideStart()
{
}

SolunaDivideStart::~SolunaDivideStart()
{
}

void SolunaDivideStart::Initialize()
{

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\SolunaDivide\\screen0", Vector2::Zero, 0.15f);
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\SolunaDivide\\screen1", Vector2::Zero, 0.15f);
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\SolunaDivide\\screen2", Vector2::Zero, 0.1f);
	
	m_Animator->GetCompleteEvent(L"SolunaDividescreen2") = std::bind(&SolunaDivideStart::End, this);


	Effect = object::Instantiate<SolunaDivideEffect>(eLayerType::SoulEclipseEffect);
	Effect->Initialize();
	m_Animator->Play(L"SolunaDividescreen2", true);

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(10000.f, 10000.f)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-1000.0f, -1000.0f)); // 히트박스 위치 조정

	m_Animator->SetIsCameraMove(false);
	GameObject::Initialize();
}


void SolunaDivideStart::Update()
{
	GameObject::Update();
}


void SolunaDivideStart::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(241, 186, 24));
	GameObject::Render(hdc);
}


void SolunaDivideStart::Release()
{
	GameObject::Release();
}

void SolunaDivideStart::Loop()
{

	m_Animator->SetIsCameraMove(false);
}

void SolunaDivideStart::End()
{
	object::Destory(this);
	m_Animator->SetIsCameraMove(false);
}

