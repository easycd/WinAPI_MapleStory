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


	mMainChar = new MainChar();
	AddGameObeject(mMainChar, eLayerType::Player);

	m_Boss_Ion = new Boss_Ion();
	AddGameObeject(m_Boss_Ion, eLayerType::Monster);

	m_Boss_Yaldabaoth = new Boss_Yaldabaoth();
	AddGameObeject(m_Boss_Yaldabaoth, eLayerType::Monster);

	Scene::Initialize();
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
	CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
}
void Boss_Stage1_Scene::OnExit()
{
}