#pragma once

#include <Windows.h>
#include "Singleton.h"

class CInputManager : public Singleton<CInputManager>
{
public:
	CInputManager();
	~CInputManager();

	BOOL Initialize(HWND hWnd);

	BOOL KeyDown(DWORD vKeyType);// ���ڷ� ���� Ű�� �����ϸ� �ش� Ű�� ������ ��� �ѹ��� ���� ��ȯ

	BOOL KeyPress(DWORD vKeyType);// ���ڷ� ���� Ű�� �����ϸ� �ش� Ű�� �������� �� �׻� ���� ��ȯ

	BOOL KeyUp(DWORD vKeyType);// ���ڷ� ���� Ű�� �����ϸ� �ش� Ű�� �����ִ� �������� �� �ѹ� ���� ��ȯ

	BOOL KeyDown(INT KeyType);// ���ڷ� ���� Ű�� �����ϸ� �ش� Ű�� ������ ��� �ѹ��� ���� ��ȯ

	BOOL KeyPress(INT KeyType);// ���ڷ� ���� Ű�� �����ϸ� �ش� Ű�� �������� �� �׻� ���� ��ȯ

	BOOL KeyUp(INT KeyType);// ���ڷ� ���� Ű�� �����ϸ� �ش� Ű�� �����ִ� �������� �� �ѹ� ���� ��ȯ

	BOOL MouseMoved();// ���콺�� ���������� ���� ��ȯ.

	INT GetMouseX()	{ return this->m_LastCursorPos.x; }// ���콺�� X�� ��ȯ

	INT GetMouseY()	{ return this->m_LastCursorPos.y; }// ���콺�� Y�� ��ȯ

	POINT GetMousePos()	{ return this->m_LastCursorPos; }// ���콺�� ��ġ ��ȯ

	INT GetMouseMovedX()	{ return this->m_HowManyMouseMove.x; }// ���콺�� ������ X�Ÿ� ��ȯ

	INT GetMouseMovedY()	{ return this->m_HowManyMouseMove.y; }// ���콺�� ������ Y�Ÿ� ��ȯ


	VOID InputUpdate();// �޽��� �������� PrepareInput �Լ� ȣ�� ���� ȣ���� ��

	VOID InputMemoryCopy() { memcpy(m_PrevKeysState, m_CurrKeysState, sizeof(m_PrevKeysState)); }// ���� Ű ���¸� ���� Ű���·� �ٲ�

private:
	HWND m_MainHWND; // �츮�� ����ϰ� �ִ� �������� �ڵ��̴�.
	BOOL m_CurrKeysState[256]; // ���� Ű�� ���¸� �����Ѵ�.
	BOOL m_PrevKeysState[256]; // ������Ʈ �ϱ� ���� Ű ���¸� �ѹ� �� �����Ѵ�.
	POINT m_LastCursorPos; // ���� Ŀ���� ��ġ�� �����Ѵ�.
	POINT m_HowManyMouseMove; // ������Ʈ ���� �Ŀ� ���콺�� �󸶳� ������������ �����Ѵ�.
	BOOL m_MouseMoved; // ���콺�� ������������ �����Ѵ�.
};

#define InputManager() Singleton<CInputManager>::InstancePtr()


// ����Ű                    �ڵ�                         �� Ű
// VK_LBUTTON                01
// VK_RBUTTON                02
// VK_CANCEL                 03                           Ctrl - Break
// VK_MBUTTON                04
// VK_BACK                   08                           Backspace
// VK_TAB                    09                              Tab
// VK_CLEAR                  0C                             NumLock�� ���� ���� ���� 5
// VK_RETURN                 0D                             Enter
// VK_SHIFT                  10                             Shift
// VK_CONTROL                11                             Ctrl
// VK_MENU                   12                             Alt
// VK_PAUSE                  13                             Pause
// VK_CAPITAL                14                             Caps Lock
// VK_ESCAPE                 1B                             Esc
// VK_SPACE                  20                             �����̽�
// VK_PRIOR                  21                             PgUp
// VK_NEXT                   22                             PgDn
// VK_END                    23                             End
// VK_HOME                   24                             Home
// VK_LEFT                   25                             ���� Ŀ�� �̵�Ű
// VK_UP                     26                             ���� Ŀ�� �̵�Ű
// VK_RIGHT                  27                             ������ Ŀ�� �̵�Ű
// VK_DOWN                   28                             �Ʒ��� Ŀ�� �̵�Ű
// VK_SELECT                 29
// VK_PRINT                  2A
// VK_EXECUTE                2B
// VK_SNAPSHOT               2C                             Print Screen
// VK_INSERT                 2D                               Insert
// VK_DELETE                 2E                               Delete
// VK_HELP                   2F
// 30~39								                    ����Ű 0~9
// 41~5A													������ A~Z
// VK_LWIN                   5B                             ���� ������ Ű
// VK_RWIN                   5C                             ������ ������ Ű
// VK_APP                    5D                             Application Ű
// VK_NUMPAD0~VK_NUMPAD9     60~69                          ���� �е��� 0~9
// VK_MULTIPLY               6A                             ���� �е��� *
// VK_ADD                    6B                             ���� �е��� +
// VK_SEPARATOR              6C
// VK_SUBTRACT               6D                             ���� �е��� -
// VK_DECIMAL                6E                             ���� �е��� .
// VK_DIVIDE                 6F                             ���� �е��� /
// VK_F1~VKF24               70~87                          ���Ű F1~F24
// VK_NUMLOCK                90                             Num Lock
// VK_SCROLL                 91                             Scroll Lock