// tetris.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "game.h"


#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#define MAX_LOADSTRING 100

// Глобальные переменные:
int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
int v = 0;
HINSTANCE hInst;								// текущий экземпляр
TCHAR szTitle[MAX_LOADSTRING];					// Текст строки заголовка
TCHAR szWindowClass[MAX_LOADSTRING];			// имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: разместите код здесь.
	MSG msg;
	HACCEL hAccelTable;

	LoadString(hInstance, IDC_TETRIS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TETRIS));

	// Цикл основного сообщения:
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

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TETRIS));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_TETRIS);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   hWnd = CreateWindow(szWindowClass, L"Пятнашки", WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,100, 100, 640, 490, NULL, NULL, hInstance, NULL);

   CreateWindow(L"button", L"Перемішати", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,450, 40, 150, 30, hWnd, (HMENU)10000, hInstance, NULL);

   CreateWindow(L"button", L"Зберегти", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,	450, 80, 150, 30, hWnd, (HMENU)9000, hInstance, NULL);

   CreateWindow(L"button", L"Відкрити останнє", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 450, 120, 150, 30, hWnd, (HMENU)8000, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   InvalidateRect(hWnd, NULL,true);
   UpdateWindow(hWnd);

   return TRUE;
}


void paste_picture(HWND hWnd, HDC hdc, int H, int W, int n){
	HBITMAP hBitmap = 0;
	HANDLE hOldObject;
	HDC hSrcDC;
	LPCWSTR aaa = 0;
	switch(n){
	case 1:aaa = L"1.bmp";break;
	case 2:aaa = L"2.bmp";break;
	case 3:aaa = L"3.bmp";break;
	case 4:aaa = L"4.bmp";break;
	case 5:aaa = L"5.bmp";break;
	case 6:aaa = L"6.bmp";break;
	case 7:aaa = L"7.bmp";break;
	case 8:aaa = L"8.bmp";break;
	case 9:aaa = L"9.bmp";break;
	case 10:aaa = L"10.bmp";break;
	case 11:aaa = L"11.bmp";break;
	case 12:aaa = L"12.bmp";break;
	case 13:aaa = L"13.bmp";break;
	case 14:aaa = L"14.bmp";break;
	case 15:aaa = L"15.bmp";break;
	default:aaa = L"15.bmp";break;
	}
	(HANDLE &)hBitmap = LoadImage(hInst, aaa, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hSrcDC = CreateCompatibleDC(hdc);
	hOldObject = SelectObject(hSrcDC, hBitmap);
	BitBlt(hdc, W*100+15, H*100+15, W*100+100, H*100+100, hSrcDC, 0, 0, SRCCOPY);
	SelectObject(hSrcDC, hOldObject);
	DeleteObject(hBitmap);
	DeleteDC(hSrcDC);
	
	//ReleaseDC(hWnd, hdc);
	
}

void vin(HWND hWnd){
	if(v == 0 && matrix[0][0] == 1 &&	matrix[0][1] == 2 &&
			matrix[0][2] == 3 && matrix[0][3] == 4 &&
			matrix[1][0] == 5 && matrix[1][1] == 6 &&
			matrix[1][2] == 7 && matrix[1][3] == 8 &&
			matrix[2][0] == 9 && matrix[2][1] == 10 &&
			matrix[2][2] == 11 && matrix[2][3] == 12 &&
			matrix[3][0] == 13 && matrix[3][1] == 14 &&
			matrix[3][2] == 15){
				MessageBox(hWnd, L"Вітаю, ти просто геній",L"ВІТАЮ", MB_OK);
		}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	bool flag = true;
	FILE* file;
	switch (message)
	{
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_LEFT:
			for(int row = 0; row < 4; ++row){
				for(int col = 0; col < 4; ++col){
					if (matrix[row][col] == 0  && col < 3 && flag){
						matrix[row][col] = matrix[row][col + 1];
						matrix[row][col + 1] = 0;
						flag = false;
					}
				}
			}
			flag = true;
			InvalidateRect(hWnd, NULL,true);
			break;
		case VK_RIGHT:
			for(int row = 0; row < 4; ++row){
				for(int col = 0; col < 4; ++col){
					if (matrix[row][col] == 0 && col > 0 && flag){
						matrix[row][col] = matrix[row][col - 1];
						matrix[row][col - 1] = 0;
						flag = false;
					}
				}
			}
			flag = true;
			InvalidateRect(hWnd, NULL,true);
			break;
		case VK_UP:
			for(int row = 0; row < 4; ++row){
				for(int col = 0; col < 4; ++col){
					if (matrix[row][col] == 0 && row < 3 && flag){
						matrix[row][col] = matrix[row + 1][col];
						matrix[row + 1][col] = 0;
						flag = false;
					}
				}
			}
			flag = true;
			InvalidateRect(hWnd, NULL,true);
			break;
		case VK_DOWN:
			for(int row = 0; row < 4; ++row){
				for(int col = 0; col < 4; ++col){
					if (matrix[row][col] == 0 && row > 0 && flag){
						matrix[row][col] = matrix[row - 1][col];
						matrix[row - 1][col] = 0;
						flag = false;
					}
				}
			}
			flag = true;
			InvalidateRect(hWnd, NULL,true);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam );
		break;
	}
		vin(hWnd);
	break;
	case WM_LBUTTONDOWN:
		{
		int xPos = GET_X_LPARAM(lParam); 
		int yPos = GET_Y_LPARAM(lParam);
		for(int row = 0; row < 4; ++row){
			for(int col = 0; col < 4; ++col){
				if (yPos > row*100+15 && xPos > col*100+15 && yPos < row*100+100 && xPos < col*100+100){
					if (matrix[row][col-1] == 0  && col > 0 && flag){
						matrix[row][col-1] = matrix[row][col];
						matrix[row][col] = 0;
						flag = false;
					}else if (matrix[row][col+1] == 0  && col < 3 && flag){
						matrix[row][col+1] = matrix[row][col];
						matrix[row][col] = 0;
						flag = false;
					}else if (matrix[row-1][col] == 0  && row > 0 && flag){
						matrix[row-1][col] = matrix[row][col];
						matrix[row][col] = 0;
						flag = false;
					}else if (matrix[row+1][col] == 0  && row < 3 && flag){
						matrix[row+1][col] = matrix[row][col];
						matrix[row][col] = 0;
						flag = false;
					}
				}
			}
		}
		flag = true;
		InvalidateRect(hWnd, NULL,true);
		}
			vin(hWnd);
			break;	
	case WM_SIZE:
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Разобрать выбор в меню:

		if (wmId == 10000)
		{
			for(int i = 0; i < 800; ++i){
				v=1;
				switch(rand()%(4)){
				case 0:
					SendMessage(hWnd, WM_KEYDOWN, VK_RIGHT, 1);
					UpdateWindow(hWnd);
					break;
				case 1:
					SendMessage(hWnd, WM_KEYDOWN, VK_LEFT, 1);
					UpdateWindow(hWnd);
					break;
				case 2:
					SendMessage(hWnd, WM_KEYDOWN, VK_UP, 1);
					UpdateWindow(hWnd);
					break;
				case 3:
					SendMessage(hWnd, WM_KEYDOWN, VK_DOWN, 1);
					UpdateWindow(hWnd);
					break;
				}	
				v=0;
				//Sleep(100);
			}
			MessageBox(hWnd, L"Фсьо, перемішав!", L"", 0);
		}else if(wmId == 9000 || wmId == IDM_32773){
			file = fopen("save", "w");
			for(int row = 0; row < 4; ++row){
				for(int col = 0; col < 4; ++col){
					if(matrix[row][col] < 10)
						fprintf (file, "%d \n", matrix[row][col]);
					else
						fprintf (file, "%d\n", matrix[row][col]);					
				}
			}
			fclose(file);
			SetFocus(hWnd);
			MessageBox(hWnd,L"Гру успішно збережено", L"Файл записано",NULL);
		}else if(wmId == 8000 || wmId == IDM_32772){
			file = fopen("save", "a+");
			for(int row = 0; row < 4; ++row){
				for(int col = 0; col < 4; ++col){
					char s[3];
					char ss[3];
					s[0]=NULL;s[1]=NULL;s[2]=NULL;
					fgets(s, 3, file);
					fgets(ss, 2, file);
					matrix[row][col] = atoi(s);
				}
			}
			fclose(file);
			UpdateWindow(hWnd);
			InvalidateRect(hWnd, NULL,true);
			SetFocus(hWnd);
			MessageBox(hWnd,L"Гру відновлено", L"Файл відкрито",NULL);
		}else if(wmId == IDM_ABOUT){
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		}else if(wmId == IDM_EXIT){
			DestroyWindow(hWnd);
		}else{
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
		
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		Rectangle(hdc, 5,5,425,425);
		Rectangle(hdc, 6,6,424,424);
		Rectangle(hdc, 7,7,423,423);
		for(int row = 0; row < 4; ++row){
			for(int col = 0; col < 4; ++col){
				if (matrix[row][col] != 0){	
					paste_picture(hWnd, hdc, row, col, matrix[row][col]);
				}
			}
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

// Обработчик сообщений для окна "О программе".
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
