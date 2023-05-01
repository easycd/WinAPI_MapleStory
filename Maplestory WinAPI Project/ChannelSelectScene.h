#pragma once
#include "Scene.h"
#include "Image.h"


class ChannelSelectBG;
class Sound;
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

	void SetSound(bool ss)
	{
		bool Check = ss;
	}

private:
	ChannelSelectBG* BG;
	Sound* ChennalSd;
	float mTime;
	bool Check;
};

