#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include "Game.h"


void DrawBitmap(HDC hDC, int x, int y, HBITMAP hBit);	//��Ʈ�� ���

void DrawTransparentBitmap(HDC hDC, int x, int y, HBITMAP hBit, int r, int g, int b); // ���� ����

void DrawStretchBitmap(HDC hDC, int x, int y, int Width, int Height, HBITMAP hBit);

void RectSet(HWND hWnd, RECT &RECTNAME, int RECTx, int RECTy, int RECTex, int RECTey);// ���� ����

void Rectangle(HDC hDC, RECT Rect);


