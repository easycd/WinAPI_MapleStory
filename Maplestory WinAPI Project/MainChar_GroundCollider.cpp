#include "MainChar_GroundCollider.h"
#include "Transform.h"
#include "Collider.h"
#include "CollisionManager.h"
#include "MainChar.h"
#include "Scene.h"
#include "Object.h"

MainChar_GroundCollider::MainChar_GroundCollider()
{
}

MainChar_GroundCollider::~MainChar_GroundCollider()
{
}

void MainChar_GroundCollider::Initialize()
{

	Collider* m_ground = AddComponent<Collider>();
	m_ground->SetSize(Vector2(50.0f, 50.0f));

	GameObject::Initialize();
}

void MainChar_GroundCollider::Update()
{


	GameObject::Update();
}

void MainChar_GroundCollider::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void MainChar_GroundCollider::Release()
{
	GameObject::Release();
}
