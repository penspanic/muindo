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

//	3) �Ŀ� �Ĺ� ������
//		A - �������� - ����
//		B - ������ - ���
//		C - õ���� - ���