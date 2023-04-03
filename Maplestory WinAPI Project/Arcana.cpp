#include "Arcana.h"
#include "ArcanaBack.h"
#include "ArcanaObject.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"
#include "waterspirit.h"
#include "Camera.h"
#include "CollisionManager.h"

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

	Scene::Initialize();
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
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
}
void Arcana::OnExit()
{
}