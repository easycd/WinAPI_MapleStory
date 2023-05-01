#pragma once
#include "Scene.h"
#include "Image.h"


class MainChar;
class Boss_Stage1_Back;
class Boss_Stage1_Object;
class Boss_Ion;
class Boss_Yaldabaoth;
class Sound;

class Boss_Stage1_Scene : public Scene
{
public:
	Boss_Stage1_Scene();
	~Boss_Stage1_Scene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

	virtual MainChar* GetPlayer() override { return mMainChar; };

private:
	MainChar* mMainChar;
	Boss_Stage1_Back* m_Boss_Stage1_Back;
	Boss_Stage1_Object* m_Boss_Stage1_Object;
	Boss_Ion* m_Boss_Ion;
	Boss_Yaldabaoth* m_Boss_Yaldabaoth;
	Sound* Stage1;
	Sound* NextMap;
};

