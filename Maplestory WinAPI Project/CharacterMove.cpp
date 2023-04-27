#include "CharacterMove.h"
#include "CharacterSelectBG.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"
#include "Animator.h"

CharacterMove::CharacterMove()
{
}

CharacterMove::~CharacterMove()
{
}

void CharacterMove::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(-1235.f, 482.f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Char\\moveRight", Vector2::Zero, 0.17f);
	m_Animator->Play(L"CharmoveRight", true);
	GameObject::Initialize();
}

void CharacterMove::Update()
{
	GameObject::Update();
}

void CharacterMove::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void CharacterMove::Release()
{
	GameObject::Release();
}
