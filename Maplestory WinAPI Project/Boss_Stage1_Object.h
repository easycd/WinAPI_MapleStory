#pragma once
#include "GameObject.h"
#include "Image.h"

class Boss_Stage1_Object : public GameObject
{
public:
	Boss_Stage1_Object();
	~Boss_Stage1_Object();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

