#pragma once
#include "MapleEngine.h"

class Application
{
public:
	Application(); // ���� ��ü �Ѱ�
	~Application();

	void Initialize(HWND hWnd); //���� �ʱ�ȭ
	void Run();
	void Update();
	void Render();
	void SetMenuBar(bool power);
	//void Release(); // �޸� ����

	HWND GetHwnd() { return mHwnd; }
	HDC GetHdc() { return mHdc; }
	UINT GetWidth() { return mWidth; }
	UINT GetHeight() { return mHeight; }

private:
	void clear();

private:
	HWND mHwnd;
	HDC mHdc;

	//�����
	HBITMAP mBackBuffer;
	HDC mBackHDC;
	HMENU mMenubar;

	UINT mWidth;
	UINT mHeight;

	Vector2 mPos;
};

