#pragma once
#include "GameObject.h"
#include "Image.h"

class ChannelName : public GameObject
{
public:
	ChannelName();
	~ChannelName();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
private:
	Transform* tr;
	Image* mImage;
};

