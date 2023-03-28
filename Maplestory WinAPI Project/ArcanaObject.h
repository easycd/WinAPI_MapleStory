#pragma once
#include "GameObject.h"
#include "Image.h"

class ArcanaObject : public GameObject
{
public:
	ArcanaObject();
	~ArcanaObject();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

