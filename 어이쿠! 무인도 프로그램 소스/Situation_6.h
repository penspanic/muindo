#pragma once
#include "Game.h"


class Situation_6 :public CScene
{
private:
	HBITMAP *hbit;
	HBITMAP *CurrentNarr;
	WORD SitState;


public:
	Situation_6();
	~Situation_6();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);
};
//
//6) ���� ������
//		A - �綼������ �������� �帥��. - ���
//		B - ���Ա����� �����ϰ� �Ǿ�ö���. - ����
//		C - �η縶�������� ������ �帥��. - ���