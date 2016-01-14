#pragma once
#include "Game.h"


class Situation_8 :public CScene
{
private:
	HBITMAP *hbit;
	HBITMAP *CurrentNarr;
	WORD SitState;


public:
	Situation_8();
	~Situation_8();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);
};

//	8) 구조 선택지
//		A - 횃불을 피워 흔든다. - 사망
//		B - 소리를 크게 지른다. - 사망
//		C - 단검을 공중에 휘두른다. - 생존65