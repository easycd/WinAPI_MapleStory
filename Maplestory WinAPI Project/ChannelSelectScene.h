#pragma once
#include "Scene.h"
#include "Image.h"


class ChannelSelectBG;
class Sound;
class MousCollider;
class ServerList;
class Scania;
class WorldChannelSelect;

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
	Sound* worldClick;
	Sound* NextScene;
	MousCollider* Mc;
	POINT mousePos;
	Vector2 McPos;
	ServerList* Sl;
	Scania* scania;
	WorldChannelSelect* Wcs;

	float mTime;
	bool Check;
	bool nextCheck;
};

