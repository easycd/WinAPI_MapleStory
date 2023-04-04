#include "Boss_Enter_Scene.h"
#include "Boss_Enter_Back.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "Ground.h"
#include "Transform.h"

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

	Scene::Initialize();

	ground0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 600.0f));
	ground0->GetComponent<Collider>()->SetSize(Vector2(2000.0f, 30.0f));
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
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
}
void Boss_Enter_Scene::OnExit()
{
}