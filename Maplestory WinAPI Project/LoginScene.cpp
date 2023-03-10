#include "LoginScene.h"
#include "LoginBack.h"
#include "MainChar.h"
#include "Input.h"
#include "SceneManager.h"

LoginScene::LoginScene()
{
}
LoginScene::~LoginScene()
{
}
void LoginScene::Initialize()
{
	m_LoginBack = new LoginBack();
	AddGameObeject(m_LoginBack, eLayerType::BG);

	Scene::Initialize();
}
void LoginScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Henesys);
	}
	Scene::Update();
}
void LoginScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void LoginScene::Release()
{
}
void LoginScene::OnEnter()
{
}
void LoginScene::OnExit()
{
}