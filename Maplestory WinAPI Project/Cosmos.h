#pragma once
#include "GameObject.h"

class Animator;
class Animation;

class Cosmos : public GameObject
{
public:
	enum class eCosmosState
	{
		Start,
		End,
	};
	Cosmos();
	virtual ~Cosmos();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void EndSkill();
	void StartSkill();


private:
	Animator* m_Animator;
	Animation* R;
	Animation* G;
	Animation* B;
	eCosmosState m_State;
	float mTime;
};

