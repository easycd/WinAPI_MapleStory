#include "SoulEclipseStart.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "Time.h"

SoulEclipseStart::SoulEclipseStart()
	: posx(0)
	, posy(0)
	, m_Time(0)
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
	m_Animator->SetIsCameraMove(false);
}

void SoulEclipseStart::Update()
{
	GameObject::Update();
	m_Time += Time::DeltaTime();
	/*if (m_Animator->IsComplte())
	{
		Destory(this);
	}*/
	if (m_Time > 5.0f)
	{
		Destory(this);
	}
}

void SoulEclipseStart::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(255, 153, 48));
	m_Animator->SetNullCameraPosX(posx);
	m_Animator->SetNullCameraPosY(posy);
	GameObject::Render(hdc);
}

void SoulEclipseStart::Release()
{
	GameObject::Release();
}
