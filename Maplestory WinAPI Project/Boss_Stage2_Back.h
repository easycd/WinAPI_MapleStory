#pragma once
#include "GameObject.h"
#include "Image.h"

class Boss_Stage2_Back : public GameObject
{
public:
	Boss_Stage2_Back();
	~Boss_Stage2_Back();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

