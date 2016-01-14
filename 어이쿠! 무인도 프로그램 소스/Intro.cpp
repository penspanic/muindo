#include "Intro.h"


Intro::Intro()
{

	hbit = new HBITMAP[7];
	Button = new RECT[2];
	CurrentNum = 1;
}


Intro::~Intro()
{

}

bool Intro::Initialize()
{
	// ∫Ò∆Æ∏  ∑ŒµÂ
	hbit = new HBITMAP[7];
	hbit[0] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Intro/Intro_1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[1] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Intro/Intro_2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[2] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Intro/Intro_3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[3] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Intro/Intro_4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[4] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Intro/Intro_5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[5] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Intro/Intro_6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[6] = (HBITMAP)LoadImage(NULL, L"./Bitmap/Intro/Intro_7.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	for (size_t i = 0; i < 7; i++)
		IMAGE_CHECK(hbit[i]);

	CurrentBit = &hbit[0];
	//StartTime = GetTickCount();
	Sound1 = SoundManager()->OpenMp3(L"./Sound/thunder.mp3");
	Sound2 = SoundManager()->OpenMp3(L"./Sound/wave.mp3");
	
	return true;
}

void Intro::UnInitialize()
{
	delete[]hbit;
	SoundManager()->Close(Sound1);
	SoundManager()->Close(Sound2);
}

void Intro::InputProcess()
{
	if (CurrentNum <= IntroSceneNum)
	{
		if (InputManager()->KeyDown(VK_RETURN))
		{
			CurrentBit = &hbit[CurrentNum++];

		}
	}

	if (CurrentNum > IntroSceneNum)
	{
		if (InputManager()->KeyDown(VK_RETURN))
			SceneManager()->ChangeScene(new Situation_1);
	}


}

void Intro::Process()
{
	
	if (CurrentNum == 4)
		SoundManager()->Play(Sound1);
	else if (CurrentNum == 5)
	{
		SoundManager()->Close(Sound1);
		SoundManager()->Play(Sound2);
	}
		
}

void Intro::Render(HDC hDC)
{
	DrawBitmap(hDC, 0, 0, *CurrentBit);	// Intro
	CommonPtr()->DrawEnter(hDC,false);
}
