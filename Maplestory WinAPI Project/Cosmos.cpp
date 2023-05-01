#include "Cosmos.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "MainChar.h"
#include "MainChar.h"

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
	tr = GetComponent<Transform>();
	tr->SetScale(Vector2(0.8f, 0.8f));
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\Cosmos\\start", Vector2::Zero, 0.06f);
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\Cosmos\\end", Vector2::Zero, 0.1f);
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\Cosmos\\loop", Vector2::Zero, 0.1f);

	m_Animator->GetCompleteEvent(L"Cosmosstart") = std::bind(&Cosmos::Loop, this);
	m_Animator->GetCompleteEvent(L"Cosmosloop") = std::bind(&Cosmos::End, this);
	m_Animator->GetCompleteEvent(L"Cosmosend") = std::bind(&Cosmos::Destroy, this);

	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-400.0f, -700.0f));
	collider->SetSize(Vector2(650.0f, 380.0f));
}

void Cosmos::Update()
{
	GameObject::Update();
	player = SceneManager::GetPlayer();
	Vector2 playerPos = player->GetComponent<Transform>()->GetPos();
	tr->SetPos(Vector2(playerPos.x + 90.0f, playerPos.y + 290.0f));
}

void Cosmos::Render(HDC hdc)
{
	m_Animator->SetRGB(RGB(56, 11, 153));
	GameObject::Render(hdc); //TransparentBlt½ÇÇà
}

void Cosmos::Release()
{
	GameObject::Release();
}

void Cosmos::Start()
{
	m_Animator->Play(L"Cosmosstart", true);
}

void Cosmos::Loop()
{
	m_Animator->Play(L"Cosmosloop", true);
}

void Cosmos::End()
{
	m_Animator->Play(L"Cosmosend", true);
}

void Cosmos::Destroy()
{
	object::Destory(this);
}

