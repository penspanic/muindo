#pragma once
#include "Game.h"
#include "function.h"

#define LOCK_X 164
#define LOCK_Y 278

class CollectScene:public CScene
{
private:
        const int ObtainableSceneNum = 14;
	HBITMAP *hbit;
	HBITMAP *Scene;
	RECT Collection[ObtainableSceneNum];
	
	RECT Main;
	RECT Back;

	bool Selected;
	bool SceneShow[ObtainableSceneNum];

public:
	CollectScene();
	~CollectScene();

	bool Initialize();
	void UnInitialize();
	void InputProcess();
	void Process();
	void Render(HDC hDC);

};

