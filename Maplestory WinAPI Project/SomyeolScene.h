#pragma once
#include "Scene.h"
#include "Image.h"

class MainChar;
class SomyeolBack;
class SomyeolObject;
class happy;
class Portal;
class Ground;
class Camera;
class Sound;

class SomyeolScene : public Scene
{
public:
	SomyeolScene();
	~SomyeolScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

	virtual MainChar* GetPlayer() override { return mMainChar; };

private:
	SomyeolBack* m_somyeolBack;
	SomyeolObject* m_somyeolObject;
	MainChar* mMainChar;
	Sound* SomyeolSound;
	Sound* NextMap;
};

