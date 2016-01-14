#pragma once 

#include <Windows.h>

#include "Singleton.h"

#include "SceneManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "Common.h"
/*       Scene       */
#include "Main.h"
#include "CollectScene.h"
#include "Intro.h"
#include "Situation_1.h"
#include "Situation_2.h"
#include "Situation_3.h"
#include "Situation_4.h"
#include "Situation_5.h"
#include "Situation_6.h"
#include "Situation_7.h"
#include "Situation_8.h"
#include "Ending.h"
/*                   */
#define SCREEN_X 1280
#define SCREEN_Y 720
enum SituationState { Narr1 = 0, Narr2, Sit_A_1, Sit_A_2, Sit_B_1, Sit_B_2, Sit_C_1, Sit_C_2 };

class CGame :public Singleton<CGame>
{
private:
	HWND m_hWnd;
	int CollectionCleared[14];

public:
	CGame();
	~CGame();

	bool Initialize(HWND g_hWnd);	// 초기화
	void UnInitialize();		// 해제
	void InputProcess();		// 입력
	void Process();				// 업데이트
	void Render();

	void FileCheck();
    
	
	HWND GetWndHandle(){ return m_hWnd; }
	int GetCollectionCleared(int i){ return CollectionCleared[i]; }
	void SetCollectionCleared(int i){ CollectionCleared[i] = 1; }
};

#define Game() Singleton<CGame>::InstancePtr()

#define IMAGE_CHECK(a) if(a==NULL) MessageBox(Game()->GetWndHandle(), L"Image Loaded Error!", L"Error", MB_OK);