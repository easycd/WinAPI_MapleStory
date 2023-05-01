#include "WizetScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "Wizet.h"
#include "Time.h"
#include "Transform.h"
#include "Animator.h"
#include "Sound.h"
#include "RResources.h"

WizetScene::WizetScene()
	: mTime(0.0f)
{
}
WizetScene::~WizetScene()
{
}
void WizetScene::Initialize()
{
	Scene::Initialize();
	//메모리 누수
	m_wizet = new Wizet();
	AddGameObeject(m_wizet, eLayerType::BG);
	m_wizet->Initialize();
	wzsound = RResources::Load<Sound>(L"wzsound", L"..\\Resources\\Sound\\UI_Sound\\WzLogo.wav");
}
void WizetScene::Update()
{
	mTime += Time::DeltaTime();
	if (mTime > 6.0f)
	{
		SceneManager::LoadScene(eSceneType::ChannelSelect);
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
	wzsound->Play(true);
}
void WizetScene::OnExit()
{
	wzsound->Stop(true);
}