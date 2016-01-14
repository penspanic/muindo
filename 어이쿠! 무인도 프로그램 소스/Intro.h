#pragma once

#include "function.h"
#include "Game.h"

#define IntroSceneNum 7

class Intro :public CScene
{
private:
	//DWORD StartTime;
	//DWORD CurrentTime;
	HBITMAP * hbit;
	HBITMAP * CurrentBit;
	RECT * Button;
	int CurrentNum;

	DWORD Sound1;
	DWORD Sound2;

public:
	Intro();
	~Intro();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);

};

