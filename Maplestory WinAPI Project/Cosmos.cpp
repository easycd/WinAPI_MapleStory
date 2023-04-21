#include "Cosmos.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"

Cosmos::Cosmos()
	:mTime(0.0f)
	, IsSkillOn(false)
	, IsSkillLoop(false)
	, posx(0)
	, posy(0)
{
}

Cosmos::~Cosmos()
{
}

void Cosmos::Initialize()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetScale(Vector2(0.8f, 0.8f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\Cosmos\\start", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\Cosmos\\end", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\Cosmos\\loop", Vector2::Zero, 0.1f);

	//m_Animator->GetStartEvent(L"Cosmossstart") = std::bind(&Cosmos::StartSkill, this);
	m_Animator->Play(L"Cosmosstart", true);
	m_Animator->SetIsCameraMove(false);
	//m_Animator->Play(L"Cosmosend", true);


	//Collider* collider = AddComponent<Collider>();
	//collider->SetCenter(Vector2(-300.0f, -380.0f));
	//collider->SetSize(Vector2(580.0f, 380.0f));
}

void Cosmos::Update()
{
	GameObject::Update();

	mTime += Time::DeltaTime();
	if (mTime > 3.0f && IsSkillLoop == false)
	{
		IsSkillLoop = true;
		m_Animator->Play(L"Cosmosloop", true);
		m_Animator->SetIsCameraMove(false);
	}

	if (mTime > 5.0f && IsSkillOn == false && IsSkillLoop == true)
	{
		IsSkillOn = true;
		m_Animator->Play(L"Cosmosend", false);
		m_Animator->SetIsCameraMove(false);

	}

	if (IsSkillOn)
	{
		if (mTime > 6.0f)
			object::Destory(this);
	}

	/*
	if (mTime > 5.0f && IsSkillOn == false)
	{
		IsSkillOn = true;
		m_Animator->Play(L"Cosmosend", false);
		m_Animator->SetIsCameraMove(false);

	}

	if (IsSkillOn)
	{
		if (mTime > 8.f)
			Destory(this);
	}
	*/
}

void Cosmos::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(56, 11, 153));
	m_Animator->SetNullCameraPosX(posx);
	m_Animator->SetNullCameraPosY(posy);
	GameObject::Render(hdc); //TransparentBlt½ÇÇà
}

void Cosmos::Release()
{
	GameObject::Release();
}

