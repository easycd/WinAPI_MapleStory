#include "Boss_Stage1_Scene.h"
#include "Boss_Stage1_Back.h"
#include "Boss_Stage1_Object.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"
#include "Boss_Ion.h"
#include "Boss_Yaldabaoth.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "Ground.h"
#include "Transform.h"
#include "Boss_Ion.h"

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
	m_Boss_Stage1_Object = new Boss_Stage1_Object();
	AddGameObeject(m_Boss_Stage1_Object, eLayerType::BG);

	Ground* ground0 = new Ground();
	AddGameObeject(ground0, eLayerType::Ground);

	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);

	m_Boss_Ion = new Boss_Ion();
	AddGameObeject(m_Boss_Ion, eLayerType::Monster);

	m_Boss_Yaldabaoth = new Boss_Yaldabaoth();
	AddGameObeject(m_Boss_Yaldabaoth, eLayerType::Monster);

	Scene::Initialize();
	m_Boss_Ion->GetComponent<Transform>()->SetPos(Vector2(1800, 820));
	m_Boss_Ion->GetComponent<Transform>()->SetScale(Vector2(1.15f, 1.15f));
	m_Boss_Yaldabaoth->GetComponent<Transform>()->SetPos(Vector2(2700, 860));
	m_Boss_Yaldabaoth->GetComponent<Transform>()->SetScale(Vector2(1.15f, 1.15f));

	ground0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 770.0f));
	ground0->GetComponent<Collider>()->SetSize(Vector2(5000.0f, 30.0f));
}
void Boss_Stage1_Scene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Boss_Stage2);
	}

	Scene::Update();

	Camera::SetTarget(mMainChar);

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
	mMainChar->GetComponent<Transform>()->SetPos(Vector2(2400.0f, 700.0f));
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);

	m_Boss_Yaldabaoth->Yaldabaoth_respawn();
	m_Boss_Ion->Ion_respawn();

	Camera::SetImgResolution(Vector2(4520.f, 880.f));
}
void Boss_Stage1_Scene::OnExit()
{
}