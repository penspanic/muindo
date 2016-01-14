#pragma once

#include <Windows.h>
#include "Singleton.h"

class CInputManager : public Singleton<CInputManager>
{
public:
	CInputManager();
	~CInputManager();

	BOOL Initialize(HWND hWnd);

	BOOL KeyDown(DWORD vKeyType);// 인자로 가상 키를 전달하면 해당 키가 눌렸을 경우 한번만 참을 반환

	BOOL KeyPress(DWORD vKeyType);// 인자로 가상 키를 전달하면 해당 키가 눌려있을 때 항상 참을 반환

	BOOL KeyUp(DWORD vKeyType);// 인자로 가상 키를 전달하면 해당 키가 눌려있다 때어졌을 때 한번 참을 반환

	BOOL KeyDown(INT KeyType);// 인자로 보통 키를 전달하면 해당 키가 눌렸을 경우 한번만 참을 반환

	BOOL KeyPress(INT KeyType);// 인자로 보통 키를 전달하면 해당 키가 눌려있을 때 항상 참을 반환

	BOOL KeyUp(INT KeyType);// 인자로 보통 키를 전달하면 해당 키가 눌려있다 때어졌을 때 한번 참을 반환

	BOOL MouseMoved();// 마우스가 움직였으면 참을 반환.

	INT GetMouseX()	{ return this->m_LastCursorPos.x; }// 마우스의 X값 반환

	INT GetMouseY()	{ return this->m_LastCursorPos.y; }// 마우스의 Y값 반환

	POINT GetMousePos()	{ return this->m_LastCursorPos; }// 마우스의 위치 반환

	INT GetMouseMovedX()	{ return this->m_HowManyMouseMove.x; }// 마우스가 움직인 X거리 반환

	INT GetMouseMovedY()	{ return this->m_HowManyMouseMove.y; }// 마우스가 움직인 Y거리 반환


	VOID InputUpdate();// 메시지 루프에서 PrepareInput 함수 호출 전에 호출할 것

	VOID InputMemoryCopy() { memcpy(m_PrevKeysState, m_CurrKeysState, sizeof(m_PrevKeysState)); }// 현재 키 상태를 과거 키상태로 바꿈

private:
	HWND m_MainHWND; // 우리가 사용하고 있는 윈도우의 핸들이다.
	BOOL m_CurrKeysState[256]; // 현재 키의 상태를 보관한다.
	BOOL m_PrevKeysState[256]; // 업데이트 하기 전의 키 상태를 한번 더 저장한다.
	POINT m_LastCursorPos; // 현재 커서의 위치를 저장한다.
	POINT m_HowManyMouseMove; // 업데이트 전과 후에 마우스를 얼마나 움직였는지를 저장한다.
	BOOL m_MouseMoved; // 마우스가 움직였는지를 저장한다.
};

#define InputManager() Singleton<CInputManager>::InstancePtr()


// 가상키                    코드                         값 키
// VK_LBUTTON                01
// VK_RBUTTON                02
// VK_CANCEL                 03                           Ctrl - Break
// VK_MBUTTON                04
// VK_BACK                   08                           Backspace
// VK_TAB                    09                              Tab
// VK_CLEAR                  0C                             NumLock이 꺼져 있을 때의 5
// VK_RETURN                 0D                             Enter
// VK_SHIFT                  10                             Shift
// VK_CONTROL                11                             Ctrl
// VK_MENU                   12                             Alt
// VK_PAUSE                  13                             Pause
// VK_CAPITAL                14                             Caps Lock
// VK_ESCAPE                 1B                             Esc
// VK_SPACE                  20                             스페이스
// VK_PRIOR                  21                             PgUp
// VK_NEXT                   22                             PgDn
// VK_END                    23                             End
// VK_HOME                   24                             Home
// VK_LEFT                   25                             왼측 커서 이동키
// VK_UP                     26                             위쪽 커서 이동키
// VK_RIGHT                  27                             오른쪽 커서 이동키
// VK_DOWN                   28                             아래쪽 커서 이동키
// VK_SELECT                 29
// VK_PRINT                  2A
// VK_EXECUTE                2B
// VK_SNAPSHOT               2C                             Print Screen
// VK_INSERT                 2D                               Insert
// VK_DELETE                 2E                               Delete
// VK_HELP                   2F
// 30~39								                    숫자키 0~9
// 41~5A													영문자 A~Z
// VK_LWIN                   5B                             왼쪽 윈도우 키
// VK_RWIN                   5C                             오른쪽 윈도우 키
// VK_APP                    5D                             Application 키
// VK_NUMPAD0~VK_NUMPAD9     60~69                          숫자 패드의 0~9
// VK_MULTIPLY               6A                             숫자 패드의 *
// VK_ADD                    6B                             숫자 패드의 +
// VK_SEPARATOR              6C
// VK_SUBTRACT               6D                             숫자 패드의 -
// VK_DECIMAL                6E                             숫자 패드의 .
// VK_DIVIDE                 6F                             숫자 패드의 /
// VK_F1~VKF24               70~87                          평션키 F1~F24
// VK_NUMLOCK                90                             Num Lock
// VK_SCROLL                 91                             Scroll Lock