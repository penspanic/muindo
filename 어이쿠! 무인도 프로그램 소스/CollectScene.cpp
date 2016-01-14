#include "CollectScene.h"

#pragma warning(disable : 4805)

CollectScene::CollectScene()
{
	hbit = new HBITMAP[4];
	Scene = new HBITMAP[14];
}


CollectScene::~CollectScene()
{
}

bool CollectScene::Initialize()
{
	hbit[0] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Collect/collections.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[1] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Collect/lock.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[2] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Collect/back.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[3] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Collect/OnMouse.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	for (size_t i = 0; i < 4; i++)
		IMAGE_CHECK(hbit[i]);

	Scene[0] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_1/BackGround_A.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[1] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_1/BackGround_B.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[2] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_2/BackGround_B.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[3] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_2/BackGround_C.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[4] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_3/BackGround_B.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[5] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_3/BackGround_C.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[6] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_4/BackGround_A.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[7] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_4/BackGround_C.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[8] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_5/BackGround_A.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[9] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_5/BackGround_B.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[10] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_6/BackGround_A.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[11] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_6/BackGround_C.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[12] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_7/BackGround_A.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	Scene[13] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Sit_7/BackGround_B.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	for (size_t i = 0; i < 14; i++)
		IMAGE_CHECK(Scene[i]);

	SetRect(&Collection[0], 9, 8, 9 + LOCK_X, 8 + LOCK_Y);
	SetRect(&Collection[1], 192, 8, 192+ LOCK_X, 8 + LOCK_Y);
	SetRect(&Collection[2], 375, 8, 375 + LOCK_X, 8 + LOCK_Y);
	SetRect(&Collection[3], 558, 8, 558 + LOCK_X, 8 + LOCK_Y);
	SetRect(&Collection[4], 741, 8, 741 + LOCK_X, 8 + LOCK_Y);
	SetRect(&Collection[5], 924, 8, 924 + LOCK_X, 8 + LOCK_Y);
	SetRect(&Collection[6], 1107, 8, 1107 + LOCK_X, 8 + LOCK_Y);
	SetRect(&Collection[7], 9, 298, 9 + LOCK_X, 298 + LOCK_Y);
	SetRect(&Collection[8], 192, 298, 192 + LOCK_X, 298 + LOCK_Y);
	SetRect(&Collection[9], 375, 298, 375 + LOCK_X, 298 + LOCK_Y);
	SetRect(&Collection[10], 558, 298, 558 + LOCK_X, 298 + LOCK_Y);
	SetRect(&Collection[11], 741, 298, 741 + LOCK_X, 298 + LOCK_Y);
	SetRect(&Collection[12], 924, 298, 924 + LOCK_X, 298 + LOCK_Y);
	SetRect(&Collection[13], 1107, 298, 1107 + LOCK_X, 298 + LOCK_Y);

	SetRect(&Back, 1100, 650, 1100 + 170, 650 + 51);

	
	Selected = false;
	for (size_t i = 0; i < 14; i++)
		SceneShow[i] = false;

	return true;
}

void CollectScene::UnInitialize()
{
	delete[] hbit;
	delete[] Scene;
}

void CollectScene::InputProcess()
{
	if (InputManager()->KeyDown(VK_LBUTTON))
	{
		if (PtInRect(&Back, InputManager()->GetMousePos()) && Selected == false)
			SceneManager()->ChangeScene(new class Main);
		else if (PtInRect(&Back, InputManager()->GetMousePos()) && Selected == true)
		{
			for (size_t i = 0; i < 14; i++)
				SceneShow[i] = false;
			Selected = false;
		}
		for (size_t i = 0; i < 14; i++)
		{
			if (PtInRect(&Collection[i], InputManager()->GetMousePos())
				&& Game()->GetCollectionCleared(i) == true)
			{
				SceneShow[i] = true;
				Selected = true;
			}
		}
	}


}

void CollectScene::Process()
{

}

void CollectScene::Render(HDC hDC)
{
	
	DrawBitmap(hDC, 0, 0, hbit[0]);

	for (size_t i = 0; i < 14; i++)
	{
		if (Game()->GetCollectionCleared(i) == false)
			DrawBitmap(hDC, Collection[i].left, Collection[i].top, hbit[1]);
	}
	DrawTransparentBitmap(hDC, Back.left, Back.top, hbit[2], 255, 0, 255);

	for (size_t i = 0; i < 14; i++)
	{
		if (Game()->GetCollectionCleared(i) == true && PtInRect(&Collection[i], InputManager()->GetMousePos()))
			DrawTransparentBitmap(hDC, Collection[i].left, Collection[i].top, hbit[3],255,0,255);
	}

	for (size_t i = 0; i < 14; i++)
	{
		if (SceneShow[i] == true)
		{
			DrawBitmap(hDC, 0, 0, Scene[i]);
			DrawTransparentBitmap(hDC, Back.left, Back.top, hbit[2], 255, 0, 255);
			
		}
	}
}