#pragma once
#include "SceneManager.h"
#include <Windows.h>


CSceneManager::CSceneManager()
{
	m_CurrentScene = nullptr;
}


CSceneManager::~CSceneManager()
{
	this->DeleteScene();
}

bool CSceneManager::ChangeScene(CScene * NewScene)
{
	this->DeleteScene();		// 현재의 씬을 해제한다.

	if (NewScene->Initialize() == false)
	{
		MessageBox(NULL, L"Scene Loaded Error!", L"Error!", MB_OK);
		return false;
	}
	m_CurrentScene = NewScene;
	return true;
}

void CSceneManager::DeleteScene()
{
	if (m_CurrentScene != nullptr)
	{
		m_CurrentScene->UnInitialize();

		delete m_CurrentScene;
		m_CurrentScene = nullptr;
	}
}

void CSceneManager::InputProcess()
{
	m_CurrentScene->InputProcess();
}

void  CSceneManager::Process()
{
	m_CurrentScene->Process();

}

void CSceneManager::Render(HDC hDC)
{
	m_CurrentScene->Render(hDC);
	//InvalidateRect(m_hWnd, NULL, FALSE);
}