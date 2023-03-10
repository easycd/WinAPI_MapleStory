#pragma once
#include "GameObject.h"
#include "Image.h"

class Boss_Stage1_Back : public GameObject
{
public:
	Boss_Stage1_Back();
	~Boss_Stage1_Back();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

