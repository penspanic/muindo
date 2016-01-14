#pragma once
#include "function.h"
#include "Game.h"


enum StartState{ ActionLess = 0, Rise, Fall,ButtonClicked };
enum QuitState{ MoveRight = 2, MoveLeft };
enum InfoState {InfoActionLess=0,InfoMoveLeft,InfoStoped,InfoMoveRight};
class Main :public CScene
{
private:
	HBITMAP * hbit;
	RECT * Button;
	int ButtonMinY;
	int ButtonMaxX;
	BYTE QuitState;
	BYTE StartState;
	BYTE InfoState; 

	// Sound
	bool SoundPlay; 
	DWORD Sound1;
	DWORD MainBGM;

public:
	Main();
	~Main();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void RectCheck();
	void ButtonUpdate();
	void InfoUpdate();
	void Render(HDC hDC);
	void ButtonProcess();

};

