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

//	2) �ļ� ������
//		A - ���簡 ���. - ����
//		B - ��� ���. - ���
//		C - �ؾ ���. - ���