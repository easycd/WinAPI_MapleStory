#include "SolunaDivideEffect.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "Time.h"

SolunaDivideEffect::SolunaDivideEffect()
{
}

SolunaDivideEffect::~SolunaDivideEffect()
{
}

void SolunaDivideEffect::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(780.f, 660.f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\SolunaDivide\\screen0", Vector2::Zero, 0.05f);
	m_Animator->GetCompleteEvent(L"SolunaDividescreen0") = std::bind(&SolunaDivideEffect::End, this);

	m_Animator->Play(L"SolunaDividescreen0", true);

	m_Animator->SetIsCameraMove(false);
	GameObject::Initialize();
}

void SolunaDivideEffect::Update()
{
	GameObject::Update();
}

void SolunaDivideEffect::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(241, 185, 26));
	GameObject::Render(hdc);
}

void SolunaDivideEffect::Release()
{
	GameObject::Initialize();
}

void SolunaDivideEffect::Start()
{
}

void SolunaDivideEffect::End()
{
	object::Destory(this);
}
