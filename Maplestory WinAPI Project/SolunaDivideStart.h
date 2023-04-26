#pragma once
#include "GameObject.h"

class Animation;
class Animator;

class SolunaDivideStart : public GameObject
{
public:
	SolunaDivideStart();
	~SolunaDivideStart();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void Start();
private:
	Animator* m_Animator;

	float mTime;

	void Loop();
	void End();

};

