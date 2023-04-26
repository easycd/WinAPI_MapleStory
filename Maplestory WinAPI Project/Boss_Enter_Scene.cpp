#include "Boss_Enter_Scene.h"
#include "Boss_Enter_Back.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "Ground.h"
#include "Transform.h"
#include "Portal.h"

Boss_Enter_Scene::Boss_Enter_Scene()
{
}
Boss_Enter_Scene::~Boss_Enter_Scene()
{
}
void Boss_Enter_Scene::Initialize()
{
	boss_enter_back = new Boss_Enter_Back();
	AddGameObeject(boss_enter_back, eLayerType::BG);

	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);

	Ground* ground0 = new Ground();
	AddGameObeject(ground0, eLayerType::Ground);

	Ground* ground1 = new Ground();
	AddGameObeject(ground1, eLayerType::Ground);

	Portal* portal0 = new Portal();
	AddGameObeject(portal0, eLayerType::Portal);

	Portal* portal1 = new Portal();
	AddGameObeject(portal1, eLayerType::Portal);

	Scene::Initialize();

	ground0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 600.0f)); ground0->GetComponent<Collider>()->SetSize(Vector2(2000.0f, 30.0f));

	ground1->GetComponent<Transform>()->SetPos(Vector2(720.0f, 555.0f)); ground1->GetComponent<Collider>()->SetSize(Vector2(550.0f, 10.0f));

	portal0->GetComponent<Transform>()->SetPos(Vector2(130.0f, 600.0f));
	portal1->GetComponent<Transform>()->SetPos(Vector2(1000.0f, 550.0f));
}
void Boss_Enter_Scene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Boss_Stage1);
	}

	Scene::Update();

	Camera::SetTarget(mMainChar);

}
void Boss_Enter_Scene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void Boss_Enter_Scene::Release()
{
	Scene::Release();
}
void Boss_Enter_Scene::OnEnter()
{
	mMainChar->GetComponent<Transform>()->SetPos(Vector2(240.0f, 800.0f));
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);

	Camera::SetImgResolution(Vector2(1990.f, 780.f));
}
void Boss_Enter_Scene::OnExit()
{
}