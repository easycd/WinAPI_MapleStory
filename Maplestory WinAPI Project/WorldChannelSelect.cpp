#include "WorldChannelSelect.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"
#include "Animation.h"
#include "Animator.h"


WorldChannelSelect::WorldChannelSelect()
{
}

WorldChannelSelect::~WorldChannelSelect()
{
}

void WorldChannelSelect::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(-855.f, 550.f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\StartUI\\WorldChennel", Vector2::Zero, 0.1f);
	//m_Animator->Play(L"StartUIWorldChennel", true);
	GameObject::Initialize();
}

void WorldChannelSelect::Update()
{
	GameObject::Update();
}

void WorldChannelSelect::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void WorldChannelSelect::Release()
{
	GameObject::Release();
}

void WorldChannelSelect::open()
{
	m_Animator->Play(L"StartUIWorldChennel", true);
}
