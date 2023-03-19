#include "Application.h"
#include "SceneManager.h"
#include "Time.h"
#include "Input.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "resource.h"

Application::Application()
	: mHwnd(NULL) //�ʱ�ȭ
	, mHdc(NULL)  //�ʱ�ȭ
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

	//��Ʈ�� �ػ󵵸� �����ϱ� ���� ���� ������ ũ�⸦ ������ش�.
	RECT rect = { 0, 0, mWidth , mHeight };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	// ������ ũ�� ����� ��� ����
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
	Camera::Initiailize(); //ī�޶� �Լ� �ʱ�ȭ
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
	Camera::Update(); //ī�޶� �Լ� ������Ʈ

	SceneManager::Update();
	CollisionManager::Update();
}

void Application::Render()
{
	// clear
	Rectangle(mBackHDC, -1, -1, 1602, 902);

	Time::Render(mBackHDC);
	Input::Render(mBackHDC);
	SceneManager::Render(mBackHDC);

	// ����ۿ� �ִ� �׸��� �������ۿ� �׷�����Ѵ�.
	BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
}

void Application::SetMenuBar(bool power)
{
	SetMenu(mHwnd, mMenubar);

	RECT rect = { 0, 0, mWidth , mHeight };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, power);

	// ������ ũ�� ����� ��� ����
	SetWindowPos(mHwnd
		, nullptr, 0, 0
		, rect.right - rect.left
		, rect.bottom - rect.top
		, 0);
	ShowWindow(mHwnd, true);
}

void Application::clear()
{
	HBRUSH grayBrush = CreateSolidBrush(RGB(121, 121, 121));
	HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHDC, grayBrush);
	Rectangle(mBackHDC, -1, -1, 1602, 902);
	SelectObject(mBackHDC, oldBrush);
	DeleteObject(grayBrush);
}