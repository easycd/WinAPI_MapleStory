#pragma once

#include "Scene.h"
#include "Image.h"

class LoginBack;

class LoginScene : public Scene
{
public:
	LoginScene();
	~LoginScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	LoginBack* m_LoginBack;
};
