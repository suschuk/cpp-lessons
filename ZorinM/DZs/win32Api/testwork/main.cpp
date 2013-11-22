////////////////////////////////////////////////////////////
// Testwork Win32: Zorin M
#include <windows.h>
#include <tchar.h>

#include "KWnd.h"
#include "Maze_.h"

#define xyStep 15
#define cY  29	// Лише непарні числа
#define cX  49	// Лише непарні числа
int dX, dY, xWin, yWin;

void DrawMaze (HWND, HDC, PAINTSTRUCT, MazeRB&);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
////////////////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	KWnd mainWnd(L"Testwork Win32: Zorin M.", hInstance, nCmdShow, WndProc);	

	while (GetMessage(&msg, NULL, 0, 0))  {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

HRGN hRgn;

////////////////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	RECT wRect, cRect;
	GetWindowRect(hWnd, &wRect);
	GetClientRect(hWnd, &cRect);
	
	dX = wRect.right - wRect.left - (cRect.right - cRect.left);
	dY = wRect.bottom - wRect.top - (cRect.bottom - cRect.top);
	xWin = cX * (xyStep - 0) + dX, yWin = cY * (xyStep - 0)  + dY;

	int xSh = xyStep * cX - xyStep, 
		ySh = xyStep * cY - xyStep;
	HDC hDC;
	PAINTSTRUCT ps;
	static HRGN hRgn = CreateRoundRectRgn(xSh + 1, ySh + 1, xSh + xyStep, ySh + xyStep, xyStep / 3, xyStep / 3 );
	HBRUSH hBrush;
	HPEN hLinePen, hPenOld;
	int userReply = 0;
	static MazeRB maze(cY, cX);

	//TCHAR buff[32];
	//wsprintf( buff, TEXT("width = %d; height = %d"), dX, dY );

	switch (uMsg)
	{
	case WM_CREATE:
		maze.start();
		// SetWindowText(hWnd, buff);
		break;

	case WM_PAINT:
		MoveWindow(hWnd, 10, 10, xWin, yWin, TRUE);

		hDC = BeginPaint(hWnd, &ps);
		
		DrawMaze(hWnd, hDC, ps, maze);
		//SetBkMode(hDC, OPAQUE);

		// фініш
		hLinePen = CreatePen(PS_SOLID, 1, RGB(193, 1, 255));
		hPenOld = (HPEN)SelectObject(hDC, hLinePen);
		
		MoveToEx(hDC, xyStep / 2, 0, NULL);
		LineTo (hDC, xyStep / 2, xyStep);
		MoveToEx(hDC, 0, xyStep / 2, NULL);
		LineTo (hDC, xyStep, xyStep  / 2);
		Ellipse (hDC, xyStep / 6, xyStep / 6, 
						xyStep - xyStep / 6, xyStep - xyStep / 6);

		SelectObject(hDC, hPenOld);
		DeleteObject(hLinePen);		
		
		
		SetDCBrushColor(hDC, RGB(198, 75, 0));
		hBrush = (HBRUSH)GetStockObject(DC_BRUSH);
		FillRgn(hDC, hRgn, hBrush);

		EndPaint(hWnd, &ps);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_UP) {
			if ( maze.move(0) ) {
				InvalidateRgn(hWnd, hRgn, TRUE);
				ySh -= xyStep;
				OffsetRgn(hRgn, 0, -xyStep);
				InvalidateRgn(hWnd, hRgn, TRUE);
			}
		}
		if (wParam == VK_RIGHT) {
			if ( maze.move(1) ) {
				InvalidateRgn(hWnd, hRgn, TRUE);
				xSh += xyStep;
				OffsetRgn(hRgn, xyStep, 0);
				InvalidateRgn(hWnd, hRgn, TRUE);
			}
		}
		if (wParam == VK_DOWN) {
			if ( maze.move(2) ) {
				InvalidateRgn(hWnd, hRgn, TRUE);
				ySh += xyStep;
				OffsetRgn(hRgn, 0, xyStep);
				InvalidateRgn(hWnd, hRgn, TRUE);
			}
		}
		if (wParam == VK_LEFT) {
			if ( maze.move(3) ) {
				InvalidateRgn(hWnd, hRgn, TRUE);
				xSh -= xyStep;
				OffsetRgn(hRgn, -xyStep, 0);
				InvalidateRgn(hWnd, hRgn, TRUE);
			}
		}
		if (maze.ifWon()) 
		{
			userReply = MessageBox(NULL, L"You won!\nDo you want to try again?", 
												L"Victory", MB_YESNO | MB_ICONQUESTION);

			if ( userReply == IDNO )
				DestroyWindow(hWnd);
			if ( userReply == IDYES )
			{
				xSh = xyStep * cX - xyStep; 
				ySh = xyStep * cY - xyStep;

				OffsetRgn(hRgn, xSh, ySh);
				InvalidateRgn(hWnd, hRgn, TRUE);

				maze.start();
				InvalidateRect(hWnd, 0, TRUE);
			}
		}
		break;
    case WM_DESTROY:
		DeleteObject(hRgn);
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

//======================================================
void DrawMaze(HWND hwnd, HDC hdc, PAINTSTRUCT ps, MazeRB& maze)
{
	HPEN hPen0 = CreatePen(PS_SOLID, 1, RGB(120, 120, 120));
	HPEN hOldPen = (HPEN)SelectObject(hdc, hPen0);

	for(int i = 0; i < xWin; i += xyStep) { MoveToEx(hdc, i, 0, NULL); LineTo(hdc, i, yWin); }
	for(int i = 0; i < yWin; i += xyStep) { MoveToEx(hdc, 0, i, NULL); LineTo(hdc, xWin, i); }

	SelectObject(ps.hdc, GetStockObject(GRAY_BRUSH)); 
	for (int i = 0; i < cY; i++)
		for (int j = 0; j < cX; j++){
			if (maze.getElement(i, j) == WALL) {
				MoveToEx(hdc, j * xyStep, i * xyStep, NULL);
				Rectangle(hdc,  j * xyStep, i * xyStep,
								j * xyStep + xyStep, i * xyStep + xyStep);
		}	
			
	}
	
	SelectObject(hdc, hOldPen);
	DeleteObject(hPen0);
}
