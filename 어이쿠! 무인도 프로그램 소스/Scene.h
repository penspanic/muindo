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

	// 위 함수들은 순수 가상 함수이므로 상속받는 
	// 클래스에서 재정의 해주어야 함.


};

