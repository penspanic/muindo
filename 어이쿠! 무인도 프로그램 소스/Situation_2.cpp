#include "Situation_2.h"



Situation_2::Situation_2()
{
	hbit = new HBITMAP[15];
	SitState = Narr1;

}


Situation_2::~Situation_2()
{

}

bool Situation_2::Initialize()
{
	hbit[0] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/BackGround.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[1] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/Narr1.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[2] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/Narr2.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[3] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/ButtonA.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[4] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/ButtonB.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[5] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/ButtonC.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[6] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/BackGround_A.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[7] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/BackGround_B.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[8] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/BackGround_C.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[9] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/NarrA_1.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[10] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/NarrA_2.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[11] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/NarrB_1.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[12] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/NarrB_2.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[13] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/NarrC_1.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[14] = (HBITMAP)LoadImage(NULL, L"./Bitmap/sit_2/NarrC_2.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	for (size_t i = 0; i < 15; i++)
		IMAGE_CHECK(hbit[i]);

	CurrentNarr = &hbit[1];
	CommonPtr()->ResetCommon();

	return true;
}

void Situation_2::UnInitialize()
{
	delete[]hbit;
	//delete[]Button;
}

void Situation_2::InputProcess()
{
	if (InputManager()->KeyDown(VK_LBUTTON))
	{
		if (SitState == Narr2)
		{
			if (PtInRect(&CommonPtr()->GetA(), InputManager()->GetMousePos()))
			{
				CommonPtr()->ResetCommon();
				SitState = Sit_A_1;
			}
			else if (PtInRect(&CommonPtr()->GetB(), InputManager()->GetMousePos()))
			{
				Game()->SetCollectionCleared(2);
				CommonPtr()->ResetCommon();
				CommonPtr()->PlayDeadBGM();
				SitState = Sit_B_1;
			}
			else if (PtInRect(&CommonPtr()->GetC(), InputManager()->GetMousePos()))
			{
				Game()->SetCollectionCleared(3);
				CommonPtr()->ResetCommon();
				CommonPtr()->PlayDeadBGM();
				SitState = Sit_C_1;
			}
		}
		//////////////////////////////////////////////////////////////////////////
		else if (SitState == Sit_A_2)		// 맞는 선택지가 비어있음
		{
			
		}
		else if (SitState == Sit_B_2)
		{
			if (PtInRect(&CommonPtr()->GetReturn(), InputManager()->GetMousePos()))
				SceneManager()->ChangeScene(new Situation_1);
			else if (PtInRect(&CommonPtr()->GetMain(), InputManager()->GetMousePos()))
				SceneManager()->ChangeScene(new Main);
			else if (PtInRect(&CommonPtr()->GetExit(), InputManager()->GetMousePos()))
				PostQuitMessage(0);
		}
		else if (SitState == Sit_C_2)
		{
			if (PtInRect(&CommonPtr()->GetReturn(), InputManager()->GetMousePos()))
				SceneManager()->ChangeScene(new Situation_1);
			else if (PtInRect(&CommonPtr()->GetMain(), InputManager()->GetMousePos()))
				SceneManager()->ChangeScene(new Main);
			else if (PtInRect(&CommonPtr()->GetExit(), InputManager()->GetMousePos()))
				PostQuitMessage(0);
		}
	}
	if (InputManager()->KeyDown(VK_RETURN))	// 엔터
	{
		if (SitState == Narr1)
		{
			if (CommonPtr()->GetPressEnter() && InputManager()->KeyDown(VK_RETURN))	// 엔터
			{
				CurrentNarr = &hbit[2];
				CommonPtr()->SetStartTime(GetTickCount());
				SitState = Narr2;
			}
		}
		else if (CommonPtr()->GetPressEnter() && SitState == Sit_A_1)
		{
			SitState = Sit_A_2;
		}
		else if (CommonPtr()->GetPressEnter() && SitState == Sit_B_1)
		{
			SitState = Sit_B_2;
		}
		else if (CommonPtr()->GetPressEnter() && SitState == Sit_C_1)
		{
			SitState = Sit_C_2;
		}
		///////////////////////////////////////////////////
		else if (SitState == Sit_A_2) // 맞는 선택지에서 다음씬으로
		{
			SceneManager()->ChangeScene(new Situation_3);
		}
		else if (SitState == Sit_B_2)
		{

		}
		else if (SitState == Sit_C_2)
		{
			
		}
	}
}

void Situation_2::Process()
{
	CommonPtr()->NarrationMove();

}

void Situation_2::Render(HDC hDC)
{
	DrawBitmap(hDC, 0, 0, hbit[0]); //배경
	switch (SitState)
	{
	case Narr1:

		DrawTransparentBitmap(hDC, CommonPtr()->GetNarration().left, CommonPtr()->GetNarration().top, *CurrentNarr, 255, 0, 255);
		CommonPtr()->DrawEnter(hDC);

		break;
	case Narr2:
		DrawTransparentBitmap(hDC, CommonPtr()->GetNarration().left, CommonPtr()->GetNarration().top, *CurrentNarr, 255, 0, 255);
		CommonPtr()->DrawButton(hDC, hbit[3], hbit[4], hbit[5]);

		break;
		////////////////////////////////// 맞는 선택지_2에서 DrawEnter();
	case Sit_A_1:
		DrawBitmap(hDC, 0, 0, hbit[6]);
		DrawTransparentBitmap(hDC, CommonPtr()->GetNarration().left, CommonPtr()->GetNarration().top, hbit[9], 255, 0, 255);
		CommonPtr()->DrawEnter(hDC);
		break;
	case Sit_A_2:
		DrawBitmap(hDC, 0, 0, hbit[6]);
		DrawTransparentBitmap(hDC, CommonPtr()->GetNarration().left, CommonPtr()->GetNarration().top, hbit[10], 255, 0, 255);
		CommonPtr()->DrawEnter(hDC);
		break;
	case Sit_B_1:
		DrawBitmap(hDC, 0, 0, hbit[7]);	// 배경
		DrawTransparentBitmap(hDC, CommonPtr()->GetNarration().left, CommonPtr()->GetNarration().top, hbit[11], 255, 0, 255);
		CommonPtr()->DrawEnter(hDC);
		break;
	case Sit_B_2:
		DrawBitmap(hDC, 0, 0, hbit[7]);
		DrawTransparentBitmap(hDC, CommonPtr()->GetNarration().left, CommonPtr()->GetNarration().top, hbit[12], 255, 0, 255);
		CommonPtr()->DrawReturn(hDC);
		CommonPtr()->DrawExit(hDC);
		CommonPtr()->DrawMain(hDC);
		break;
	case Sit_C_1:
		DrawBitmap(hDC, 0, 0, hbit[8]);
		DrawTransparentBitmap(hDC, CommonPtr()->GetNarration().left, CommonPtr()->GetNarration().top, hbit[13], 255, 0, 255);
		CommonPtr()->DrawEnter(hDC);
		break;
	case Sit_C_2:
		DrawBitmap(hDC, 0, 0, hbit[8]);
		DrawTransparentBitmap(hDC, CommonPtr()->GetNarration().left, CommonPtr()->GetNarration().top, hbit[14], 255, 0, 255);
		CommonPtr()->DrawReturn(hDC);
		CommonPtr()->DrawExit(hDC);
		CommonPtr()->DrawMain(hDC);
		break;

	}


}