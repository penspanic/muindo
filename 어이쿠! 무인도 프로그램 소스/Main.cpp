#include "Main.h"
#pragma warning(disable : 4244)
extern HINSTANCE g_hInst;
Main::Main()
{

	hbit = new HBITMAP[6];
	Button = new RECT[5];
	StartState = ActionLess;
	QuitState = ActionLess;
	InfoState = InfoActionLess;
}


Main::~Main()
{

}

bool Main::Initialize()
{

	hbit[0] = (HBITMAP)LoadImage(NULL, L"./Bitmap/main.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[1] = (HBITMAP)LoadImage(NULL, L"./Bitmap/m_int.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[2] = (HBITMAP)LoadImage(NULL, L"./Bitmap/m_out.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[3] = (HBITMAP)LoadImage(NULL, L"./Bitmap/m_info.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[4] = (HBITMAP)LoadImage(NULL, L"./Bitmap/m_information.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hbit[5] = (HBITMAP)LoadImage(NULL, L"./Bitmap/deathcollect.bmp", IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	for (size_t i = 0; i < 6; i++)
		IMAGE_CHECK(hbit[i]);

	SetRect(&Button[0], 200, 430, 500, 500);		// 게임 시작
	SetRect(&Button[1], 200, 530, 500, 600);		// 게임 종료
	SetRect(&Button[2], 1150, 50, 1150 + 85, 50 + 85);	// Maker Info Button
	SetRect(&Button[3], 1280, 0, 1280 + 1280, 720); // Maker Information
	SetRect(&Button[4], 210, 610, 462, 690);  // Collection

	/*              Sound                */
	

	SoundManager()->Pause(CommonPtr()->GetDeadBGM());
	Sound1 = SoundManager()->OpenMp3(L"./Sound/InfoSound.mp3");
	
	SoundManager()->PlayRepeat(CommonPtr()->GetMainBGM());
	
	return true;
}

void Main::UnInitialize()
{
	delete[]hbit;
	delete[]Button;

	SoundManager()->Close(Sound1);
}

void Main::InputProcess()
{
	RectCheck();
}

void Main::Process()
{
	ButtonUpdate();
	InfoUpdate();
	if ((StartState == ButtonClicked) && (Button[0].top >= SCREEN_Y))
	{
		SoundManager()->Pause(CommonPtr()->GetMainBGM());
		SceneManager()->ChangeScene(new Intro);
	}
}

void Main::RectCheck()
{

	if (InputManager()->KeyDown(VK_LBUTTON))
	{
		if (PtInRect(&Button[0], InputManager()->GetMousePos())) // 마우스 커서가 버튼 위일때
			StartState = ButtonClicked;

		else if (PtInRect(&Button[1], InputManager()->GetMousePos()))
			PostQuitMessage(0);

		else if ((PtInRect(&Button[2], InputManager()->GetMousePos()))
			&& (InfoState != InfoMoveLeft))
		{
			if (InfoState == InfoActionLess)
				InfoState = InfoMoveLeft;
			else if (InfoState == InfoStoped)
				InfoState = InfoMoveRight;
		}
		else if (PtInRect(&Button[4], InputManager()->GetMousePos()))
			SceneManager()->ChangeScene(new CollectScene);
	}
}

void Main::ButtonUpdate()
{
#pragma region Start
	if (StartState == ActionLess&&InfoState != InfoStoped) // 움직임이 없을 때
	{
		if (PtInRect(&Button[0], InputManager()->GetMousePos()))
		{
			ButtonMinY = Button[0].top - 400;
			StartState = Rise; // 위로 움직이도록
		}
	}
	else if (StartState == Rise)
	{
		if (Button[0].top > ButtonMinY)
			OffsetRect(&Button[0], 0, -(0.2*(Button[0].top+50 - ButtonMinY) + 5));
		else
			StartState = Fall;
	}
	else if (StartState == Fall)
	{
		if (Button[0].top >= 430)
		{
			//Button[0] = { 200, 430, 500, 500 };
			SetRect(&Button[0], 200, 430, 500, 500);
			StartState = ActionLess;
		}
		else
			//OffsetRect(&Button[0], 0, 8);
			OffsetRect(&Button[0], 0, ((430-Button[0].top)*0.1)+1);
	}
	else if (StartState == ButtonClicked)
	{
		static float FallSpeed = 10.0f;
		OffsetRect(&Button[0], 0, FallSpeed);
		FallSpeed += FallSpeed*0.1f;
	}
#pragma endregion Start

#pragma region Quit
	if (PtInRect(&Button[1], InputManager()->GetMousePos()) && InfoState != InfoStoped)
	{
		ButtonMaxX = InputManager()->GetMousePos().x + 500;
		QuitState = MoveRight;
	}
	if (QuitState == MoveRight)
	{
		if (Button[1].left < ButtonMaxX)
			OffsetRect(&Button[1], (0.05*(ButtonMaxX - Button[0].left) + 1), 0);
		else
			QuitState = MoveLeft;
	}
	else
	{
		if (Button[1].left <= 200)
		{
			return;
		}
		if (Button[1].left > 200)
		{
			OffsetRect(&Button[1], -20, 0);
			if (Button[1].left < 200)
				SetRect(&Button[1], 200, 530, 500, 600);
		}
	}
#pragma endregion Quit
}


void Main::InfoUpdate()
{
	if (Button[3].left <= 0 && InfoState == InfoMoveLeft)
	{
		InfoState = InfoStoped;
		return;
	}
	if (InfoState == InfoMoveLeft)
	{
		SoundManager()->Play(Sound1);
		OffsetRect(&Button[3], -14, 0);
		if (Button[3].left<=0)
			OffsetRect(&Button[3], -Button[3].left, 0);
		
	}
	else if (InfoState == InfoMoveRight)
	{
		
		if (Button[3].left >= 1280)
		{
			SoundManager()->MoveStartPosition(Sound1);// 처음으로 옮김
			InfoState = InfoActionLess;
			return;
		}
		OffsetRect(&Button[3], 14, 0);
	}
}


void Main::Render(HDC hDC)
{
	DrawBitmap(hDC, 0, 0, hbit[0]);	// 배경
	DrawTransparentBitmap(hDC, Button[0].left - 30, Button[0].top - 10, hbit[1], 255, 0, 255);
	//Rectangle(hDC, Button[0]);
	DrawTransparentBitmap(hDC, Button[1].left - 30, Button[1].top - 10, hbit[2], 255, 0, 255);
	//Rectangle(hDC, Button[1]);
	DrawTransparentBitmap(hDC, Button[4].left - 10, Button[4].top - 10, hbit[5], 255, 0, 255);
	//Rectangle(hDC, Button[4]);
	DrawTransparentBitmap(hDC, Button[3].left, Button[3].top, hbit[4], 255, 0, 255);
	DrawTransparentBitmap(hDC, Button[2].left, Button[2].top, hbit[3], 255, 0, 255);//InfoButton
	//Rectangle(hDC, Button[2]);
	
}