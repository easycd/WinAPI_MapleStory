#pragma once
#include "GameObject.h"
#include "Image.h"

class Animation;
class Animator;
class Application;

class ChannelSelectBG : public GameObject
{
public:
	ChannelSelectBG();
	~ChannelSelectBG();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Animator* m_Animator;
	Application* Width;
	Application* Hight;
};
