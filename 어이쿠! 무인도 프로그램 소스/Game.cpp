#include "Game.h"
#include <fstream>
#include <ostream>
#include <iostream>
using namespace std;

#pragma warning(disable : 4244)

CGame::CGame()
{}
CGame::~CGame()
{}

bool CGame::Initialize(HWND g_hWnd)
{
	this->m_hWnd = g_hWnd;
	for (size_t i = 0; i < 14; i++)
	{
		CollectionCleared[i] = 0;
	}
	if (!SceneManager()->ChangeScene(new Main))
		return false;
	if (!InputManager()->Initialize(this->m_hWnd))
		return false;
	if (!SoundManager()->Initialize(this->m_hWnd))
		return false;
	FileCheck();

	return true;
}

void CGame::UnInitialize()
{
	InputManager()->DestroyInstance();
	SceneManager()->DestroyInstance();
	SoundManager()->DestroyInstance();
	CommonPtr()->DestroyInstance();

	
	ofstream output("Data.txt");

	for (size_t i = 0; i < 14; i++)
	{
		output << CollectionCleared[i];
		output << "\n";
	}
	output.close();

}

void CGame::FileCheck()
{

	ifstream input("Data.txt");
	for (size_t i = 0; i < 14; i++)
	{
		input >> CollectionCleared[i];
	}
	input.close();

}



void  CGame::InputProcess()
{
	SceneManager()->InputProcess();
}

void UpdateFPS(HDC hDC)
{

	static DWORD frameCount = 0;                //������ ī��Ʈ��
	static float timeElapsed = 0.0f;            //�帥 �ð�
	static DWORD lastTime = timeGetTime();		//������ �ð�(temp����)
	static TCHAR Mes[256];
	DWORD curTime = timeGetTime();				//���� �ð�
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1�������� �帥 �ð�) 1�ʴ����� �ٲ��ش�.
	int fps;
	timeElapsed += timeDelta;

	frameCount++;

	if (timeElapsed >= 1.0f)         
	{
		fps = frameCount / timeElapsed;

		wsprintf(Mes, L"%d������", fps);

		frameCount = 0;
		timeElapsed = 0.0f;

	}

	TextOut(hDC, 100, 100, Mes, lstrlen(Mes));

	lastTime = curTime;
}

void CGame::Process()
{
	SceneManager()->Process();
}

void CGame::Render()
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	HDC hMemDC;
	HBITMAP hBitMem, OldBitMap;

	hdc = BeginPaint(m_hWnd, &ps);
	GetClientRect(m_hWnd, &rect);
	hMemDC = CreateCompatibleDC(hdc);

	hBitMem = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
	OldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMem);

	FillRect(hMemDC, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));


	SceneManager()->Render(hMemDC);
	//UpdateFPS(hMemDC);

	BitBlt(hdc, rect.left, rect.top, rect.right, rect.bottom, hMemDC, 0, 0, SRCCOPY);
	hBitMem = (HBITMAP)SelectObject(hMemDC, OldBitMap);
	DeleteObject(hBitMem);

	DeleteDC(hMemDC);

	EndPaint(m_hWnd, &ps);
	InvalidateRect(m_hWnd, NULL, FALSE);
}