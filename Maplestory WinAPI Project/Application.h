#pragma once
#include "MapleEngine.h"

class Application
{
public:
	Application(); // 게임 전체 총괄
	~Application();

	void Initialize(HWND hWnd); //게임 초기화
	void Run();
	void Update();
	void Render();
	void SetMenuBar(bool power);
	//void Release(); // 메모리 해제

	HWND GetHwnd() { return mHwnd; }
	HDC GetHdc() { return mHdc; }
	UINT GetWidth() { return mWidth; }
	UINT GetHeight() { return mHeight; }

private:
	void clear();

private:
	HWND mHwnd;
	HDC mHdc;

	//백버퍼
	HBITMAP mBackBuffer;
	HDC mBackHDC;
	HMENU mMenubar;

	UINT mWidth;
	UINT mHeight;

	Vector2 mPos;
};

