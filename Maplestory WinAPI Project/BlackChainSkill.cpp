#include "BlackChainSkill.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "Time.h"

BlackChainSkill::BlackChainSkill()
	: m_Time(0.0f)
	, Check(0.0f)
{
}

BlackChainSkill::~BlackChainSkill()
{
}

void BlackChainSkill::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(505.0f, 0.0f));
	tr->SetScale(Vector2(1.1f, 1.1f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\Skill4_BlackChain\\BlackChain_Obj", Vector2::Zero, 0.05f);
	m_Animator->GetCompleteEvent(L"Skill4_BlackChainBlackChain_Obj") = std::bind(&BlackChainSkill::Destroy, this);
	
	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(150.f, 1400.f));
	collider->SetCenter(Vector2(-40.0f, -1500.0f));

	GameObject::Initialize();
}

void BlackChainSkill::Update()
{
	GameObject::Update();
}

void BlackChainSkill::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(208, 208, 208));
	GameObject::Render(hdc);
}

void BlackChainSkill::Release()
{
	GameObject::Release();
}

void BlackChainSkill::Attack()
{
	m_Animator->Play(L"Skill4_BlackChainBlackChain_Obj", true);
}

void BlackChainSkill::Destroy()
{
	object::Destory(this);
}
