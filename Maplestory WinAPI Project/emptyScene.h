#pragma once
#include "Scene.h"
#include "Image.h"


class EmptyObj;
class Sound;

class emptyScene : public Scene
{
public:
	emptyScene();
	virtual ~emptyScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	EmptyObj* m_empty;
	Sound* wzsound;
	float mTime;
};