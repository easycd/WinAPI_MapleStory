#include "SolunaDivideStart.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "Time.h"

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

	m_Animator->Play(L"SolunaDividescreen2", true);
	m_Animator->SetIsCameraMove(false);

	m_Animator->GetCompleteEvent(L"SolunaDividescreen2")

	GameObject::Initialize();
}


void SolunaDivideStart::Update()
{
	GameObject::Update();
}


void SolunaDivideStart::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(241, 185, 26));
	GameObject::Render(hdc);
}


void SolunaDivideStart::Release()
{
	GameObject::Release();
}

void SolunaDivideStart::Start()
{

	m_Animator->SetIsCameraMove(false);
}

void SolunaDivideStart::Loop()
{

	m_Animator->SetIsCameraMove(false);
}

void SolunaDivideStart::End()
{

	m_Animator->SetIsCameraMove(false);
}

