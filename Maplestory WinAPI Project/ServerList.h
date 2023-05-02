#pragma once
#include "GameObject.h"
#include "Image.h"

class Animation;
class Animator;
class Application;

class ServerList : public GameObject
{
public:
	ServerList();
	~ServerList();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Animator* m_Animator;
	Application* Width;
	Application* Hight;
};
