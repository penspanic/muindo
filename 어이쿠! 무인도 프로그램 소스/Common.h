#pragma once
#include <Windows.h>
#include "function.h"
#include "Singleton.h"

#define BUTTONABC_WIDTH 300
#define BUTTONABC_HEIGHT 230
class Common:public Singleton<Common> // 씬들에서 공통으로 사용하는 것 모음
{
private:
	HWND m_hWnd;

	DWORD StartTime;
	DWORD CurrentTime;
	HBITMAP *hbit;
	int NarrMoveNum;
	RECT Narration;
	bool PressEnter; // 엔터를 누를 수 있는지
	RECT A;	// A 선택지 버튼
	RECT B; // B 선택지 버튼
	RECT C; // C 선택지 버튼
	RECT Main;   // 메인으로 버튼
	RECT Return; // 처음으로 버튼
	RECT Exit;   // 게임종료 버튼
	RECT Enter;  // 엔터 버튼

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

