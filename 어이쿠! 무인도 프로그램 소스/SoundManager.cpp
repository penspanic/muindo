#include "SoundManager.h"


CSoundManager::CSoundManager()
{
	
}


CSoundManager::~CSoundManager()
{

}

bool CSoundManager::Initialize(HWND hWnd)
{
	m_hWnd = hWnd;
	return true;
}

DWORD CSoundManager::OpenMp3(LPCWSTR ElementName)
{
	MCI_OPEN_PARMS mciOpenParms;
	MCIERROR mciError;
	mciOpenParms.lpstrDeviceType = L"MPEGVideo";
	mciOpenParms.lpstrElementName = ElementName;
	mciError = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,
		(DWORD)&mciOpenParms);
	//if (mciError)
		//MessageBox(m_hWnd, L"Open Error!!", L"Error", MB_OK);
	return mciOpenParms.wDeviceID;
}

DWORD CSoundManager::OpenWav(LPCWSTR ElementName)
{
	MCI_OPEN_PARMS mciOpenParms;
	MCIERROR mciError;
	mciOpenParms.lpstrDeviceType = L"waveaudio";
	mciOpenParms.lpstrDeviceType = ElementName;
	mciError = mciSendCommand(NULL, MCI_OPEN,
		MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mciOpenParms);
	if (mciError)
		MessageBox(m_hWnd, L"Open Error!!", L"Error", MB_OK);
	return mciOpenParms.wDeviceID;
}

void CSoundManager::Play(DWORD dwID)
{
	MCI_PLAY_PARMS mciPlayParms;
	MCIERROR mciError;
	mciPlayParms.dwCallback = NULL;
	mciError = mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY,
		(DWORD)&mciPlayParms);
	//if (mciError)
		//MessageBox(m_hWnd, L"Play Error!!", L"Error", MB_OK);
}

void CSoundManager::PlayRepeat(DWORD dwID)
{
	MCI_PLAY_PARMS mciPlayParms;
	MCIERROR mciError;
	mciPlayParms.dwCallback = NULL;
	mciError = mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY | MCI_DGV_PLAY_REPEAT,
		(DWORD)&mciPlayParms);
	//if (mciError)
		//MessageBox(m_hWnd, L"Play Error!!", L"Error", MB_OK);
}

void CSoundManager::Pause(DWORD dwID)
{
	MCI_GENERIC_PARMS mciGenericParms;
	MCIERROR mciError;
	mciError = mciSendCommand(dwID, MCI_PAUSE, MCI_WAIT,
		(DWORD)&mciGenericParms);
	if (mciError)
		MessageBox(m_hWnd, L"Pause Error!!", L"Error", MB_OK);
}

void CSoundManager::Close(DWORD dwID)
{
	MCI_GENERIC_PARMS mciGenericParms;
	MCIERROR mciError;
	mciError = mciSendCommand(dwID, MCI_CLOSE, MCI_WAIT,
		(DWORD)&mciGenericParms);
	//if (mciError)
	//	MessageBox(m_hWnd, L"Resume Error!!", L"Error", MB_OK);
}

void CSoundManager::MoveStartPosition(DWORD dwID)
{
	MCI_SEEK_PARMS mciSeekParms;
	MCIERROR mciError;
	mciError = mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START,
		(DWORD)&mciSeekParms);
	if (mciError)
		MessageBox(m_hWnd, L"Set Length Format Error!!", L"Error", MB_OK);
}

DWORD CSoundManager::MoveStartCurrentPosition(DWORD dwID)
{
	MCI_STATUS_PARMS mciStatusParms;
	MCIERROR mciError;
	mciStatusParms.dwItem = MCI_STATUS_POSITION;
	mciError = mciSendCommand(dwID, MCI_STATUS, MCI_STATUS_ITEM,
		(DWORD)&mciStatusParms);
	if (mciError)
		MessageBox(m_hWnd, L"Status Position Error!!", L"Error", MB_OK);
	return mciStatusParms.dwReturn;
}

void CSoundManager::SetCurrentPosition(DWORD dwID, DWORD dwPos)
{
	MCI_SEEK_PARMS mciSeekParms;
	MCIERROR mciError;
	mciSeekParms.dwTo = dwPos;
	mciError = mciSendCommand(dwID, MCI_SEEK, MCI_TO, (DWORD)&mciSeekParms);
	if (mciError)
		MessageBox(m_hWnd, L"Set Length Format Error!!", L"Error", MB_OK);
}