#pragma once
#include "GameObject.h"
#include "Image.h"

class SomyeolObject : public GameObject
{
public:
	SomyeolObject();
	~SomyeolObject();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};


