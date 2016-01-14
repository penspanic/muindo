#pragma once
#include "Game.h"


class Situation_3 :public CScene
{
private:
	HBITMAP *hbit;
	HBITMAP *CurrentNarr;
	WORD SitState;


public:
	Situation_3();
	~Situation_3();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);
};

//	3) 식용 식물 선택지
//		A - 으름덩굴 - 생존
//		B - 투구꽃 - 사망
//		C - 천남성 - 사망