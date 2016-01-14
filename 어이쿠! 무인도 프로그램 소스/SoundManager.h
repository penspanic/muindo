#pragma once
#include "Singleton.h"

#include <Windows.h>
#include <mmsystem.h>
#include <Digitalv.h>

class CSoundManager:public Singleton<CSoundManager>
{
private:
	HWND m_hWnd;

public:
	CSoundManager();
	~CSoundManager();

	bool Initialize(HWND hWnd);

	DWORD OpenMp3(LPCWSTR ElementName);
	DWORD OpenWav(LPCWSTR ElementName);
	void Play(DWORD dwID);
	void PlayRepeat(DWORD dwID);
	void Stop(DWORD dwID);
	void Pause(DWORD dwID);
	void Close(DWORD dwID);
	void MoveStartPosition(DWORD dwID);
	DWORD MoveStartCurrentPosition(DWORD dwID);
	void SetCurrentPosition(DWORD dwID, DWORD dwPos);

};

#define SoundManager() Singleton<CSoundManager>::InstancePtr()

