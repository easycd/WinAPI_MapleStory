#pragma once
#include "Scene.h"
#include "Image.h"


class Sound;
class Stage2Enter_Ani;

class Stage2Enter_AniScene : public Scene
{
public:
	Stage2Enter_AniScene();
	virtual ~Stage2Enter_AniScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	Stage2Enter_Ani* ani;
	Sound* S2Enter;
	float mTime;
};
