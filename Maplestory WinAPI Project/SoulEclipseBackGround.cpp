#include "SoulEclipseBackGround.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "Time.h"

SoulEclipseBackGround::SoulEclipseBackGround()
	: m_Time(0)
{
}

SoulEclipseBackGround::~SoulEclipseBackGround()
{
}

void SoulEclipseBackGround::Initialize()
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

void SoulEclipseBackGround::Update()
{
	GameObject::Update();
	m_Time += Time::DeltaTime();
	if (m_Time > 10.0f)
	{
		object::Destory(this);
	}
	
}

void SoulEclipseBackGround::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void SoulEclipseBackGround::Release()
{
	GameObject::Release();
}
