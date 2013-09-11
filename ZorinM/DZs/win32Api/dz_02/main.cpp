#include <Windows.h>
#include "MessageCrackers.h"
#include "stdafx.h"

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//===================================================
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, 
					LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	wchar_t szClassName[] = L"MyClas";
	MSG msg;
	WNDCLASSEX wc;

	// заповнюємо структуру класу вікна
	wc.cbSize			= sizeof(wc);
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wc.lpfnWndProc		= WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= hInstance;
	wc.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= szClassName;
	wc.hIconSm			= LoadIcon(NULL, IDI_APPLICATION);

	// реєструємо клас вікна
	if (!RegisterClassEx(&wc))
	{
		MessageBox( NULL, L"Cannot register class", L"Error", MB_OK );
		return 0;
	}

	// створюємо основне вікно програми
	hWnd = CreateWindow(
		szClassName, L"MessageCracker Demo", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		(HWND)NULL, (HMENU)NULL, (HINSTANCE)hInstance, NULL	);

	if(!hWnd)
	{
		MessageBox(NULL, L"Cannot create main window", L"Error", MB_OK);
	}

	// показуємо вікно
	ShowWindow(hWnd, nCmdShow);
	// UpdateWindow(hWnd);

	// виконуємо цикл обробки до закриття програми
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

//=========================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        HANDLE_MSG(hWnd, WM_PAINT, OnPaint);
        // HANDLE_MSG(hWnd, WM_MOUSEMOVE, OnMouseMove);
        HANDLE_MSG(hWnd, WM_LBUTTONDOWN, OnLButtonDown);
        HANDLE_MSG(hWnd, WM_RBUTTONDOWN, OnRButtonDown);
        HANDLE_MSG(hWnd, WM_DESTROY, OnDestroy);
        HANDLE_MSG(hWnd, WM_LBUTTONDBLCLK, LButtonDblClk);
        HANDLE_MSG(hWnd, WM_RBUTTONDBLCLK, RButtonDblClk);
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}
