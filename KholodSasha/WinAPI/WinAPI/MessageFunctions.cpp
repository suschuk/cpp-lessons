#include "stdafx.h"
#include "MessageFunctions.h"

void OnPaint(HWND hWnd)
{
    PAINTSTRUCT ps = {0};
    HDC hDC;
    TCHAR greeting[] = _T("Hello, World!");
    hDC=BeginPaint(hWnd, &ps);
    TextOut(hDC, 5, 5, greeting, _tcslen(greeting));
	using myNS::rects;
	for(auto it = rects.begin(); it != rects.end(); ++it)
	{
		Rectangle(hDC, it->left, it->top, it->right, it->bottom);
	}
	
    EndPaint(hWnd, &ps);
}

void OnDestroy(HWND hWnd)
{
    PostQuitMessage(0);
}

void OnLButtonDown(HWND hWnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	myNS::currentRect.left = x;
	myNS::currentRect.top = y;
}
void OnLButtonUp(HWND hWnd, int x, int y, UINT keyFlags)
{
	RECT rect;
	rect.left = myNS::currentRect.left;
	rect.top = myNS::currentRect.top;
	rect.right = x;
	rect.bottom = y;
	myNS::rects.push_back(rect);

	HDC hDC = GetDC(hWnd);
	Rectangle(hDC, myNS::currentRect.left, myNS::currentRect.top, x, y); 
	ReleaseDC(hWnd, hDC);
}