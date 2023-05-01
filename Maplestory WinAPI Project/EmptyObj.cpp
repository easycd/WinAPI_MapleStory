#include "EmptyObj.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"

EmptyObj::EmptyObj()
{
}

EmptyObj::~EmptyObj()
{
}

void EmptyObj::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	//tr->SetPos(Vector2(670.0f, 450.0f));
	tr->SetPos(Vector2(1000.0f, 1000.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\empty", Vector2::Zero, 0.1f);
	m_Animator->Play(L"Resourcesempty", false);
	GameObject::Initialize();
}

void EmptyObj::Update()
{
	GameObject::Update();
}

void EmptyObj::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void EmptyObj::Release()
{
	GameObject::Release();
}
