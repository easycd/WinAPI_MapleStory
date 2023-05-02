#include "BsHit.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"
#include "Object.h"
#include "MainChar.h"

BsHit::BsHit()
{
}

BsHit::~BsHit()
{
}

void BsHit::Initialize()
{
	tr = GetComponent<Transform>();

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\Hit\\BsHit", Vector2::Zero, 0.1f);
	
	m_Animator->GetCompleteEvent(L"HitBsHit") = std::bind(&BsHit::Distroy, this);
	GameObject::Initialize();
}

void BsHit::Update()
{
	GameObject::Update();
}

void BsHit::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(195, 195, 195));
	GameObject::Render(hdc);
}

void BsHit::Release()
{
	GameObject::Release();
}

void BsHit::Hit()
{
	m_Animator->Play(L"HitBsHit", true);
}

void BsHit::Distroy()
{
	object::Destory(this);
}
