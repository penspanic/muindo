#pragma once
#include "Game.h"


class Situation_5 :public CScene
{
private:
	HBITMAP *hbit;
	HBITMAP *CurrentNarr;
	WORD SitState;


public:
	Situation_5();
	~Situation_5();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);
};

//	5) ����ó ������
//		A - �� �ӿ� ���� ���� �ܴ�. - ���
//		B - ������ ���� �ǿ����� �ܴ�. - ���
//		C - �غ��� ���� �ǿ����� �ܴ�. - ����