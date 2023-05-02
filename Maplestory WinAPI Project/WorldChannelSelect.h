#pragma once
#include "GameObject.h"
#include "Image.h"

class Animation;
class Animator;

class WorldChannelSelect : public GameObject
{
public:
	WorldChannelSelect();
	~WorldChannelSelect();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void open();

private:
	Animator* m_Animator;

};
