#include "Arcana.h"
#include "ArcanaBack.h"
#include "ArcanaObject.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"
#include "waterspirit.h"
#include "Camera.h"
#include "CollisionManager.h"
#include "Ground.h"
#include "Transform.h"
#include "Portal.h"

Arcana::Arcana()
{
	
}
Arcana::~Arcana()
{
}
void Arcana::Initialize()
{
	m_mainchar = new MainChar();
	AddGameObeject(m_mainchar, eLayerType::Player);

	m_arcanaback = new ArcanaBack();
	AddGameObeject(m_arcanaback, eLayerType::BG);

	m_arcanaobject = new ArcanaObject();
	AddGameObeject(m_arcanaobject, eLayerType::BG);

	m_waterspirit = new waterspirit();
	AddGameObeject(m_waterspirit, eLayerType::Monster);


	Portal* portal0 = new Portal();
	AddGameObeject(portal0, eLayerType::Portal);

	Portal* portal1 = new Portal();
	AddGameObeject(portal1, eLayerType::Portal);

	Ground* ground0 = new Ground();
	AddGameObeject(ground0, eLayerType::Monster);

	Ground* ground1 = new Ground();
	AddGameObeject(ground1, eLayerType::Monster);

	Ground* ground2 = new Ground();
	AddGameObeject(ground2, eLayerType::Monster);

	Ground* ground3 = new Ground();
	AddGameObeject(ground3, eLayerType::Monster);

	Ground* ground4 = new Ground();
	AddGameObeject(ground4, eLayerType::Monster);

	Ground* ground5 = new Ground();
	AddGameObeject(ground5, eLayerType::Monster);

	Scene::Initialize();
	ground0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 1005.0f)); ground0->GetComponent<Collider>()->SetSize(Vector2(2800.0f, 30.0f));
	ground1->GetComponent<Transform>()->SetPos(Vector2(0.0f, 370.0f)); ground1->GetComponent<Collider>()->SetSize(Vector2(510.0f, 30.0f));
	ground2->GetComponent<Transform>()->SetPos(Vector2(500.0f, 580.0f)); ground2->GetComponent<Collider>()->SetSize(Vector2(510.0f, 30.0f));
	ground3->GetComponent<Transform>()->SetPos(Vector2(990.0f, 730.0f)); ground3->GetComponent<Collider>()->SetSize(Vector2(600.0f, 30.0f));
	ground4->GetComponent<Transform>()->SetPos(Vector2(1580.0f, 580.0f)); ground4->GetComponent<Collider>()->SetSize(Vector2(510.0f, 30.0f));
	ground5->GetComponent<Transform>()->SetPos(Vector2(2070.0f, 730.0f)); ground5->GetComponent<Collider>()->SetSize(Vector2(510.0f, 30.0f));

	portal0->GetComponent<Transform>()->SetPos(Vector2(160.0f, 370.0f));
	portal1->GetComponent<Transform>()->SetPos(Vector2(2650.0f, 1000.0f));
}
void Arcana::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Boss_Enter);
	}

	Scene::Update();

	Camera::SetTarget(m_mainchar);

}
void Arcana::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void Arcana::Release()
{
	Scene::Release();
}
void Arcana::OnEnter()
{
	m_mainchar->GetComponent<Transform>()->SetPos(Vector2(500.0f, 800.0f));
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
}
void Arcana::OnExit()
{
}