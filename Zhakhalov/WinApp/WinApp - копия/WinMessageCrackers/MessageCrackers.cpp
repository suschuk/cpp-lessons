#include "stdafx.h"
#include "MessageCrackers.h"
#include "WinMessageCrackers.h"

int _x;
int _y;

BOOL onCreate(HWND hWnd, LPCREATESTRUCT lpCreateStruct)
{
	MessageBox(hWnd, L"Rising", L"Rising", MB_OK);
	_x = 100;
	_y = 100;
	return true;
}

void onDestroy(HWND hWnd)
{
	MessageBox(hWnd, L"Falling", L"Falling", MB_OK);
}

void onPaint(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);

	Pen pen(Color(255, 0, 255, 0), 3);
	graphics.DrawRectangle(&pen, _x - 7, _y - 7, 15, 15);

	ReleaseDC(hWnd, hdc);
}

void onMouseMove(HWND hWnd, int x, int y, UINT keyFlags)
{
	if(keyFlags & MK_LBUTTON)
	{
		_x = x;
		_y = y;
	}
}

void onLButtonDown(HWND hWnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	_x = x;
	_y = y;
}

void onRButtonDown(HWND hWnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{

}

