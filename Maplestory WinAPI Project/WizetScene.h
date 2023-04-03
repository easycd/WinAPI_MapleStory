#pragma once
#include "Scene.h"
#include "Image.h"


class Wizet;

class WizetScene : public Scene
{
public:
	WizetScene();
	~WizetScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	Wizet* m_wizet;
	float mTime;
};

