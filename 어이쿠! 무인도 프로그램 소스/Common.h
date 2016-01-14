#pragma once
#include <Windows.h>
#include "function.h"
#include "Singleton.h"

#define BUTTONABC_WIDTH 300
#define BUTTONABC_HEIGHT 230
class Common:public Singleton<Common> // ���鿡�� �������� ����ϴ� �� ����
{
private:
	HWND m_hWnd;

	DWORD StartTime;
	DWORD CurrentTime;
	HBITMAP *hbit;
	int NarrMoveNum;
	RECT Narration;
	bool PressEnter; // ���͸� ���� �� �ִ���
	RECT A;	// A ������ ��ư
	RECT B; // B ������ ��ư
	RECT C; // C ������ ��ư
	RECT Main;   // �������� ��ư
	RECT Return; // ó������ ��ư
	RECT Exit;   // �������� ��ư
	RECT Enter;  // ���� ��ư

	DWORD DeadBGM;
	DWORD MainBGM;

public:

	Common();
	~Common();
	void ResetCommon();
	void NarrationMove();
	void EnterMove();
	void DrawButton(HDC hDC, HBITMAP A, HBITMAP B, HBITMAP C);
	void DrawEnter(HDC hDC);
	void DrawEnter(HDC hDC, bool move);
	void DrawReturn(HDC hDC);
	void DrawMain(HDC hDC);
	void DrawExit(HDC hDC);
	
	RECT GetA(){ return A; }
	RECT GetB(){ return B; }
	RECT GetC(){ return C; }
	RECT GetNarration(){ return Narration; }
	RECT GetReturn(){ return Return; }
	RECT GetMain(){ return Main; }
	RECT GetExit(){ return Exit; }
	DWORD GetMainBGM(){ return MainBGM; }
	DWORD GetDeadBGM(){ return DeadBGM; }
	bool GetPressEnter(){ return PressEnter; }
	void PlayDeadBGM();
	void SetStartTime(DWORD StartTime){ this->StartTime = StartTime; }



};

#define CommonPtr()Singleton<Common>::InstancePtr()

