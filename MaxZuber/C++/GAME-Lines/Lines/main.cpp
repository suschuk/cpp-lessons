
#include "windows.h"
#include "windowsx.h"
#include "tchar.h"
#include "string"
#include "sstream"
#include "resource.h"
#include <ctime>
#include "define.h"

#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")



#include "Painter.h"

#include "Game.h"
#include "Nodes.h"


Painter& p = *Painter::getInstance();
//Game game;


static TCHAR szWindowClass[] = _T("UMLEditMainWnd");
static TCHAR szTitle[] = _T("UMLEdit");

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	srand(static_cast<unsigned>(time(0)));
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;

	//Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	WNDCLASSEX wcex = {0};

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style          = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = WndProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = hInstance;
	wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName   = szTitle;
	wcex.lpszClassName  = szWindowClass;
	wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_HAND));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("Win32 Guided Tour"), NULL);
		return 1;
	}

	hInst = hInstance; 
	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		1000, 1000, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("Win32 Guided Tour"), NULL);
		return 1;
	}



	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//Main message loop:
	MSG msg = {0};
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	GdiplusShutdown(gdiplusToken);

	return (int) msg.wParam;

}
//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Show message crackersfrom windowsx.h
//
void ClientResize(HWND hWnd, int nWidth, int nHeight);

struct dataS
{
	HWND hwnd;
	int x, y;
};


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static WNDPROC lpfnAboutDlgProc;
	static HDC hdc;
	static PAINTSTRUCT ps;


 static Game game;
 static RECT rc;
	switch (message)
	{
	case WM_CREATE:	
		ClientResize(hWnd, WIDTH * SIZE, SIZE * HEIGHT + 2 * HEIGHT);
		GetClientRect(hWnd, &rc);


		break;
	case WM_PAINT:	
		InvalidateRect(hWnd, &rc, TRUE);
		hdc = BeginPaint(hWnd, &ps);
		game.draw(p, hdc);	
		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
	case WM_LBUTTONDOWN:
		hdc = GetDC(hWnd);
		game.move(p, hdc,GET_X_LPARAM(lParam) / 50, GET_Y_LPARAM(lParam) / 50); 
		ReleaseDC(hWnd, hdc);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;

}

BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case  IDOK:
			MessageBox(hwnd, L"hi", L"hihi", MB_OK);
			EndDialog(hwnd, 0);
			return TRUE;
		}
		break;
	}
	return FALSE;
}


void ClientResize(HWND hWnd, int nWidth, int nHeight)
{

	RECT rcClient, rcWindow;

	POINT ptDiff;

	GetClientRect(hWnd, &rcClient);

	GetWindowRect(hWnd, &rcWindow);

	ptDiff.x = (rcWindow.right - rcWindow.left) - rcClient.right;

	ptDiff.y = (rcWindow.bottom - rcWindow.top) - rcClient.bottom;

	MoveWindow(hWnd,rcWindow.left, rcWindow.top, nWidth + ptDiff.x, nHeight + ptDiff.y, TRUE);

}