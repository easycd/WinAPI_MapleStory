#include "ChannelSelectBG.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"
#include "Animation.h"
#include "Animator.h"

ChannelSelectBG::ChannelSelectBG()
{
}

ChannelSelectBG::~ChannelSelectBG()
{
}

void ChannelSelectBG::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(-855.f, 768.f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\StartUI\\WorldSelect.frames", Vector2::Zero, 0.1f); 
	m_Animator->Play(L"StartUIWorldSelect.frames", true);
	GameObject::Initialize();
}

void ChannelSelectBG::Update()
{
	GameObject::Update();
}

void ChannelSelectBG::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ChannelSelectBG::Release()
{
	GameObject::Release();
}
