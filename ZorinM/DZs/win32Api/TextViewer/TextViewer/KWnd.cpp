#include "KWnd.h"

KWnd::KWnd(LPCTSTR windowName, HINSTANCE hInst, int cmdShow,
				   LRESULT (WINAPI *pWndProc)(HWND,UINT,WPARAM,LPARAM),
				   LPCTSTR menuName, int x, int y, int width, int height,
				   UINT classStyle, DWORD windowStyle, HWND hParent)
{
	TCHAR szClassName[] = L"KWndClass";

	wc.cbSize        = sizeof(wc);
	wc.style         = classStyle;
	wc.lpfnWndProc   = pWndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInst;
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName  = menuName;
	wc.lpszClassName = szClassName;
	wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	// реєструємо клас вікна
	if (!RegisterClassEx(&wc)) {
		TCHAR msg[100] = L"Cannot register class: ";
		wcscat_s(msg, szClassName);
		MessageBox(NULL, msg, L"Error", MB_OK);
		return;
	}
	
	// створюємо вікно
	hWnd = CreateWindow(szClassName, windowName, windowStyle,
		x, y, width, height, hParent, (HMENU)NULL, hInst, NULL);       
	
	if (!hWnd) {
		TCHAR text[100] = L"Cannot create window: ";
		wcscat_s(text, windowName);
		MessageBox(NULL, text, L"Error", MB_OK);
		return;
	}

	ShowWindow(hWnd, cmdShow); 
}
