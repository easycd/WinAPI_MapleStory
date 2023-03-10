#pragma once
#include "GameObject.h"
#include "Image.h"

class ArcanaBack : public GameObject
{
public:
	ArcanaBack();
	~ArcanaBack();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};

