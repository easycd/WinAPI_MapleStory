#include "CenterFullSkill.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "Time.h"

CenterFullSkill::CenterFullSkill()
{
}

CenterFullSkill::~CenterFullSkill()
{
}

void CenterFullSkill::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(505.0f, 405.0f));
	tr->SetScale(Vector2(1.965f, 1.98f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill2_Center\\Skill2_Phase1_Start", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill2_Center\\Skill2_Phase1_Loop", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill2_Center\\Skill2_Phase2_Start", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill2_Center\\Skill2_Phase2_Loop", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill2_Center\\Skill2_end", Vector2::Zero, 0.1f);

	m_Animator->GetCompleteEvent(L"Skill2_CenterSkill2_Phase1_Start") = std::bind(&CenterFullSkill::P1_Loop, this);
	m_Animator->GetCompleteEvent(L"Skill2_CenterSkill2_Phase1_Loop") = std::bind(&CenterFullSkill::P2_Start, this);
	m_Animator->GetCompleteEvent(L"Skill2_CenterSkill2_Phase2_Start") = std::bind(&CenterFullSkill::P2_Loop, this);
	m_Animator->GetCompleteEvent(L"Skill2_CenterSkill2_Phase2_Loop") = std::bind(&CenterFullSkill::End, this);
	m_Animator->GetCompleteEvent(L"Skill2_CenterSkill2_end") = std::bind(&CenterFullSkill::Destroy, this);

	GameObject::Initialize();
}

void CenterFullSkill::Update()
{
	GameObject::Update();
}

void CenterFullSkill::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(255, 0, 255));
	GameObject::Render(hdc);
}

void CenterFullSkill::Release()
{
	GameObject::Release();
}

void CenterFullSkill::P1_Start()
{
	m_Animator->Play(L"Skill2_CenterSkill2_Phase1_Start", true);
}

void CenterFullSkill::P1_Loop()
{
	m_Animator->Play(L"Skill2_CenterSkill2_Phase1_Loop", true);
}

void CenterFullSkill::P2_Start()
{
	m_Animator->Play(L"Skill2_CenterSkill2_Phase2_Start", true);
}

void CenterFullSkill::P2_Loop()
{
	m_Animator->Play(L"Skill2_CenterSkill2_Phase2_Loop", true);
}

void CenterFullSkill::End()
{
	m_Animator->Play(L"Skill2_CenterSkill2_end", true);
}

void CenterFullSkill::Destroy()
{
	object::Destory(this);
}
