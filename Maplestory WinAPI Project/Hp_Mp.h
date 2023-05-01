#pragma once
#include "GameObject.h"
#include "Image.h"

class Hp_Mp : public GameObject
{
public:
	Hp_Mp();
	~Hp_Mp();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Image* mImage;
};