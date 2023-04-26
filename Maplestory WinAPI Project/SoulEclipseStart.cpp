#include "SoulEclipseStart.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "Time.h"
#include "Input.h"
#include "SolunaDivideStart.h"

SoulEclipseStart::SoulEclipseStart()
{
}
SoulEclipseStart::~SoulEclipseStart()
{
}

void SoulEclipseStart::Initialize()
{
	//Transform* tr0 = GetComponent<Transform>();
	//tr0->SetPos(Vector2(780.f, 660.f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\SoulEclipse\\StartEffect", Vector2::Zero, 0.15f);
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\SoulEclipse\\Continue", Vector2::Zero, 0.15f);

	m_Animator->GetCompleteEvent(L"SoulEclipseStartEffect") = std::bind(&SoulEclipseStart::Loop, this);
	//m_Animator->GetCompleteEvent(L"SoulEclipseContinue") = std::bind(&SoulEclipseStart::End, this);
	m_Animator->Play(L"SoulEclipseStartEffect", true);
	m_Animator->SetIsCameraMove(false);

	GameObject::Initialize();
}

void SoulEclipseStart::Update()
{
	if (Input::GetKeyDown(eKeyCode::A))
		End();

	GameObject::Update();
}

void SoulEclipseStart::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(255, 153, 48));
	GameObject::Render(hdc);
}

void SoulEclipseStart::Release()
{
	GameObject::Release();
}

void SoulEclipseStart::Start()
{
}

void SoulEclipseStart::Loop()
{
	m_Animator->Play(L"SoulEclipseContinue", true);
	m_Animator->SetIsCameraMove(false);
}

void SoulEclipseStart::End()
{
	object::Destory(this);
}
