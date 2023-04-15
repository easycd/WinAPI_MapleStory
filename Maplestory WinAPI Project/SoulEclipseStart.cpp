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
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\SoulEclipse\\", Vector2::Zero, 0.1f);
	m_Animator->Play(L"", false);
}

void SoulEclipseStart::Update()
{
	if (m_Animator->IsComplte())
	{
		Destory(this);
	}
}

void SoulEclipseStart::Render(HDC hdc)
{
}

void SoulEclipseStart::Release()
{
}
