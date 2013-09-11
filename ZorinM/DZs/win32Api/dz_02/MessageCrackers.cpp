#include "stdafx.h"
#include "MessageCrackers.h"

extern HINSTANCE hInst;

void OnPaint(HWND hWnd)
{
    PAINTSTRUCT ps = {0};
    HDC hDC;
    TCHAR title1[] = _T("LeftButtonClick: Red Line; RightButtonClick: Green Rectangle");
    TCHAR title2[] = _T("DblLeftButtonClick: Blue Ellipse; DblRightButtonClick: bmp");
    hDC=BeginPaint(hWnd, &ps);
    TextOut(hDC, 5, 5, title1, _tcslen(title1));
    TextOut(hDC, 5, 25, title2, _tcslen(title2));
    EndPaint(hWnd, &ps);
}

void OnMouseMove(HWND hWnd, int x, int y, UINT keyFlags)
{
    // HDC hdc = GetDC(hWnd); 
    // SetPixel(hdc, x, y, RGB(255,0,0)); 
    // ReleaseDC(hWnd, hdc);
}

void OnLButtonDown(HWND hWnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
    //std::wstringstream oss;
    //oss << "Left mouse click detected: x = " << x << ", y = " << y << std::endl;
    //MessageBox(hWnd, oss.str().c_str(), _T("Attention"), MB_OK);
	
	InvalidateRect(hWnd, 0, FALSE);
	HDC hdc;
	PAINTSTRUCT ps = {0};
	hdc = BeginPaint(hWnd, &ps);
	HPEN hPenOld;
	HPEN hLinePen;
	COLORREF qLineColor;

	// draw a red line
	qLineColor = RGB(255, 0, 0);
	hLinePen = CreatePen(PS_SOLID, 3, qLineColor);
	hPenOld = (HPEN)SelectObject(hdc, hLinePen);

	MoveToEx(hdc, 50, 50, NULL);
	LineTo(hdc, 500, 250);

	SelectObject(hdc, hPenOld);
	DeleteObject(hLinePen);

}

void OnRButtonDown(HWND hWnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
    // std::wstringstream oss;
    // oss << "Right mouse button released: x = " << x << ", y = " << y << std::endl;
    // MessageBox(hWnd, oss.str().c_str(), _T("Attention"), MB_OK);
	InvalidateRect(hWnd, 0, FALSE);
	HDC hdc;
	PAINTSTRUCT ps = {0};
	hdc = BeginPaint(hWnd, &ps);
	HPEN hPenOld;
	HPEN hLinePen;
	COLORREF qLineColor;

	qLineColor = RGB(0, 255, 0);
	hLinePen = CreatePen(PS_SOLID, 3, qLineColor);
	hPenOld = (HPEN)SelectObject(hdc, hLinePen);

	Rectangle(hdc, 50, 50, 500, 250);

	SelectObject(hdc, hPenOld);
	DeleteObject(hLinePen);
}

void LButtonDblClk(HWND hWnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	InvalidateRect(hWnd, 0, FALSE);
	HDC hdc;
	PAINTSTRUCT ps = {0};
	hdc = BeginPaint(hWnd, &ps);
	HPEN hPenOld;
	HPEN hLinePen;
	COLORREF qLineColor;
	
	qLineColor = RGB(0, 0, 255);
	hLinePen = CreatePen(PS_SOLID, 3, qLineColor);
	hPenOld = (HPEN)SelectObject(hdc, hLinePen);
	
	Ellipse(hdc, 50, 50, 500, 250);
	
	SelectObject(hdc, hPenOld);
	DeleteObject(hLinePen);
	//MessageBox(hWnd, _T("LButtonDblClk"), _T("Attention"), MB_OK);
}

void RButtonDblClk(HWND hWnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	HDC hdc;
	InvalidateRect(hWnd, 0, FALSE);
	HBITMAP hBitMap;
	hBitMap = (HBITMAP)LoadImage(hInst, L"sowa.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	
	hdc = GetDC(hWnd);
		{
			BITMAP bitmap;
			HDC hdcMem;
			HGDIOBJ oldBitMap;


			hdcMem = CreateCompatibleDC(hdc);
			oldBitMap = SelectObject(hdcMem, hBitMap);
			GetObject(hBitMap, sizeof(bitmap), &bitmap);

			BitBlt(hdc, 50, 50, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

			SelectObject(hdcMem, oldBitMap);
			DeleteDC(hdcMem);
		}
}

void OnDestroy(HWND hWnd)
{
    PostQuitMessage(0);
}

