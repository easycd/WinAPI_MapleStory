#pragma once
#include "Scene.h"
#include "Image.h"


class MainChar;
class Boss_Stage2_Back;
class Boss_Stage2_Object;
class Boss;
class CircleObj;
class Sound;
class BossHP_Bar;
class Boss_Stage2_Scene : public Scene
{
public:
	Boss_Stage2_Scene();
	~Boss_Stage2_Scene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

	virtual MainChar* GetPlayer() override { return mMainChar; };

private:
	MainChar* mMainChar;
	Boss_Stage2_Back* m_Boss_Stage2_Back;
	Boss_Stage2_Object* m_Boss_Stage2_Object;
	Boss* boss;
	Sound* Stage2;
	BossHP_Bar* Hpb;

	CircleObj* circleobj0;
	CircleObj* circleobj1;
	CircleObj* circleobj2;
	CircleObj* circleobj3;
	CircleObj* circleobj4;
	CircleObj* circleobj5;
	CircleObj* circleobj6;
	CircleObj* circleobj7;

	float mTime;

	int bossHpCnt;
	int cnt;
	bool test = false;
};

