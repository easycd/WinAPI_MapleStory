#include "Collider.h"
#include "Transform.h"
#include "GameObject.h"
#include "Camera.h"

Collider::Collider()
	: Component(eComponentType::Collider)
	, mCenter(Vector2::Zero)
	, mScale(Vector2::One)
	, mPos(Vector2::Zero)
	, mSize(55.0f, 10.0f)
	, mCollisionCount(0)
	, m_IsCameraMove(true)
	, m_nullcameraX(0)
	, m_nullcameraY(0)
{

}

Collider::~Collider()
{
}
void Collider::Initialize()
{
}
void Collider::Update()
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	mPos = tr->GetPos() + mCenter;
}

void Collider::Render(HDC hdc)
{
	HPEN pen = NULL;
	if (mCollisionCount <= 0)
		pen = CreatePen(BS_SOLID, 2, RGB(0, 255, 0));
	else
		pen = CreatePen(BS_SOLID, 2, RGB(255, 0, 0));

	//�ʷϻ� �׵θ� �׸���
	HPEN oldPen = (HPEN)SelectObject(hdc, pen);
	HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH); //�������� ä���
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
	//bool �Լ��� true�� ī�޶� ��� , false�� ī�޶� ��� ����
	if (m_IsCameraMove)
	{
	Vector2 pos = Camera::CaluatePos(mPos); //pos�� ī�޶� ��ǥ�� ����
	Rectangle(hdc, pos.x, pos.y, pos.x + mSize.x, pos.y + mSize.y); //�׵θ� ũ�� ����
	}
	else
	{
		mPos.x += m_nullcameraX;
		mPos.y += m_nullcameraY;
		Vector2 pos = mPos;
		Rectangle(hdc, pos.x, pos.y, pos.x + mSize.x, pos.y + mSize.y);
	}

	(HPEN)SelectObject(hdc, oldPen);
	(HBRUSH)SelectObject(hdc, oldBrush);
	DeleteObject(pen);
}
void Collider::Release()
{
}
void Collider::OnCollisionEnter(Collider* other)
{
	mCollisionCount++;
	GetOwner()->OnCollisionEnter(other);
}
void Collider::OnCollisionStay(Collider* other)
{
	GetOwner()->OnCollisionStay(other);
}
void Collider::OnCollisionExit(Collider* other)
{
	mCollisionCount--;

	GetOwner()->OnCollisionExit(other);
}