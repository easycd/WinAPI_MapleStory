#pragma once
#include "Scene.h"
#include "Image.h"

class CharacterSelectBG;
class CharacterMove;
class ChannelName;
class ChannelSelectScene;

class CharacterSelectScene : public Scene
{
public:
	CharacterSelectScene();
	virtual ~CharacterSelectScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	CharacterSelectBG* BG;
	CharacterMove* Character;
	ChannelName* ChName;
	ChannelSelectScene* chs;

	float mTime;
};


