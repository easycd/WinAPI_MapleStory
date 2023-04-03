#include "Ground.h"
#include "Collider.h"
#include "MainChar.h"
#include "Rigidbody.h"
#include "Transform.h"



Ground::Ground()
{
}

Ground::~Ground()
{
}

void Ground::Initialize()
{
	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(1700.0f, 50.0f));
	collider->SetCenter(Vector2(0.0f, 0.0f));
	GameObject::Initialize();
}

void Ground::Update()
{
	GameObject::Update();
}

void Ground::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Ground::Release()
{
}

void Ground::OnCollisionEnter(Collider* other)
{
	MainChar* mainchar = dynamic_cast<MainChar*>(other->GetOwner());
	if (mainchar == nullptr) 
		return;

	Rigidbody* rb = mainchar->GetComponent<Rigidbody>();
	rb->SetGround(true); //�ε����� �ɸ�

	Collider* maincharCol = mainchar->GetComponent<Collider>();
	Vector2 maincharPos = maincharCol->GetPos();

	Collider* groundCol = this->GetComponent<Collider>();
	Vector2 groundPos = groundCol->GetPos();

	float fLen = fabs(maincharPos.y - groundPos.y); //�� ����  = �÷��̾� ��ġ - �׶��� ����
	float fSize = (maincharCol->GetSize().y / 2.0f) + (groundCol->GetSize().y / 2.0f);

	if (fLen < fSize) //���̰� ���� ������� �۴ٸ�
	{
		Transform* mainTr = mainchar->GetComponent<Transform>();
		Transform* grTr = this->GetComponent<Transform>();

		Vector2 mainPos = mainTr->GetPos();
		Vector2 grPos = grTr->GetPos();

		mainPos -= (fSize - fLen) - 1.0f;
		mainTr->SetPos(mainPos);
	}
}

void Ground::OnCollisionStay(Collider* other)
{
}

void Ground::OnCollisionExit(Collider* other)
{
	MainChar* mainchar = dynamic_cast<MainChar*>(other->GetOwner());
	if (mainchar == nullptr) 
		return;

	Rigidbody* rb = mainchar->GetComponent<Rigidbody>();
	rb->SetGround(false);
}

