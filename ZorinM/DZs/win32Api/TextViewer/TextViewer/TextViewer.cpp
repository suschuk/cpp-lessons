//////////////////////////////////////////////////////////////////////
// TextViewer.cpp
#include <windows.h>
#include "KWnd.h"
#include "KDocument.h"

#define FILE_NAME "D:\\README.TXT"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

KDocument doc;
//////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	if (!doc.Open(FILE_NAME))
		return 0;

	KWnd mainWnd(L"Text Viewer", hInstance, nCmdShow, WndProc, NULL,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, CS_HREDRAW | CS_VREDRAW,
		WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL);	

	while (GetMessage(&msg, NULL, 0, 0))  {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	TEXTMETRIC tm;
	int cxClient=0, cyClient=0;
	static int xInc, yInc;	

	switch (uMsg)
	{
	case WM_CREATE:
		hDC = GetDC(hWnd);
		GetTextMetrics(hDC, &tm);
		doc.Initialize(&tm); 
		ReleaseDC(hWnd, hDC);
		break;

	case WM_SIZE:
		hDC = GetDC(hWnd);
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		if (cxClient > 0)
			doc.ScrollSettings(hWnd, cxClient, cyClient);

		ReleaseDC(hWnd, hDC);
		break;

	case WM_VSCROLL:
		switch(LOWORD(wParam)) {
		case SB_LINEUP:
			yInc = -1;
			break;

		case SB_LINEDOWN:
			yInc = 1;
			break;

		case SB_PAGEUP:
			yInc = -(int)doc.vsi.nPage;
			break;

		case SB_PAGEDOWN:
			yInc = (int)doc.vsi.nPage;
			break;

		case SB_THUMBTRACK:
			yInc = HIWORD(wParam) - doc.vsi.nPos;
			break;

		default:
			yInc = 0;
		}

		doc.UpdateVscroll(hWnd, yInc);
		break;

	case WM_HSCROLL:
		switch(LOWORD(wParam)) {
		case SB_LINELEFT:
			xInc = -1;
			break;

		case SB_LINERIGHT:
			xInc = 1;
			break;

		case SB_PAGELEFT:
			xInc = -0.8 * doc.hsi.nPage;
			break;

		case SB_PAGERIGHT:
			xInc = 0.8 * doc.hsi.nPage;
			break;

		case SB_THUMBTRACK:
			xInc = HIWORD(wParam) - doc.hsi.nPos;
			break;

		default:
			xInc = 0;
		}

		doc.UpdateHscroll(hWnd, xInc);
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);

		doc.PutText(hWnd, hDC);

		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}
