#pragma once
#include "Game.h"


class Situation_7 :public CScene
{
private:
	HBITMAP *hbit;
	HBITMAP *CurrentNarr;
	WORD SitState;


public:
	Situation_7();
	~Situation_7();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);
};
//
//7) ���� ������
//		A - ȶ���� �ǿ� ����. - ���
//		B - �Ҹ��� ũ�� ������. - ���
//		C - �ܰ��� ���߿� �ֵθ���. - ����