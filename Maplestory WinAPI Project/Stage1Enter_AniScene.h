#pragma once
#include "Scene.h"
#include "Image.h"


class Sound;
class Stage1Enter_Ani;

class Stage1Enter_AniScene : public Scene
{
public:
	Stage1Enter_AniScene();
	virtual ~Stage1Enter_AniScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	Stage1Enter_Ani* ani;
	Sound* S1Enter;
	float mTime;
};
