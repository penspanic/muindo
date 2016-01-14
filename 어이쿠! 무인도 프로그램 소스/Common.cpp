#include "Common.h"


Common::Common()
{
	hbit = new HBITMAP[4];
	SetRect(&A, 100, 400, 400, 670);
	SetRect(&B, 490, 400, 790, 670);
	SetRect(&C, 880, 400, 1180, 670);
	SetRect(&Return, 900, 530, 1200, 600);		// 처음으로
	SetRect(&Main, 900, 630, 1200, 700);        // 메인으로
	SetRect(&Exit, 0, 630, 300, 700);		    // 게임 종료
	SetRect(&Enter, 0, 600, 250, 700);          // Enter

	hbit[0] = (HBITMAP)LoadImage(NULL, L"./Bitmap/enter.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[1] = (HBITMAP)LoadImage(NULL, L"./Bitmap/return.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[2] = (HBITMAP)LoadImage(NULL, L"./Bitmap/m_out.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[3] = (HBITMAP)LoadImage(NULL, L"./Bitmap/mainButton.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	for (size_t i = 0; i < 4; i++)
		IMAGE_CHECK(hbit[i]);

	NarrMoveNum = 1;

	MainBGM = SoundManager()->OpenMp3(L"./Sound/MainBGM.mp3");
	DeadBGM = SoundManager()->OpenMp3(L"./Sound/DeadBGM.mp3");
	
}


Common::~Common()
{
	delete[]hbit;
	SoundManager()->Close(MainBGM);
	SoundManager()->Close(DeadBGM);
}

void Common::ResetCommon()
{
	PressEnter = false;
	SetRect(&Narration, 250, -150, 1050, 0);
	SetRect(&Enter, -250, 600, 0, 700);
	StartTime = GetTickCount();
	SoundManager()->Pause(DeadBGM); 
	SoundManager()->MoveStartPosition(MainBGM);
	SoundManager()->MoveStartPosition(DeadBGM);
	NarrMoveNum = 1;
}

void Common::NarrationMove()
{

	if (StartTime < GetTickCount() - 1000)
	{
		if (NarrMoveNum < 3)
			OffsetRect(&Narration, 0, 15);
		else if (NarrMoveNum < 6)
			OffsetRect(&Narration, 0, 17);
		else if (NarrMoveNum < 9)
			OffsetRect(&Narration, 0, 20);
		else if (NarrMoveNum < 12)
			OffsetRect(&Narration, 0, 22);
		else if (NarrMoveNum < 15)
			OffsetRect(&Narration, 0, -18);
		else if (NarrMoveNum < 18)
			OffsetRect(&Narration, 0, -16);
		else if (NarrMoveNum < 21)
			OffsetRect(&Narration, 0, -14);
		else if (NarrMoveNum < 24)
			OffsetRect(&Narration, 0, -12);
		else if (NarrMoveNum < 27)
			OffsetRect(&Narration, 0, 10);
		else if (NarrMoveNum < 30)
			OffsetRect(&Narration, 0, 12);
		else if (NarrMoveNum < 33)
			OffsetRect(&Narration, 0, 14);
		else if (NarrMoveNum < 36)
			OffsetRect(&Narration, 0, 16);
		else if (NarrMoveNum < 39)
			OffsetRect(&Narration, 0, -12);
		else if (NarrMoveNum < 42)
			OffsetRect(&Narration, 0, -10);
		else if (NarrMoveNum < 45)
			OffsetRect(&Narration, 0, -8);
		else if (NarrMoveNum < 48)
			OffsetRect(&Narration, 0, -6);
		else if (NarrMoveNum < 51)
			OffsetRect(&Narration, 0, 6);
		else if (NarrMoveNum < 54)
			OffsetRect(&Narration, 0, 8);
		else if (NarrMoveNum < 57)
			OffsetRect(&Narration, 0, 9);
		else if (NarrMoveNum < 60)
			OffsetRect(&Narration, 0, 10);
		else if (NarrMoveNum < 63)
			OffsetRect(&Narration, 0, -4);
		else if (NarrMoveNum < 66)
			OffsetRect(&Narration, 0, -2);
		else if (NarrMoveNum < 69)
			OffsetRect(&Narration, 0, 2);
		else if (NarrMoveNum < 72)
			OffsetRect(&Narration, 0, 4);
		if (NarrMoveNum == 72)
		{
			PressEnter = true;
		}

		NarrMoveNum++;
	}

	EnterMove();
}

void Common::EnterMove()
{
	if (Enter.left < -1)
	{
		OffsetRect(&Enter, 3, 0);
	}
	
}

void Common::DrawButton(HDC hDC, HBITMAP A, HBITMAP B, HBITMAP C)
{
	if (StartTime < GetTickCount() - 2000)
	{
		DrawTransparentBitmap(hDC,
			this->A.left, this->A.top, A, 255, 0, 255);
		DrawTransparentBitmap(hDC, this->B.left, this->B.top, B, 255, 0, 255);
		DrawTransparentBitmap(hDC, this->C.left, this->C.top, C, 255, 0, 255);
	}
}

void Common::DrawEnter(HDC hDC)
{
	DrawTransparentBitmap(hDC, Enter.left, Enter.top, hbit[0], 255, 0, 255);
}

void Common::DrawEnter(HDC hDC, bool move)
{
	if (move == false)
		DrawTransparentBitmap(hDC, 0, 600, hbit[0], 255, 0, 255);
	else
		DrawEnter(hDC);
}

void Common::DrawReturn(HDC hDC)
{
	DrawTransparentBitmap(hDC, Return.left - 30, Return.top - 10, hbit[1], 255, 0, 255);
}

void Common::DrawMain(HDC hDC)
{
	DrawTransparentBitmap(hDC, Main.left - 30, Main.top - 10, hbit[3], 255, 0, 255);
}

void Common::DrawExit(HDC hDC)
{
	DrawTransparentBitmap(hDC, Exit.left - 30, Exit.top - 10, hbit[2], 255, 0, 255);
}

void Common::PlayDeadBGM()
{
	SoundManager()->Play(DeadBGM);
}
