#include "Boss_Stage2_Scene.h"
#include "Boss_Stage2_Back.h"
#include "Boss_Stage2_Object.h"
#include "Input.h"
#include "SceneManager.h"
#include "MainChar.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "Ground.h"
#include "Transform.h"
#include "Boss.h"
#include "CircleObj.h"
#include "Time.h"


Boss_Stage2_Scene::Boss_Stage2_Scene()
	: mTime(0.0f)
{
}
Boss_Stage2_Scene::~Boss_Stage2_Scene()
{
}
void Boss_Stage2_Scene::Initialize()
{
	m_Boss_Stage2_Back = new Boss_Stage2_Back();
	AddGameObeject(m_Boss_Stage2_Back, eLayerType::BG);

	m_Boss_Stage2_Object = new Boss_Stage2_Object();
	AddGameObeject(m_Boss_Stage2_Object, eLayerType::BG);

	Ground* ground0 = new Ground();
	AddGameObeject(ground0, eLayerType::Ground);

	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);

	boss = new Boss();
	AddGameObeject(boss, eLayerType::Boss);

	//circleobj0 = new CircleObj(); AddGameObeject(circleobj0, eLayerType::BossObj);
	//circleobj1 = new CircleObj(); AddGameObeject(circleobj1, eLayerType::BossObj);
	//circleobj2 = new CircleObj(); AddGameObeject(circleobj2, eLayerType::BossObj);
	//circleobj3 = new CircleObj(); AddGameObeject(circleobj3, eLayerType::BossObj);
	//circleobj4 = new CircleObj(); AddGameObeject(circleobj4, eLayerType::BossObj);
	//circleobj5 = new CircleObj(); AddGameObeject(circleobj5, eLayerType::BossObj);
	//circleobj6 = new CircleObj(); AddGameObeject(circleobj6, eLayerType::BossObj);
	//circleobj7 = new CircleObj(); AddGameObeject(circleobj7, eLayerType::BossObj);

	Scene::Initialize();

	ground0->GetComponent<Transform>()->SetPos(Vector2(0.0f, 690.0f));
	ground0->GetComponent<Collider>()->SetSize(Vector2(2000.0f, 30.0f));

	//circleobj1->GetComponent<Transform>()->SetPos(Vector2(400.0f, 200.0f));
	//circleobj2->GetComponent<Transform>()->SetPos(Vector2(650.0f, 200.0f));
	//circleobj3->GetComponent<Transform>()->SetPos(Vector2(900.0f, 200.0f));
	//circleobj4->GetComponent<Transform>()->SetPos(Vector2(1150.0f, 200.0f));
	//circleobj5->GetComponent<Transform>()->SetPos(Vector2(1400.0f, 200.0f));
	//circleobj6->GetComponent<Transform>()->SetPos(Vector2(1650.0f, 200.0f));
	//circleobj7->GetComponent<Transform>()->SetPos(Vector2(1900.0f, 200.0f));
}

void Boss_Stage2_Scene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Henesys);
	}

	Scene::Update();


	Camera::SetTarget(mMainChar);

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
	mMainChar->GetComponent<Transform>()->SetPos(Vector2(240.0f, 800.0f));

	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	CollisionManager::SetLayer(eLayerType::BossObj, eLayerType::Ground, true);

	boss->respawn();

	//circleobj0->respawn();
	//circleobj1->respawn();
	//circleobj2->respawn();
	//circleobj3->respawn();
	//circleobj4->respawn();
	//circleobj5->respawn();
	//circleobj6->respawn();
	//circleobj7->respawn();

}
void Boss_Stage2_Scene::OnExit()
{
}