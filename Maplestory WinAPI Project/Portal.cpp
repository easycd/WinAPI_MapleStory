#include "Portal.h"
#include "Time.h" 
#include "Input.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"

Portal::Portal()
{
}

Portal::~Portal()
{
}

void Portal::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetPos(Vector2(1000.0f, 800.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Object\\Portal_Bmp", Vector2::Zero, 0.1f);
	m_Animator->Play(L"ObjectPortal_Bmp", true);

	/*m_State = ePortalState::Idle;*/

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(100, 150)); // ��Ʈ�ڽ� ũ�� ����
	collider->SetCenter(Vector2(-50.0f, -150.0f)); // ��Ʈ�ڽ� ��ġ ����

	GameObject::Initialize();
}

void Portal::Update()
{
	GameObject::Update();
}

void Portal::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Portal::Release()
{
	GameObject::Release();
}
