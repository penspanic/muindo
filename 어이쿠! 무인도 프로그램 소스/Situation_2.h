#pragma once
#include "Game.h"


class Situation_2 :public CScene
{
private:
	HBITMAP *hbit;
	HBITMAP *CurrentNarr;
	WORD SitState;


public:
	Situation_2();
	~Situation_2();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);
};

//	2) 식수 선택지
//		A - 가재가 산다. - 생존
//		B - 은어가 산다. - 사망
//		C - 붕어가 산다. - 사망