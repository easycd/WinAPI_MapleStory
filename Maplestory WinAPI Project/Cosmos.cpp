#include "Cosmos.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"

Cosmos::Cosmos()
	:mTime(0.0f)
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
	m_Animator->Play(L"Cosmosstart", true);
	//m_Animator->Play(L"Cosmosend", true);


	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-300.0f, -380.0f));
	collider->SetSize(Vector2(580.0f, 380.0f));
}

void Cosmos::Update()
{
	GameObject::Update();

	//EndSkill();
	mTime += Time::DeltaTime();

	if (mTime > 3.0f)
	{
		//Destory(this);
		//m_Animator->Play(L"Cosmosend", true);
		//m_Animator->GetEndEvent(L"Cosmosstart");
		m_Animator->Play(L"Cosmosend", true);


		//EndSkill();
	}

	// 플레이어 가져와
	vector2 playerpos = mainchar->getpos
		tr->setpos(playerpos().x + , playerpos.y);
	

	//if(m_Animator->FindAnimation((L"Cosmosstart"))->IsComplete())
		//m_Animator->Play(L"Cosmosend", true);

	



	/*switch (m_State)
	{
	case Cosmos::eCosmosState::Start:
		Initialize();
		break;
	case  Cosmos::eCosmosState::End:
		EndSkill();
		break;
	default:
		break;
	}*/
}

void Cosmos::Render(HDC hdc)
{
	R->SetR((__int8)207);
	G->SetG((__int8)207);
	B->SetB((__int8)207);
	GameObject::Render(hdc); //TransparentBlt실행

}

void Cosmos::Release()
{
	GameObject::Release();
}

void Cosmos::EndSkill()
{
	Transform* tr = GetComponent<Transform>();
	tr->SetScale(Vector2(0.8f, 0.8f));
	m_Animator->Play(L"Cosmosend", true);
}
