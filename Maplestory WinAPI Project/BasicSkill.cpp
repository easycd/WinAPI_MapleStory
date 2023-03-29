#include "BasicSkill.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"
#include "Object.h"

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
}

void BasicSkill::Update()
{
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();

	//mTime += Time::DeltaTime();
	//if (mTime > 2.0f) //2초가 지나면 사라짐
	//{
	//	Destory(this);
	//}
}

void BasicSkill::Render(HDC hdc)
{
	m_Animator->Play(L"SkillBasicAttack", true);
}

void BasicSkill::Release()
{
	GameObject::Release();
}
