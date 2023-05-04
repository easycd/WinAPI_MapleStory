#pragma once
#include "GameObject.h"
#include "Image.h"

class BossHP_State : public GameObject
{
public:
	BossHP_State();
	~BossHP_State();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

