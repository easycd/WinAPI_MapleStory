#include "Application.h"
#include "SceneManager.h"
#include "Time.h"
#include "Input.h"

Application::Application()
	: mHwnd(NULL) //초기화
	, mHdc(NULL)  //초기화
{
}

Application::~Application()
{

}

void Application::Initialize(HWND hWnd)
{
	mHwnd = hWnd;
	mHdc = GetDC(hWnd);
	mWidth = 1600;
	mHeight = 900;

	//비트맵 해상도를 설정하기 위한 실제 윈도우 크기를 계산해준다.
	RECT rect = { 0, 0, mWidth , mHeight };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	// 윈도우 크기 변경및 출력 설정
	SetWindowPos(mHwnd
		, nullptr, 100, 50
		, rect.right - rect.left
		, rect.bottom - rect.top
		, 0);
	ShowWindow(hWnd, true);

	mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
	mBackHDC = CreateCompatibleDC(mHdc);

	HBITMAP defaultBitmap
		= (HBITMAP)SelectObject(mBackHDC, mBackBuffer);
	DeleteObject(defaultBitmap);

	Time::Initialize();
	Input::Initialize();
	SceneManager::Initialize();
}

void Application::Run()
{
	Update();
	Render();
}

void Application::Update()
{
	Time::Update();
	Input::Update();
	SceneManager::Update();
}

void Application::Render()
{
	// clear
	Rectangle(mBackHDC, -1, -1, 1602, 902);

	Time::Render(mBackHDC);
	Input::Render(mBackHDC);
	SceneManager::Render(mBackHDC);

	// 백버퍼에 있는 그림을 원본버퍼에 그려줘야한다.
	BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
}

void Application::clear()
{
	HBRUSH grayBrush = CreateSolidBrush(RGB(121, 121, 121));
	HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHDC, grayBrush);
	Rectangle(mBackHDC, -1, -1, 1602, 902);
	SelectObject(mBackHDC, oldBrush);
	DeleteObject(grayBrush);
}