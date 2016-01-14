#pragma once
#include "Game.h"


class Situation_4 :public CScene
{
private:
	HBITMAP *hbit;
	HBITMAP *CurrentNarr;
	WORD SitState;


public:
	Situation_4();
	~Situation_4();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);
};

//	4) 뱀 응급 처치 선택지
//		A - 입으로 독을 빨아낸다. - 사망
//		B - 넝쿨로 위쪽을 묶는다. - 생존
//		C - 코코넛 과즙으로 씻어낸다. - 사망