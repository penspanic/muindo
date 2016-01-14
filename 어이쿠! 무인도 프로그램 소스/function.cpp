#include "function.h"

extern HWND hWnd;
void DrawBitmap(HDC hDC, int x, int y, HBITMAP hBit)//비트맵 출력
{
	HDC MemDC;
	HBITMAP OldBitmap;
	BITMAP bit;

	MemDC = CreateCompatibleDC(hDC);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);
	int bx = bit.bmWidth;
	int by = bit.bmHeight;

	BitBlt(hDC, x, y, bx, by, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}

void DrawTransparentBitmap(HDC hDC, int x, int y, HBITMAP hBit, int r, int g, int b)//투명화할 부분 (r,g,b), 비트맵 출력
{
	HDC MemDC;
	HBITMAP OldBitmap;
	BITMAP bit;

	MemDC = CreateCompatibleDC(hDC);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);
	int bx = bit.bmWidth;
	int by = bit.bmHeight;

	GdiTransparentBlt(hDC, x, y, bx, by, MemDC, 0, 0, bx, by, RGB(r, g, b));

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}




void DrawStretchBitmap(HDC hDC, int x, int y, int Width, int Height, HBITMAP hBit)
{
	HDC MemDC;
	HBITMAP OldBitmap;
	BITMAP bit;

	MemDC = CreateCompatibleDC(hDC);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);
	

	GetObject(hBit, sizeof(BITMAP), &bit);
	int bx = bit.bmWidth;
	int by = bit.bmHeight;

	StretchBlt(hDC, 0, 0, Width, Height, MemDC, 0, 0, bx, by, SRCCOPY);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);

}


void RectSet(HWND hWnd, RECT &RECTNAME, int Left, int Top, int Right, int Bottom)
{
	RECT ClientRect;
	GetClientRect(hWnd, &ClientRect);



	SetRect(&RECTNAME, ClientRect.left + Left, ClientRect.top + Top,
		ClientRect.left + Right, ClientRect.top + Bottom);
}

void Rectangle(HDC hDC, RECT Rect)
{
	Rectangle(hDC, Rect.left, Rect.top, Rect.right, Rect.bottom);
}

