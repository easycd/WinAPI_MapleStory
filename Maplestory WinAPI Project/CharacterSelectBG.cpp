#include "CharacterSelectBG.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"
#include "Animator.h"

CharacterSelectBG::CharacterSelectBG()
{
}

CharacterSelectBG::~CharacterSelectBG()
{
}

void CharacterSelectBG::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(-855.f, 768.f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\StartUI\\CharSelect", Vector2::Zero, 0.15f);
	m_Animator->Play(L"StartUICharSelect", true);
	GameObject::Initialize();
}

void CharacterSelectBG::Update()
{
	GameObject::Update();
}

void CharacterSelectBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void CharacterSelectBG::Release()
{
	GameObject::Release();
}