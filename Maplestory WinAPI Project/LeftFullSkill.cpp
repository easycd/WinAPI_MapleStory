#include "LeftFullSkill.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "Time.h"

LeftFullSkill::LeftFullSkill()
{
}

LeftFullSkill::~LeftFullSkill()
{
}

void LeftFullSkill::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(505.0f, 405.0f));
	tr->SetScale(Vector2(1.965f, 1.98f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill1_Left\\Skill1_Phase1_Start", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill1_Left\\Skill1_Phase1_Loop", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill1_Left\\Skill1_Phase2_Start", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill1_Left\\Skill1_Phase2_Loop", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill1_Left\\Skill1_end", Vector2::Zero, 0.1f);

	m_Animator->GetCompleteEvent(L"Skill1_LeftSkill1_Phase1_Start") = std::bind(&LeftFullSkill::P1_Loop, this);
	m_Animator->GetCompleteEvent(L"Skill1_LeftSkill1_Phase1_Loop") = std::bind(&LeftFullSkill::P2_Start, this);
	m_Animator->GetCompleteEvent(L"Skill1_LeftSkill1_Phase2_Start") = std::bind(&LeftFullSkill::P2_Loop, this);
	m_Animator->GetCompleteEvent(L"Skill1_LeftSkill1_Phase2_Loop") = std::bind(&LeftFullSkill::End, this);
	m_Animator->GetCompleteEvent(L"Skill1_LeftSkill1_end") = std::bind(&LeftFullSkill::Destroy, this);

	GameObject::Initialize();
}

void LeftFullSkill::Update()
{
	GameObject::Update();
}

void LeftFullSkill::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(255, 0, 255));
	GameObject::Render(hdc);
}

void LeftFullSkill::Release()
{
	GameObject::Release();
}

void LeftFullSkill::P1_Start()
{
	m_Animator->Play(L"Skill1_LeftSkill1_Phase1_Start", true);
}

void LeftFullSkill::P1_Loop()
{
	m_Animator->Play(L"Skill1_LeftSkill1_Phase1_Loop", true);
}

void LeftFullSkill::P2_Start()
{
	m_Animator->Play(L"Skill1_LeftSkill1_Phase2_Start", true);
}

void LeftFullSkill::P2_Loop()
{
	m_Animator->Play(L"Skill1_LeftSkill1_Phase2_Loop", true);
}

void LeftFullSkill::End()
{
	m_Animator->Play(L"Skill1_LeftSkill1_end", true);
}

void LeftFullSkill::Destroy()
{
	object::Destory(this);
}
