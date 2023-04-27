#pragma once
#include "Scene.h"
#include "Image.h"


class ChannelSelectBG;

class ChannelSelectScene : public Scene
{
public:
	ChannelSelectScene();
	virtual ~ChannelSelectScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	ChannelSelectBG* BG;
	float mTime;
};

