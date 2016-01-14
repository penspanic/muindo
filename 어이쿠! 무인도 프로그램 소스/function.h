#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include "Game.h"


void DrawBitmap(HDC hDC, int x, int y, HBITMAP hBit);	//비트맵 출력

void DrawTransparentBitmap(HDC hDC, int x, int y, HBITMAP hBit, int r, int g, int b); // 투명 츨력

void DrawStretchBitmap(HDC hDC, int x, int y, int Width, int Height, HBITMAP hBit);

void RectSet(HWND hWnd, RECT &RECTNAME, int RECTx, int RECTy, int RECTex, int RECTey);// 영역 설정

void Rectangle(HDC hDC, RECT Rect);


