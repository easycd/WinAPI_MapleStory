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

	//초록색 테두리 그리기
	HPEN oldPen = (HPEN)SelectObject(hdc, pen);
	HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH); //투명으로 채우기
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
	//bool 함수로 true면 카메라 기능 , false면 카메라 기능 제거
	if (m_IsCameraMove)
	{
	Vector2 pos = Camera::CaluatePos(mPos); //pos를 카메라 좌표로 변경
	Rectangle(hdc, pos.x, pos.y, pos.x + mSize.x, pos.y + mSize.y); //테두리 크기 조정
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