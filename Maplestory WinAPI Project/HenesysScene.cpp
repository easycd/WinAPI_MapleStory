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

	//캐릭터
	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);

	//Camera::SetTarget(mMainChar);

	//빨간달팽이 몬스터
	RedSnail* m_redsnail = new RedSnail();
	AddGameObeject(m_redsnail, eLayerType::Monster);
	
	//주황버섯 몬스터
	mushroom* m_mushroom = new mushroom();
	AddGameObeject(m_mushroom, eLayerType::Monster);

	Ground* ground = new Ground();
	AddGameObeject(ground, eLayerType::Ground);

	

	Scene::Initialize();
}
void HenesysScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Somyeol);
	}
	Scene::Update();
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
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
}
void HenesysScene::OnExit()
{
}