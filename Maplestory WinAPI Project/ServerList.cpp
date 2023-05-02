#include "ServerList.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"
#include "Animation.h"
#include "Animator.h"
#include "Application.h"

ServerList::ServerList()
{
}

ServerList::~ServerList()
{
}

void ServerList::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(-420.f,510.f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\StartUI\\ServerList", Vector2::Zero, 0.1f);
	m_Animator->Play(L"StartUIServerList", true);
}

void ServerList::Update()
{
	GameObject::Update();
}

void ServerList::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ServerList::Release()
{
	GameObject::Release();
}
