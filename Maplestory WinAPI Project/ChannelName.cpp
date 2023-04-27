#include "ChannelName.h"
#include "HenesysBack.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"

ChannelName::ChannelName()
{
}

ChannelName::~ChannelName()
{
}

void ChannelName::Initialize()
{
	 tr = GetComponent<Transform>();
	 tr->SetPos(Vector2(830.0f, 25.0f));
	mImage = RResources::Load<Image>(L"ChannelName", L"..\\Resources\\StartUI\\ChannelName\\ChannelName.bmp");
	GameObject::Initialize();
}

void ChannelName::Update()
{
	GameObject::Update();
}

void ChannelName::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Vector2 pos = tr->GetPos();
	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}

void ChannelName::Release()
{
	GameObject::Release();
}
