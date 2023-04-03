#pragma once
#include "GameObject.h"
#include "Image.h"

class Boss_Enter_Back : public GameObject
{
public:
	Boss_Enter_Back();
	~Boss_Enter_Back();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

