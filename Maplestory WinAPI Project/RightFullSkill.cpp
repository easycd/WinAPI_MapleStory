#include "RightFullSkill.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "Time.h"


RightFullSkill::RightFullSkill()
{
}

RightFullSkill::~RightFullSkill()
{
}

void RightFullSkill::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(505.0f, 405.0f));
	tr->SetScale(Vector2(1.965f, 1.98f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill3_Right\\Skill3_Phase1_Start", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill3_Right\\Skill3_Phase1_Loop", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill3_Right\\Skill3_Phase2_Start", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill3_Right\\Skill3_Phase2_Loop", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill3_Right\\Skill3_end", Vector2::Zero, 0.1f);

	m_Animator->GetCompleteEvent(L"Skill3_RightSkill3_Phase1_Start") = std::bind(&RightFullSkill::P1_Loop, this);
	m_Animator->GetCompleteEvent(L"Skill3_RightSkill3_Phase1_Loop") = std::bind(&RightFullSkill::P2_Start, this);
	m_Animator->GetCompleteEvent(L"Skill3_RightSkill3_Phase2_Start") = std::bind(&RightFullSkill::P2_Loop, this);
	m_Animator->GetCompleteEvent(L"Skill3_RightSkill3_Phase2_Loop") = std::bind(&RightFullSkill::End, this);
	m_Animator->GetCompleteEvent(L"Skill3_RightSkill3_end") = std::bind(&RightFullSkill::Destroy, this);

	GameObject::Initialize();
}

void RightFullSkill::Update()
{
	GameObject::Update();
}

void RightFullSkill::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(255, 0, 255));
	GameObject::Render(hdc);
}

void RightFullSkill::Release()
{
	GameObject::Release();
}

void RightFullSkill::P1_Start()
{
	m_Animator->Play(L"Skill3_RightSkill3_Phase1_Start", true);
}

void RightFullSkill::P1_Loop()
{
	m_Animator->Play(L"Skill3_RightSkill3_Phase1_Loop", true);
}

void RightFullSkill::P2_Start()
{
	m_Animator->Play(L"Skill3_RightSkill3_Phase2_Start", true);
}

void RightFullSkill::P2_Loop()
{
	m_Animator->Play(L"Skill3_RightSkill3_Phase2_Loop", true);
}

void RightFullSkill::End()
{
	m_Animator->Play(L"Skill3_RightSkill3_end", true);
}

void RightFullSkill::Destroy()
{
	object::Destory(this);
}
