
#include "windows.h"
#include "windowsx.h"
#include "tchar.h"
#include <string>
#include "sstream"
#include <ctime>
#include <stdio.h>


#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

#include <atlbase.h>
CComModule _Module;
#include <atlcom.h>
#include <atlwin.h>
#include <Windows.h>

//#include "resource5.h"
#include "resource6.h"

#include <assert.h>
#include <sstream>
//#include "atlcontrols.h"
#include <Commctrl.h>




#include "define.h"
#include "Painter.h"
#include "Nodes.h"
#include "Game.h"
#include "score.h"
#include "ScoreDialog.h"

Painter& p = *Painter::getInstance();

static TCHAR szWindowClass[] = _T("LinesMainWnd");
static TCHAR szTitle[] = _T("Lines");
const std::vector<Score_>* scoreList; 
static TCHAR buffer[20];
HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK ScoreDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK GetNameDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{

	_Module.Init(NULL, hInstance);


	INITCOMMONCONTROLSEX iccex = {sizeof(iccex), ICC_TREEVIEW_CLASSES};

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
	wcex.hIcon          = LoadIcon(hInstance, IDI_APPLICATION);
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
	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT,
		1000, 1000, NULL, LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1) ), hInstance, NULL);

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

	_Module.Term();
	GdiplusShutdown(gdiplusToken);

	return (int) msg.wParam;

}
//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Show message crackersfrom windowsx.h
//
void ClientResize(HWND hWnd, int nWidth, int nHeight);



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static PAINTSTRUCT ps;
	static RECT rc;
	//static Gdiplus::Image* img = Gdiplus::Image::FromFile(L"../red.png", FALSE);
//	static Nodes nodes;
	static POINT p1, p2;
//	static bool dClick = false;
	static Game game;
	static int gameStatus = 0;
	static Score score;

	//static const std::vector<Score_>* scoreList; 


	switch (message)
	{
	case WM_CREATE:	
		ClientResize(hWnd, X::WIDTH * X::SIZE, X::SIZE * X::HEIGHT + 2 * X::HEIGHT);
		GetClientRect(hWnd, &rc);
		p.init(hWnd);
		game.start();
		SetTimer(hWnd, 0, 250, NULL);

		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case ID_SCORE_SHOWSCORETABLE:
			scoreList = &game.getScoreList();
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, ScoreDlgProc);
			break;
		}
		break;
	case WM_PAINT:
		BeginPaint(hWnd,&ps);
		/*InvalidateRect(hWnd, &rc, FALSE);*/
		game.draw();
		EndPaint(hWnd,&ps);
		break;
	case WM_LBUTTONDOWN:
		p1.x = GET_X_LPARAM(lParam) / X::SIZE;
		p1.y = GET_Y_LPARAM(lParam) / X::SIZE;

		
		gameStatus = game.chekGameOver();
		if(!gameStatus)
		{
			if(p1.y < X::HEIGHT)
				game.click(p1);
			game.draw();
		}
		break;
	case WM_TIMER:	
		gameStatus = game.chekGameOver();
		if(!gameStatus)
			game.draw();
		else if(gameStatus == X::TIME_END)
		{
			KillTimer(hWnd, 0);
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG3), hWnd, GetNameDlgProc);
			std::wstring tmp(buffer);
			game.addGameScore(std::string(tmp.begin(), tmp.end()));
			
		}
		else if(gameStatus == X::VICTORY)
		{
			KillTimer(hWnd, 0);
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, GetNameDlgProc);
			std::wstring tmp(buffer);
			game.addGameScore(std::string(tmp.begin(), tmp.end()));	
		}		
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;

}

BOOL CALLBACK ScoreDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	int i = 0;
	
	switch(msg)
	{
	case WM_INITDIALOG:
		for(auto it = scoreList->begin(); it != scoreList->end() && i < 5; ++it, ++i)
		{

			std::copy(it->name.begin(), it->name.end(), buffer );
			buffer[it->name.length()] = 0;
			CreateWindow(L"STATIC", buffer, WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 90, 100 + 20 * i, 250, 20, hwnd, 0, NULL, NULL); 
			wsprintf(buffer, L"%i", it->score);
			CreateWindow(L"STATIC", buffer, WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 340, 100 +  20 * i, 50, 20, hwnd, 0, NULL, NULL); 
		}
		return TRUE;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case  IDOK:

			EndDialog(hwnd, 0);
			return TRUE;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	}
	return FALSE;
}

BOOL CALLBACK GetNameDlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case  IDOK:
			GetDlgItemText(hwnd, IDC_EDIT1, buffer, 20);
			EndDialog(hwnd, 0);
			return TRUE;
		}
		break;	
	case WM_CLOSE:
		EndDialog(hwnd, 0);
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