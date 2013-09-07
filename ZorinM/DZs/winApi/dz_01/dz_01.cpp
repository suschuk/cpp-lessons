// dz_01.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "dz_01.h"
#define MAX_LOADSTRING 100


// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
LPTSTR testTitle = _T("test test test");
bool ifStart		= false;
bool ifFinish		= false;
bool bDrawLine		= true;
bool bDrawRect		= false;
bool bDrawEllipse	= false;
bool bDrawBMP		= false;

int startX, startY, finishX, finishY;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DZ_01, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DZ_01));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}


bool LoadBMP(LPCWSTR szFileName, HDC hWinDC)
{
	// Load the bitmap image file
	HBITMAP hBitmap;
	hBitmap = (HBITMAP)::LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	// verify that image was loaded
	if (hBitmap == NULL)
	{
		::MessageBox(NULL, __T("LoadImage Failed"), __T("Error"), MB_OK);
		return false;
	}

	// create a device context that is compatible with the window
	HDC hLocalDC;
	hLocalDC = ::CreateCompatibleDC(hWinDC);
	// verify that the device context was created
	if(hLocalDC == NULL)
	{
		::MessageBox(NULL, __T("CreateCompatibleDC Failed"), __T("Error"), MB_OK);
		return false;
	}

	// get the bitmap's parameters and verify the get
	BITMAP qBitmap;
	int iReturn;
	iReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP), reinterpret_cast<LPVOID>(&qBitmap));
	if(!iReturn)
	{
		::MessageBox(NULL, __T("GetObbject Failed"), __T("Error"), MB_OK);
		return false;
	}

	// Select the loaded bitmap into the device context
	HBITMAP hOldBmp;
	hOldBmp = (HBITMAP)::SelectObject(hLocalDC, hBitmap);

	if(hOldBmp == NULL)
	{
		::MessageBox(NULL, __T("SelectObbject Failed"), __T("Error"), MB_OK);
		return false;
	}

	// blit the dc which holds the bitmapp iinto the windows's dc
	BOOL qRetBlit = ::BitBlt(hWinDC, 0, 0, qBitmap.bmWidth, qBitmap.bmHeight, hLocalDC, 0, 0, SRCCOPY);

	if(!qRetBlit)
	{
		::MessageBox(NULL, __T("Blit Failed"), __T("Error"), MB_OK);
		return false;
	}

	// unitialize and deallocete resources
	::SelectObject(hLocalDC, hOldBmp);
	::DeleteDC(hLocalDC);
	::DeleteObject(hBitmap);

	return true;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DZ_01));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_DZ_01);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_MOUSEMOVE:
		if (ifStart == true && ifFinish == false && !bDrawBMP)
		{
			finishX = LOWORD(lParam);
			finishY = HIWORD(lParam);
			InvalidateRect(hWnd, 0, TRUE);
		}

		break;

	case WM_LBUTTONDOWN:
		if(ifStart == false)
		{
			ifStart = true;
			startX = LOWORD(lParam);
			startY = HIWORD(lParam);
		}
		else if(ifStart == true)
		{
			ifFinish = true;

			finishX = LOWORD(lParam);
			finishY = HIWORD(lParam);
			InvalidateRect(hWnd, 0, FALSE);
		}
		break;

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_LINE:
			bDrawLine		= true;
			bDrawRect		= false;
			bDrawEllipse	= false;
			bDrawBMP		= false;
			break;
		
		case IDM_RECT:
			bDrawLine		= false;
			bDrawRect		= true;
			bDrawEllipse	= false;
			bDrawBMP		= false;
			break;
		
		case IDM_ELLIPSE:
			bDrawLine		= false;
			bDrawRect		= false;
			bDrawEllipse	= true;
			bDrawBMP		= false;
			break;

		case IDM_BMP:
			bDrawLine		= false;
			bDrawRect		= false;
			bDrawEllipse	= false;
			bDrawBMP		= true;
			InvalidateRect(hWnd, 0, TRUE);
			break;

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		HPEN hPenOld;
		HPEN hLinePen;
		COLORREF qLineColor;

		if(bDrawLine)
		{
			// draw a red line
			qLineColor = RGB(255, 0, 0);
			hLinePen = CreatePen(PS_SOLID, 3, qLineColor);
			hPenOld = (HPEN)SelectObject(hdc, hLinePen);

			MoveToEx(hdc, startX, startY, NULL);
			LineTo(hdc, finishX, finishY);

			SelectObject(hdc, hPenOld);
			DeleteObject(hLinePen);
		}
		if(bDrawRect)
		{
			// draw a green rectangle line
			qLineColor = RGB(0, 255, 0);
			hLinePen = CreatePen(PS_SOLID, 3, qLineColor);
			hPenOld = (HPEN)SelectObject(hdc, hLinePen);

			Rectangle(hdc, startX, startY,finishX, finishY);

		}
		
		if(bDrawEllipse)
		{
			// draw a blue ellipse 
			qLineColor = RGB(0, 0, 255);
			hLinePen = CreatePen(PS_SOLID, 3, qLineColor);
			hPenOld = (HPEN)SelectObject(hdc, hLinePen);

			Ellipse(hdc, startX, startY, finishX, finishY);
		}

		if(bDrawBMP)
		{
			LoadBMP(__T("sowa.bmp"), hdc);
		}

		SelectObject(hdc, hPenOld);
		DeleteObject(hLinePen);
		
		if (ifStart == true && ifFinish == true)
		{
			ifStart = false;
			ifFinish = false;
		}

		EndPaint(hWnd, &ps);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
