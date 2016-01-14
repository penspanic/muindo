#pragma once
#include "Game.h"


class Situation_1 :public CScene
{
private:
	HBITMAP *hbit;
	HBITMAP *CurrentNarr;
	WORD SitState;


public:
	Situation_1();
	~Situation_1();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);
};

//	1) 첫 행동 선택지
//		A - 제자리에서 체력을 회복한다. - 사망
//		B - 주변을 수색한다. - 사망
//		C - 그늘로 이동한다. - 생존