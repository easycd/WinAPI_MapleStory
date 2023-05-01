#include "emptyScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "EmptyObj.h"
#include "Time.h"
#include "Transform.h"
#include "Animator.h"
#include "Sound.h"
#include "RResources.h"

emptyScene::emptyScene()
{
}

emptyScene::~emptyScene()
{
}

void emptyScene::Initialize()
{
	Scene::Initialize();
	//메모리 누수
	m_empty = new EmptyObj();
	AddGameObeject(m_empty, eLayerType::BG);
	m_empty->Initialize();
	//wzsound = RResources::Load<Sound>(L"wzsound", L"..\\Resources\\Sound\\UI_Sound\\WzLogo.wav");
	//wzsound->Play(true);
}

void emptyScene::Update()
{
	mTime += Time::DeltaTime();
	if (mTime > 2.0f)
	{
		SceneManager::LoadScene(eSceneType::Start);
	}
	Scene::Update();
}

void emptyScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void emptyScene::Release()
{
	Scene::Release();
}

void emptyScene::OnEnter()
{
}

void emptyScene::OnExit()
{
}
