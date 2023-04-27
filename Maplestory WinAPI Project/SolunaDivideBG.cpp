#include "SolunaDivideBG.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "Time.h"
#include "Input.h"

SolunaDivideBG::SolunaDivideBG()
	: m_Time(0)
{
}

SolunaDivideBG::~SolunaDivideBG()
{
}

void SolunaDivideBG::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetScale(Vector2(2.f, 2.f));
	tr->SetPos(Vector2(340.0f, 385.0f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\SoulEclipse\\BackGround", Vector2::Zero, 0.1f);
	m_Animator->Play(L"SoulEclipseBackGround", false);
	m_Animator->SetIsCameraMove(false);

	GameObject::Initialize();
}

void SolunaDivideBG::Update()
{
	m_Time += Time::DeltaTime();
	if (m_Time > 2.5f)
	{
		object::Destory(this);
	}

	GameObject::Update();
}

void SolunaDivideBG::Render(HDC hdc)
{

	GameObject::Render(hdc);
}

void SolunaDivideBG::Release()
{

	GameObject::Release();
}
