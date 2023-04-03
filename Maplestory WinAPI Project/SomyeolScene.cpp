#include "SomyeolScene.h"
#include "SomyeolBack.h"
#include "SomyeolObject.h"
#include "MainChar.h"
#include "happy.h"
#include "Input.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "Ground.h"
#include "Transform.h"

SomyeolScene::SomyeolScene()
{
}
SomyeolScene::~SomyeolScene()
{
}
void SomyeolScene::Initialize()
{
	m_somyeolBack = new SomyeolBack();
	AddGameObeject(m_somyeolBack, eLayerType::BG);

	m_somyeolObject = new SomyeolObject();
	AddGameObeject(m_somyeolObject, eLayerType::BG);

	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);

	happy* m_happy = new happy();
	AddGameObeject(m_happy, eLayerType::Monster);

	Ground* ground0 = new Ground();
	AddGameObeject(ground0, eLayerType::Ground);
	Ground* ground1 = new Ground();
	AddGameObeject(ground1, eLayerType::Ground);
	Ground* ground2 = new Ground();
	AddGameObeject(ground2, eLayerType::Ground);
	Ground* ground3 = new Ground();
	AddGameObeject(ground3, eLayerType::Ground);
	Ground* ground4 = new Ground();
	AddGameObeject(ground4, eLayerType::Ground);
	Ground* ground5 = new Ground();
	AddGameObeject(ground5, eLayerType::Ground);
	Ground* ground6 = new Ground();
	AddGameObeject(ground6, eLayerType::Ground);

	Scene::Initialize();
	ground0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 1210.0f));
	ground0->GetComponent<Collider>()->SetSize(Vector2(2100.0f, 30.0f));
	ground1->GetComponent<Transform>()->SetPos(Vector2(0.0f, 975.0f));
	ground1->GetComponent<Collider>()->SetSize(Vector2(650.0f, 30.0f));
	ground2->GetComponent<Transform>()->SetPos(Vector2(0.0f, 555.0f));
	ground2->GetComponent<Collider>()->SetSize(Vector2(650.0f, 30.0f));
	ground3->GetComponent<Transform>()->SetPos(Vector2(1445.0f, 555.0f));
	ground3->GetComponent<Collider>()->SetSize(Vector2(650.0f, 30.0f));
	ground4->GetComponent<Transform>()->SetPos(Vector2(1445.0f, 975.0f));
	ground4->GetComponent<Collider>()->SetSize(Vector2(650.0f, 30.0f));
	ground5->GetComponent<Transform>()->SetPos(Vector2(665.0f, 855.0f));
	ground5->GetComponent<Collider>()->SetSize(Vector2(778.0f, 30.0f));
	ground6->GetComponent<Transform>()->SetPos(Vector2(665.0f, 435.0f));
	ground6->GetComponent<Collider>()->SetSize(Vector2(778.0f, 30.0f));
}
void SomyeolScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Arcana);
	}
	Scene::Update();

	Camera::SetTarget(mMainChar);
}
void SomyeolScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void SomyeolScene::Release()
{
}
void SomyeolScene::OnEnter()
{
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
}
void SomyeolScene::OnExit()
{
}