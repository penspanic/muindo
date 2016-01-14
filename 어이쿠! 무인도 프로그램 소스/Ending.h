#pragma once
#include "Game.h"

#define EndingSceneNum 7

class Ending :public CScene
{
private:
	HBITMAP *hbit;
	HBITMAP *CurrentBit;
	int CurrentNum;
public:
	Ending();
	~Ending();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);
};

