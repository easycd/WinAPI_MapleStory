#include "Boss_Stage1_Scene.h"
#include "Boss_Stage1_Back.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"

Boss_Stage1_Scene::Boss_Stage1_Scene()
{
}
Boss_Stage1_Scene::~Boss_Stage1_Scene()
{
}
void Boss_Stage1_Scene::Initialize()
{
	m_Boss_Stage1_Back = new Boss_Stage1_Back();
	AddGameObeject(m_Boss_Stage1_Back, eLayerType::BG);

	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);

	Scene::Initialize();
}
void Boss_Stage1_Scene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Boss_Stage2);
	}

	Scene::Update();


}
void Boss_Stage1_Scene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void Boss_Stage1_Scene::Release()
{
	Scene::Release();
}
void Boss_Stage1_Scene::OnEnter()
{
}
void Boss_Stage1_Scene::OnExit()
{
}