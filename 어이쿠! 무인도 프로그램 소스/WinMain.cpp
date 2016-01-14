#include <Windows.h>
#include "Game.h"
#include <time.h>
#include "resource.h"
/////////////////////////  WinMain  //////////////////////////
#pragma warning(disable : 4996)
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWnd;
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, INT)
{


	g_hInst = hInstance;

	WNDCLASS wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.hbrBackground = ((HBRUSH)GetStockObject(BLACK_BRUSH));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = L"어이쿠! 무인도";
	wc.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wc);

	hWnd = CreateWindow(wc.lpszClassName, wc.lpszClassName, WS_SYSMENU,
		GetSystemMetrics(SM_CXSCREEN) / 2 - SCREEN_X / 2,
		GetSystemMetrics(SM_CYSCREEN) / 2 - SCREEN_Y / 2,
		SCREEN_X + GetSystemMetrics(SM_CXFRAME) - 2,
		SCREEN_Y + (2 * GetSystemMetrics(SM_CYFRAME)) + 12,
		NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, SW_SHOWDEFAULT);	// 윈도우 상태 변경 

	if (!Game()->Initialize(hWnd)) // 초기화 
	{
		Game()->UnInitialize();		       // 초기화 실패시 해제
		MessageBox(NULL, L"GameInitialize Error!", L"Error!", MB_OK);

		DestroyWindow(hWnd);
		return -1;
	}
	//InputManager()->Initialize(hWnd);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	////////////////////////////////////////////////////////////////////
	
	static DWORD frameDelta = 0;
	static DWORD lastTime = timeGetTime();
	clock_t CurTime, OldTime;
	OldTime = clock();
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0L, 0L, PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else{
			InputManager()->InputUpdate();
			Game()->InputProcess(); // 키 상태를 업데이트 한다.
			Game()->Process();		// 업데이트
			Game()->Render();
			while (1)
			{
				CurTime = clock();
				if (CurTime - OldTime > 33)
				{
					OldTime = CurTime;
					break;
				}
			}
	
		}
	}

	////////////////////////////////////////////////////////////////////
	Game()->UnInitialize();			// 해제
	Game()->DestroyInstance();

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{



	switch (iMessage)
	{
	case WM_CREATE:
		return 0;

	case WM_PAINT:
		Game()->Render();

		break;

	case WM_COMMAND:
		return 0;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			if (MessageBox(hWnd, L"종료하시겠습니까?", L"게임 종료", MB_YESNO) == IDYES)
			{
				Game()->UnInitialize();
			}
		}
		return 0;
	case WM_DESTROY:
		Game()->UnInitialize();
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}