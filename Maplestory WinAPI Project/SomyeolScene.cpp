#include "SomyeolScene.h"
#include "SomyeolBack.h"
#include "MainChar.h"
#include "happy.h"
#include "Input.h"
#include "SceneManager.h"

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

	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);

	happy* m_happy = new happy();
	AddGameObeject(m_happy, eLayerType::Monster);

	Scene::Initialize();
}
void SomyeolScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Arcana);
	}
	Scene::Update();
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
}
void SomyeolScene::OnExit()
{
}