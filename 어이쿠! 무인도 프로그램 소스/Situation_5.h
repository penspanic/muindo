#pragma once
#include "Game.h"


class Situation_5 :public CScene
{
private:
	HBITMAP *hbit;
	HBITMAP *CurrentNarr;
	WORD SitState;


public:
	Situation_5();
	~Situation_5();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);
};

//	5) 은신처 선택지
//		A - 모래 속에 몸을 묻고 잔다. - 사망
//		B - 동굴에 불을 피워놓고 잔다. - 사망
//		C - 해변에 불을 피워놓고 잔다. - 생존