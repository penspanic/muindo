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

//	4) �� ���� óġ ������
//		A - ������ ���� ���Ƴ���. - ���
//		B - ����� ������ ���´�. - ����
//		C - ���ڳ� �������� �ľ��. - ���