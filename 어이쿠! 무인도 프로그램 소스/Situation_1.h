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

//	1) ù �ൿ ������
//		A - ���ڸ����� ü���� ȸ���Ѵ�. - ���
//		B - �ֺ��� �����Ѵ�. - ���
//		C - �״÷� �̵��Ѵ�. - ����