#pragma once
#include "GameObject.h"
#include "Image.h"

class HenesysObject : public GameObject
{
public:
	HenesysObject();
	~HenesysObject();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};


