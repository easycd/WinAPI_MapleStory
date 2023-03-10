#include "Collider.h"
#include "Transform.h"
#include "GameObject.h"

Collider::Collider()
	: Component(eComponentType::Collider)
	, mCenter(Vector2::Zero)
	, mScale(Vector2::One)
	, mPos(Vector2::Zero)
	, mSize(55.0f, 85.0f)

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
	//�ʷϻ� �׵θ� �׸���
	HPEN pen = CreatePen(BS_SOLID, 2, RGB(0, 255, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, pen);
	HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH); //�������� ä���
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	Rectangle(hdc, mPos.x, mPos.y, mPos.x + mSize.x, mPos.y + mSize.y); //�׵θ� ũ�� ����

	(HPEN)SelectObject(hdc, oldPen);
	(HBRUSH)SelectObject(hdc, oldBrush);
	DeleteObject(pen);
}
void Collider::Release()
{
}