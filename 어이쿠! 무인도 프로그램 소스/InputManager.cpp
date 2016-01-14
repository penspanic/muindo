#include "InputManager.h"


CInputManager::CInputManager()
{
	ZeroMemory(m_CurrKeysState, sizeof(m_CurrKeysState)); // 현재 키상태 초기화
	memcpy(m_PrevKeysState, m_CurrKeysState, sizeof(m_PrevKeysState));	// 이전의 키상태 초기화

	GetCursorPos(&m_LastCursorPos);
	GetCursorPos(&m_HowManyMouseMove);
	m_MouseMoved = FALSE;
}


CInputManager::~CInputManager()
{
}

BOOL CInputManager::Initialize(HWND hWnd)
{
	this->m_MainHWND = hWnd;
	this->InputUpdate();
	return TRUE;
}

BOOL CInputManager::KeyDown(DWORD vKeyType)
{
	if (!(m_PrevKeysState[vKeyType]))
	{
		if (m_CurrKeysState[vKeyType])
		{
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CInputManager::KeyPress(DWORD vKeyType)
{
	if (m_PrevKeysState[vKeyType])
	{
		if (m_CurrKeysState[vKeyType])
		{
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CInputManager::KeyUp(DWORD vKeyType)
{
	if (m_PrevKeysState[vKeyType])
	{
		if (!(m_CurrKeysState[vKeyType]))
		{
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CInputManager::KeyDown(INT KeyType)
{

	if (!(m_PrevKeysState[KeyType]))
	{
		if ((m_CurrKeysState[KeyType]))
		{
			return TRUE;
		}
	}
	return FALSE;
}

BOOL CInputManager::KeyPress(INT KeyType)
{
	if (m_PrevKeysState[KeyType])
	{
		if (m_CurrKeysState[KeyType])
		{
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CInputManager::KeyUp(INT KeyType)
{
	if (m_PrevKeysState[KeyType])
	{
		if (!(m_CurrKeysState[KeyType]))
		{
			return TRUE;
		}
	}

	return FALSE;
}

VOID CInputManager::InputUpdate()
{
	InputMemoryCopy();

	for (int i = 0; i < 256; ++i)
	{
		if (GetAsyncKeyState(i) & 0x8000)
		{
			m_CurrKeysState[i] = TRUE;
		}
		else
		{
			m_CurrKeysState[i] = FALSE;
		}
	}

	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(this->m_MainHWND, &pt);
	if (pt.x != m_LastCursorPos.x || pt.y != m_LastCursorPos.y)
	{
		this->m_HowManyMouseMove.x = pt.x - m_LastCursorPos.x;
		this->m_HowManyMouseMove.y = pt.y - m_LastCursorPos.y;
		this->m_MouseMoved = TRUE;
	}
	else
		this->m_MouseMoved = FALSE;
	GetCursorPos(&m_LastCursorPos);
	ScreenToClient(this->m_MainHWND, &m_LastCursorPos);
}

BOOL CInputManager::MouseMoved()
{
	return m_MouseMoved;
}

