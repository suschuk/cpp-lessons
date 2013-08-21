#include "stdafx.h"
extern HINSTANCE hInst;
extern TCHAR szTitle[];					// The title bar text
extern TCHAR szWindowClass[];			// the main window class name
INT_PTR CALLBACK	AboutProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);


// WndProc
void WndOnCommand(HWND hWnd, int id , HWND hWndCtrl, UINT codeNotify)
{
	switch (id)
	{
	case IDM_ABOUT:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, AboutProc);
		break;
	case ID_SHAPE_DIALOGBOX:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DialogProc);
		break;
	case IDM_EXIT:
		DestroyWindow(hWnd);
		break;
	}
}

void WndOnDestroy(HWND hWnd)
{
	PostQuitMessage(0);
}


// AboutProc

INT_PTR AboutOnInitDialog(HWND hWnd, HWND hFocus, LPARAM lParam)
{
	return (INT_PTR) TRUE;
}

INT_PTR AboutOnCommand(HWND hDlg, int id, HWND, UINT)
{
	switch(id)
	{
	case IDOK:
		EndDialog(hDlg, id);
		return (INT_PTR)TRUE;
	case IDCANCEL:
		EndDialog(hDlg, id);
		return (INT_PTR)TRUE;

	}
	return (INT_PTR) FALSE;
}


// DialogProc

HBITMAP hBitMap;
INT_PTR DlgOnInitDialog(HWND hWnd, HWND hFocus, LPARAM lParam)
{
	hBitMap = (HBITMAP)LoadImage(hInst, L"test.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	return (INT_PTR)TRUE;
}
INT_PTR DlgOnCommand(HWND hDlg, int id, HWND hWndCtrl, UINT codeNotify)
{
	HDC hdc;
	HWND hWnd = FindWindowEx(0,0, szWindowClass, szTitle);
	InvalidateRect(hWnd, 0, TRUE);
	UpdateWindow(hWnd);
	switch(id)
	{
	case IDOK:
		EndDialog(hDlg, id);
		return (INT_PTR)TRUE;
	case IDCANCEL:
		EndDialog(hDlg, id);
		return (INT_PTR)TRUE;
	case IDC_RADIO1:

		hdc = GetDC(hWnd);
		Ellipse(hdc,10,10, 50,50);
		ReleaseDC(hWnd,hdc);
		break;
	case IDC_RADIO2:
		hdc= GetDC(hWnd);
		Rectangle(hdc, 60, 80, 100, 10);
		ReleaseDC(hWnd, hdc);
		break;
	case IDC_RADIO3:
		hdc= GetDC(hWnd);
		Rectangle(hdc, 150, 150, 300, 10);
		ReleaseDC(hWnd, hdc);
		break;
	case IDC_RADIO4:
		hdc = GetDC(hWnd);
		{
			BITMAP bitmap;
			HDC hdcMem;
			HGDIOBJ oldBitMap;


			hdcMem = CreateCompatibleDC(hdc);
			oldBitMap = SelectObject(hdcMem, hBitMap);
			GetObject(hBitMap, sizeof(bitmap), &bitmap);

			BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);

			SelectObject(hdcMem, oldBitMap);
			DeleteDC(hdcMem);
		}
		break;
	}
	return (INT_PTR)FALSE;
}