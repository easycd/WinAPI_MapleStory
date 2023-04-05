#include "HenesysScene.h"
#include "HenesysBack.h"
#include "MainChar.h"
#include "Input.h"
#include "SceneManager.h"
#include "mushroom.h"
#include "RedSnail.h"
#include "Transform.h"
#include "Camera.h"
#include "CollisionManager.h"
#include "Ground.h"
#include "GameObject.h"
#include "HenesysObject.h"
#include "Rigidbody.h"
#include "Portal.h"

HenesysScene::HenesysScene()
{
}
HenesysScene::~HenesysScene()
{
}
void HenesysScene::Initialize()
{
	//헤네시스 배경
	HenesysBack* m_henesysBack = new HenesysBack();
	AddGameObeject(m_henesysBack, eLayerType::BG);

	HenesysObject* m_henesysobject = new HenesysObject();
	AddGameObeject(m_henesysobject, eLayerType::BG);

	Portal* m_portal0 = new Portal();
	AddGameObeject(m_portal0, eLayerType::Portal);

	Portal* m_portal1 = new Portal();
	AddGameObeject(m_portal1, eLayerType::Portal);

	//캐릭터
	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);

	//빨간달팽이 몬스터
	RedSnail* m_redsnail = new RedSnail();
	AddGameObeject(m_redsnail, eLayerType::Monster);
	
	//주황버섯 몬스터
	mushroom* m_mushroom = new mushroom();
	AddGameObeject(m_mushroom, eLayerType::Monster);

	Ground* ground0 = new Ground(); AddGameObeject(ground0, eLayerType::Ground);
	Ground* ground1 = new Ground(); AddGameObeject(ground1, eLayerType::Ground);
	Ground* ground2 = new Ground(); AddGameObeject(ground2, eLayerType::Ground);
	Ground* ground3 = new Ground(); AddGameObeject(ground3, eLayerType::Ground);
	Ground* ground4 = new Ground(); AddGameObeject(ground4, eLayerType::Ground);
	Ground* ground5 = new Ground(); AddGameObeject(ground5, eLayerType::Ground);
	Ground* ground6 = new Ground(); AddGameObeject(ground6, eLayerType::Ground);
	Ground* ground7 = new Ground(); AddGameObeject(ground7, eLayerType::Ground);
	Ground* ground8 = new Ground(); AddGameObeject(ground8, eLayerType::Ground);

	

	Scene::Initialize();
	ground0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 880.0f));
	ground0->GetComponent<Collider>()->SetSize(Vector2(1900.0f, 30.0f));
	ground1->GetComponent<Transform>()->SetPos(Vector2(110.0f, 310.0f));
	ground1->GetComponent<Collider>()->SetSize(Vector2(680.0f, 30.0f));
	ground2->GetComponent<Transform>()->SetPos(Vector2(1190.0f, 310.0f));
	ground2->GetComponent<Collider>()->SetSize(Vector2(140.0f, 30.0f));
	ground3->GetComponent<Transform>()->SetPos(Vector2(830.0f, 250.0f));
	ground3->GetComponent<Collider>()->SetSize(Vector2(320.0f, 30.0f));
	ground4->GetComponent<Transform>()->SetPos(Vector2(745.0f, 430.0f));
	ground4->GetComponent<Collider>()->SetSize(Vector2(485.0f, 30.0f));
	ground5->GetComponent<Transform>()->SetPos(Vector2(1280.0f, 430.0f));
	ground5->GetComponent<Collider>()->SetSize(Vector2(50.0f, 30.0f));
	ground6->GetComponent<Transform>()->SetPos(Vector2(650.0f, 610.0f));
	ground6->GetComponent<Collider>()->SetSize(Vector2(680.0f, 30.0f));
	ground7->GetComponent<Transform>()->SetPos(Vector2(110.0f, 670.0f));
	ground7->GetComponent<Collider>()->SetSize(Vector2(500.0f, 30.0f));
	ground8->GetComponent<Transform>()->SetPos(Vector2(1375.0f, 370.0f));
	ground8->GetComponent<Collider>()->SetSize(Vector2(495.0f, 30.0f));

	m_portal0->GetComponent<Transform>()->SetPos(Vector2(200.0f, 310.0f));
	m_portal1->GetComponent<Transform>()->SetPos(Vector2(1800.0f, 880.0f));

}
void HenesysScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Somyeol);
	}
	Scene::Update();

	Camera::SetTarget(mMainChar);
}
void HenesysScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void HenesysScene::Release()
{
}
void HenesysScene::OnEnter()
{
	mMainChar->GetComponent<Transform>()->SetPos(Vector2(700.0f, 900.0f));
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
	
	
}
void HenesysScene::OnExit()
{
}