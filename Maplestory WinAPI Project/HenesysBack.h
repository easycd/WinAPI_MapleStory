#pragma once
#include "GameObject.h"
#include "Image.h"

class HenesysBack : public GameObject
{
public:
	HenesysBack();
	~HenesysBack();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

public:
	UINT GetImageWidthSize()
	{
		return mImage->GetWidth();
	}

	UINT GetImageHeightSize()
	{
		return mImage->GetHeight();
	}

private:
	Image* mImage;
};
