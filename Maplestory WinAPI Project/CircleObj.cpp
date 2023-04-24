#include "CircleObj.h"
#include "Time.h" 
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Animator.h"
#include "Scene.h"
#include "Collider.h"
#include "Ground.h"
#include "Object.h"



CircleObj::CircleObj()
	: mState(eCircleState::Raspawn)
	, Speed(300.0f)
	, FallTime(0.0f)
	, FallCnt(0)
{
}

CircleObj::~CircleObj()
{
}

void CircleObj::Initialize()
{
	mTransform = GetComponent<Transform>();
	mTransform->SetPos(Vector2(150.0f, 200.0f));

	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\CircleObj\\respawn", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\CircleObj\\fall", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Boss\\boss\\Object\\CircleObj\\end", Vector2::Zero, 0.1f);

	m_Animator->GetCompleteEvent(L"CircleObjrespawn") = std::bind(&CircleObj::fall, this);
	m_Animator->GetCompleteEvent(L"CircleObjend") = std::bind(&CircleObj::destroy, this);

	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(120, 120)); // 히트박스 크기 조정
	collider->SetCenter(Vector2(-60.0f, -150.0f)); // 히트박스 위치 조정

	GameObject::Initialize();
}

void CircleObj::Update()
{
	Vector2 pos = mTransform->GetPos();
	FallTime += Time::DeltaTime();
	switch (mState)
	{
	case CircleObj::eCircleState::Fall:
			pos.y += Speed * Time::DeltaTime();
			mTransform->SetPos(pos);

		if (pos.y > 750.0f)
		{
			mState = eCircleState::End;
			Check = false;
		}
		break;
	case CircleObj::eCircleState::End:
		end();
		break;
	case CircleObj::eCircleState::Raspawn:
		break;
	default:
		break;
	}
	GameObject::Update();
}

void CircleObj::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(208, 208, 208));
	GameObject::Render(hdc);
}

void CircleObj::Release()
{
	GameObject::Release();
}

void CircleObj::OnCollisionEnter(Collider* other)
{
}

void CircleObj::respawn()
{
	m_Animator->Play(L"CircleObjrespawn", true);
}

void CircleObj::fall()
{
	if (FallCnt == FallTiming)
	{
	mState = eCircleState::Fall;
	m_Animator->Play(L"CircleObjfall", true);
	}

	FallCnt++;
}

void CircleObj::end()
{
	mState = eCircleState::Raspawn;
	m_Animator->Play(L"CircleObjend", true);
}

void CircleObj::destroy()
{
	object::Destory(this);
}
