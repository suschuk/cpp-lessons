#include "MsgCrack.h"
#include "stdafx.h"
#include <windowsx.h>
#include "resource.h"

void OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch (id)
		{
		case ID_FILE_ELLIPSE:
			{
			HDC hdc = GetDC(hWnd);
			Ellipse(hdc, 0,0, 200,200);
			ReleaseDC(hWnd, hdc);
			}
			break;	
		case ID_FILE_SQUARE:
			{
			HDC hdc = GetDC(hWnd);
			Rectangle(hdc, 300,0, 500,200);
			ReleaseDC(hWnd, hdc);
			}
			break;	
		case ID_FILE_RECTANGLE:
			{
			HDC hdc = GetDC(hWnd);
			Rectangle(hdc, 600,0, 800,400);
			ReleaseDC(hWnd, hdc);
			}
			break;	
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		}
}

void OnDestroy(HWND hWnd)
{
	PostQuitMessage(0);
}
