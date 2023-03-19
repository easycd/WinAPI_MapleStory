#include "BasicSkill.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"


BasicSkill::BasicSkill()
{
}

BasicSkill::~BasicSkill()
{
}

void BasicSkill::Initialize()
{
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\BasicAttack", Vector2::Zero, 0.1f);

	GameObject::Initialize();
}

void BasicSkill::Update()
{
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	//tr->GetPos(pos);
	m_Animator->Play(L"SkillBasicAttack", false);
}

void BasicSkill::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void BasicSkill::Release()
{
}
