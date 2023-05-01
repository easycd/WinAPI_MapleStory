#pragma once
#include "GameObject.h"

class Animator;
class Animation;
class MainChar;

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

	void Start();

private:
	void Loop();
	void End();
	void Destroy();

private:
	Animator* m_Animator;
	eCosmosState m_State;
	Transform* tr;
	MainChar* player;
	float mTime;
	bool IsSkillOn;
	bool IsSkillLoop;
	int posx;
	int posy;

public:
	const void SetPosX(int x)
	{
		posx = x;
	}
	const void SetPosY(int y)
	{
		posy = y;
	}
};

