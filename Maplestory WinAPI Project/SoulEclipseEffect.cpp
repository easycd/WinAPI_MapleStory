#include "SoulEclipseEffect.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "Time.h"

SoulEclipseEffect::SoulEclipseEffect()
	: m_Time(0)
{
}

SoulEclipseEffect::~SoulEclipseEffect()
{
}

void SoulEclipseEffect::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetScale(Vector2(2.f, 2.f));
	//tr->SetPos(Vector2(200.0f, 500.0f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\SoulEclipse\\Effect", Vector2::Zero, 0.1f);
	m_Animator->Play(L"SoulEclipseEffect", true);
	m_Animator->SetIsCameraMove(false);
	GameObject::Initialize();
}

void SoulEclipseEffect::Update()
{
	GameObject::Update();
	m_Time += Time::DeltaTime();
	if (m_Time > 5.0f)
	{
		Destory(this);
	}

}

void SoulEclipseEffect::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(208, 208, 208));
	GameObject::Render(hdc);
}

void SoulEclipseEffect::Release()
{
	GameObject::Release();
}
