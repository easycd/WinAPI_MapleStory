#include "BasicSkill.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"

BasicSkill::BasicSkill()
	:mTime(0.0f)
{
}

BasicSkill::~BasicSkill()
{
}

void BasicSkill::Initialize()
{
}

void BasicSkill::Update()
{
	mTime += Time::DeltaTime();

	if (mTime > 2.0f)
	{
		Destory(this);
	}
	GameObject::Update();
}

void BasicSkill::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BasicSkill::Release()
{
	GameObject::Release();
}

void BasicSkill::RightAttack()
{
	Transform* tr = GetComponent<Transform>();
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\BasicAttackRight", Vector2::Zero, 0.1f);
	m_Animator->Play(L"SkillBasicAttackRight", true);

	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-300.0f, -380.0f));
	collider->SetSize(Vector2(580.0f, 380.0f));
}
