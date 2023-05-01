#pragma once
#include "Scene.h"
#include "Image.h"

class MainChar;
class HenesysBack;
class HenesysObject;
class mushroom;
class RedSnail;
class Portal;
class Ground;
class Camera;
class Sound;
class HenesysScene : public Scene
{
public:
	HenesysScene();
	~HenesysScene();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;


	virtual MainChar* GetPlayer() override { return mMainChar; };


private:
	HenesysBack* m_henesysBack;
	HenesysObject* m_henesysobject;
	MainChar* mMainChar;
	RedSnail* m_redsnail;
	Camera* Camera;
	Sound* HenesysSound;
	Sound* NextMap;

	mushroom* m_mushroom0;
	mushroom* m_mushroom1;
	mushroom* m_mushroom2;
	mushroom* m_mushroom3;
	//4¹ø ¹Ù´Ú			   
	mushroom* m_mushroom4;
	mushroom* m_mushroom5;
	mushroom* m_mushroom6;
	mushroom* m_mushroom7;
	//6¹ø ¹Ù´Ú			   
	mushroom* m_mushroom8;
	mushroom* m_mushroom9;
	mushroom* m_mushroom10;
	mushroom* m_mushroom11;
	mushroom* m_mushroom12;
	//7¹ø ¹Ù´Ú			   
	mushroom* m_mushroom13;
	mushroom* m_mushroom14;
	mushroom* m_mushroom15;
	mushroom* m_mushroom16;
	//8¹ø ¹Ù´Ú			   
	mushroom* m_mushroom17;
	mushroom* m_mushroom18;
	mushroom* m_mushroom19;
	mushroom* m_mushroom20;
};

