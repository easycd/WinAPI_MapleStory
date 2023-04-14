#include "WizetScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Wizet.h"
#include "Time.h"
#include "Transform.h"
#include "Animator.h"

WizetScene::WizetScene()
	: mTime(0.0f)
{
}
WizetScene::~WizetScene()
{
	/*delete m_wizet;
	m_wizet = nullptr;*/
}
void WizetScene::Initialize()
{
	//메모리 누수
	m_wizet = new Wizet();
	AddGameObeject(m_wizet, eLayerType::BG);
	m_wizet->Initialize();
		
	Scene::Initialize();
}
void WizetScene::Update()
{
	mTime += Time::DeltaTime();
	if (mTime > 6.0f)
	{
		SceneManager::LoadScene(eSceneType::Login);
	}
	Scene::Update();
}
void WizetScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
void WizetScene::Release()
{
	Scene::Release();
}
void WizetScene::OnEnter()
{
}
void WizetScene::OnExit()
{
}