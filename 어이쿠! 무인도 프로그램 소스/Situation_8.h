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

//	8) ���� ������
//		A - ȶ���� �ǿ� ����. - ���
//		B - �Ҹ��� ũ�� ������. - ���
//		C - �ܰ��� ���߿� �ֵθ���. - ����65