#include "Missobj.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"
#include "Animation.h"
#include "Animator.h"
#include "Collider.h"
#include "MainChar.h"
#include "Object.h"
#include "Time.h"
Missobj::Missobj()
{
}

Missobj::~Missobj()
{
}

void Missobj::Initialize()
{
	tr = GetComponent<Transform>();

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\UI\\Miss", Vector2::Zero, 0.1f);
	m_Animator->GetCompleteEvent(L"UIMiss") = std::bind(&Missobj::Destroy, this);

	GameObject::Initialize();
}

void Missobj::Update()
{
	player = SceneManager::GetPlayer();
	Vector2 playerPos0 = player->GetComponent<Transform>()->GetPos();
	//Vector2 playerX0 = Vector2(playerPos0.x, playerPos0.y);
	div -= 15 * Time::DeltaTime();
	tr->SetPos(Vector2(playerPos0.x, playerPos0.y - 200.f + div));
	GameObject::Update();
}

void Missobj::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Missobj::Release()
{
	GameObject::Release();
}

void Missobj::OnCollisionEnter(Collider* other)
{
}

void Missobj::OnCollisionStay(Collider* other)
{
}

void Missobj::play()
{
	m_Animator->Play(L"UIMiss", true);

}

void Missobj::Destroy()
{
	object::Destory(this);
}
