#include "Arcana.h"
#include "ArcanaBack.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"
#include "waterspirit.h"
#include "Camera.h"

Arcana::Arcana()
{
}
Arcana::~Arcana()
{
}
void Arcana::Initialize()
{
	m_arcanaBack = new ArcanaBack();
	AddGameObeject(m_arcanaBack, eLayerType::BG);

	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);
	Camera::SetTarget(mMainChar);

	m_waterspirit = new waterspirit();
	AddGameObeject(m_waterspirit, eLayerType::Monster);

	Scene::Initialize();
}
void Arcana::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Boss_Stage1);
	}

	Scene::Update();


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
}
void Arcana::OnExit()
{
}