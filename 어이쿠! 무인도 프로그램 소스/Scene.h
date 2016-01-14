#pragma once
#include <Windows.h>


class CScene
{
public:
	CScene();
	~CScene();

	virtual bool Initialize() = 0;
	virtual void UnInitialize() = 0;
	virtual void InputProcess() = 0;
	virtual void Process() = 0;
	virtual void Render(HDC hDC) = 0;

	// �� �Լ����� ���� ���� �Լ��̹Ƿ� ��ӹ޴� 
	// Ŭ�������� ������ ���־�� ��.


};

