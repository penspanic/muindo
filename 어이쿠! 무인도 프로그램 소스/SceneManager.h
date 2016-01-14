#pragma once
#include "Singleton.h"
#include"Scene.h"



class CSceneManager :public Singleton<CSceneManager>
{
private:
	CScene* m_CurrentScene;		// ÇöÀçÀÇ ¾À
	HWND m_hWnd;

public:
	CSceneManager();
	~CSceneManager();

	bool ChangeScene(CScene* NewScene);
	void DeleteScene();
	void InputProcess();
	void Process();
	void Render(HDC hDC);

};

#define SceneManager() Singleton<CSceneManager>::InstancePtr()
