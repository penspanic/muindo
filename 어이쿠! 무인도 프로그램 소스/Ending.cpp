#include "Ending.h"

Ending::Ending()
{
	hbit = new HBITMAP[7];
	CurrentNum = 0;
}

Ending::~Ending()
{

}

bool Ending::Initialize()
{
	hbit[0] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Ending/ending_1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[1] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Ending/ending_2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[2] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Ending/ending_3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[3] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Ending/ending_4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[4] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Ending/ending_5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[5] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Ending/ending_6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[6] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Ending/ending_7.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	for (size_t i = 0; i < 7; i++)
		IMAGE_CHECK(hbit[i]);

	CurrentBit = &hbit[0];
	return true;
}

void Ending::UnInitialize()
{
	delete[]hbit;
}

void Ending::InputProcess()
{
	if (CurrentNum < EndingSceneNum-1)
	{
		if (InputManager()->KeyDown(VK_RETURN))
		{
			CurrentBit = &hbit[++CurrentNum];

		}
	}

	if (CurrentNum == EndingSceneNum-1)
	{
		if (InputManager()->KeyDown(VK_LBUTTON) &&
			PtInRect(&CommonPtr()->GetMain(), InputManager()->GetMousePos()))
			SceneManager()->ChangeScene(new Main);

	}
}

void Ending::Process()
{

}

void Ending::Render(HDC hDC)
{
	DrawBitmap(hDC, 0, 0, *CurrentBit);
	if (CurrentNum != EndingSceneNum - 1)
		CommonPtr()->DrawEnter(hDC);
	if (CurrentNum == EndingSceneNum - 1)
		CommonPtr()->DrawMain(hDC);
}