#include "MainChar_GroundCollider.h"
#include "Transform.h"
#include "Collider.h"
#include "CollisionManager.h"
#include "MainChar.h"

MainChar_GroundCollider::MainChar_GroundCollider()
{
}

MainChar_GroundCollider::~MainChar_GroundCollider()
{
}

void MainChar_GroundCollider::Initialize()
{
	/*Transform* tr = GetComponent<Transform>();
	tr->SetPos(mPos);*/
	//Transform* ChPos = player->GetComponent<Transform>();
	/*Transform* Pos =GetComponent<Transform>();
	Pos->SetPos(Vector2(ChPos));*/


	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(10, 10)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-35.0f, -65.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void MainChar_GroundCollider::Update()
{
	//mPos = player->GetComponent<Transform>()->GetPos();
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
