#include "SoulEclipseStart.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"

SoulEclipseStart::SoulEclipseStart()
{
}
SoulEclipseStart::~SoulEclipseStart()
{
}

void SoulEclipseStart::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\SoulEclipse\\StartEffect", Vector2::Zero, 0.15f);
	m_Animator->Play(L"SoulEclipseStartEffect", false);
}

void SoulEclipseStart::Update()
{
	GameObject::Update();
	/*if (m_Animator->IsComplte())
	{
		Destory(this);
	}*/
}

void SoulEclipseStart::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void SoulEclipseStart::Release()
{
	GameObject::Release();
}
