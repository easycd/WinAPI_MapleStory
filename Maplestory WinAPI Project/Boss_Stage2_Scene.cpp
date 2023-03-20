#include "Boss_Stage2_Scene.h"
#include "Boss_Stage2_Back.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"
#include "CollisionManager.h"
#include "Camera.h"

Boss_Stage2_Scene::Boss_Stage2_Scene()
{
}
Boss_Stage2_Scene::~Boss_Stage2_Scene()
{
}
void Boss_Stage2_Scene::Initialize()
{
	m_Boss_Stage2_Back = new Boss_Stage2_Back();
	AddGameObeject(m_Boss_Stage2_Back, eLayerType::BG);

	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);
	/*Camera::SetTarget(mMainChar);*/

	Scene::Initialize();
}
void Boss_Stage2_Scene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Henesys);
	}

	Scene::Update();


}
void Boss_Stage2_Scene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void Boss_Stage2_Scene::Release()
{
	Scene::Release();
}
void Boss_Stage2_Scene::OnEnter()
{
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
}
void Boss_Stage2_Scene::OnExit()
{
}