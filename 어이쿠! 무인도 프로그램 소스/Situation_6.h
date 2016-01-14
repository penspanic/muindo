#pragma once
#include "Game.h"


class Situation_6 :public CScene
{
private:
	HBITMAP *hbit;
	HBITMAP *CurrentNarr;
	WORD SitState;


public:
	Situation_6();
	~Situation_6();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);
};
//
//6) 구름 선택지
//		A - 양떼구름이 동쪽으로 흐른다. - 사망
//		B - 뭉게구름이 굵직하게 피어올랐다. - 생존
//		C - 두루마리구름이 북으로 흐른다. - 사망