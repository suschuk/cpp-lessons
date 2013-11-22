
HINSTANCE hInst;
TCHAR szTitle[MAX_LOADSTRING];
TCHAR szWindowClass[MAX_LOADSTRING];	

typedef struct tagShape
{
	RECT rect;
	UINT shapeID;
} Shape;


const UINT SHAPE_COUNT = 5;
Shape Shapes[SHAPE_COUNT]; 
UINT nCurrentIndex = 0;

bool  isRubberBand = false;
POINT ptStart;
POINT ptCurrent;

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;
			
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_PAINT_BEGINNER, szWindowClass, MAX_LOADSTRING);
			
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_PAINT_BEGINNER);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_PAINT_BEGINNER;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	RegisterClassEx(&wcex);
			
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_PAINT_BEGINNER);
			
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}



BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;
			
   hInst = hInstance;
			
   memset(&Shapes, -1, sizeof(Shapes));
			
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


LRESULT OnCommand (HWND hWnd, int iID, int iEvent, HWND hWndControl, bool &isHandled);
LRESULT OnLButtonDown (HWND hWnd, UINT nCtrl, UINT x, UINT y);
LRESULT OnMouseMove   (HWND hWnd, UINT nCtrl, UINT x, UINT y);
LRESULT OnLButtonUp   (HWND hWnd, UINT nCtrl, UINT x, UINT y);
LRESULT OnPaint       (HWND hWnd);
void DrawRubberBand(HWND hWnd);


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
	case WM_CREATE:
		{
			HMENU hMenu = ::GetMenu(hWnd);
			HMENU hMenuShapes = ::GetSubMenu(hMenu, 1);
			::CheckMenuRadioItem(hMenuShapes, ID_SHAPE_RECTANGLE, ID_SHAPE_CIRCLE, ID_SHAPE_RECTANGLE, MF_BYCOMMAND);
		}
	case WM_COMMAND:
		{
			int wmId    = LOWORD(wParam); 
			int wmEvent = HIWORD(wParam); 

			bool isHandled = true;
			LRESULT lResult = OnCommand(hWnd, wmId, wmEvent, (HWND)lParam, isHandled);
			if (!isHandled)
			{
				lResult = DefWindowProc(hWnd, message, wParam, lParam);
			}

			return lResult;
		}
		break;
	case WM_CHAR:
		{
			if (VK_ESCAPE == wParam && isRubberBand)
			{
				isRubberBand = false;
				DrawRubberBand(hWnd);
			}
		}
		break;
	case WM_LBUTTONDOWN:
		{
			return OnLButtonDown(hWnd, (UINT)wParam, LOWORD(lParam), HIWORD(lParam));
		}
		break;
	case WM_MOUSEMOVE:
		{
			return OnMouseMove(hWnd, (UINT)wParam, LOWORD(lParam), HIWORD(lParam));
		}
		break;
	case WM_LBUTTONUP:
		{
			return OnLButtonUp(hWnd, (UINT)wParam, LOWORD(lParam), HIWORD(lParam));
		}
		break;
	case WM_PAINT:
		{
			return OnPaint(hWnd);
		}
		break;
	case WM_DESTROY:
		{
			
			PostQuitMessage(0);
			return 0;
		}
		break;
	}
			//C: Exit.
	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT OnCommand (HWND hWnd, int iID, int iEvent, HWND hWndControl, bool &isHandled)
{
	switch (iID)
	{			
	case ID_SHAPE_RECTANGLE:
	case ID_SHAPE_ELLIPSE:
		{
			HMENU hMenu = ::GetMenu(hWnd);
			HMENU hMenuShapes = ::GetSubMenu(hMenu, 1);
			::CheckMenuRadioItem(hMenuShapes, ID_SHAPE_RECTANGLE, ID_SHAPE_ELLIPSE, iID, MF_BYCOMMAND);
		}
		break;
	case IDM_EXIT: 
		{
			DestroyWindow(hWnd);
		}
		break;
	default:
		{
			
			isHandled = false;
		}
	}

	return 0;
}


LRESULT OnLButtonDown (HWND hWnd, UINT nCtrl, UINT x, UINT y)
{
	ptStart.x = x;
	ptStart.y = y;
	isRubberBand = true;
	ptCurrent.x = x;
	ptCurrent.y = y;
	DrawRubberBand(hWnd);
	return 0;	
}



LRESULT OnMouseMove   (HWND hWnd, UINT nCtrl, UINT x, UINT y)
{
			
	if (!isRubberBand)
	{
		return 0;
	}
			
	DrawRubberBand(hWnd);
			
	ptCurrent.x = x;
	ptCurrent.y = y;
			
	DrawRubberBand(hWnd);
			
	return 0;		
}


LRESULT OnLButtonUp   (HWND hWnd, UINT nCtrl, UINT x, UINT y)
{
			
	if (!isRubberBand)
	{
		return 0;
	}
			
	DrawRubberBand(hWnd);
			
	HMENU hMenu			= ::GetMenu(hWnd);
	HMENU hShapeMenu	= ::GetSubMenu(hMenu, 1);

	if (::GetMenuState(hShapeMenu, ID_SHAPE_RECTANGLE, MF_BYCOMMAND) & MF_CHECKED)
	{
		Shapes[nCurrentIndex].shapeID = ID_SHAPE_RECTANGLE;
	}
	else
	{
		Shapes[nCurrentIndex].shapeID = ID_SHAPE_ELLIPSE;
	}
	
	Shapes[nCurrentIndex].rect.left		= ptStart.x;
	Shapes[nCurrentIndex].rect.top		= ptStart.y;
	Shapes[nCurrentIndex].rect.right	= ptCurrent.x;
	Shapes[nCurrentIndex].rect.bottom	= ptCurrent.y;
	nCurrentIndex = (++nCurrentIndex)%SHAPE_COUNT;
	isRubberBand = false;
	InvalidateRect(hWnd, NULL, TRUE);
	UpdateWindow(hWnd);
	return 0;		
}


LRESULT OnPaint       (HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC			hdc;
	hdc = ::BeginPaint(hWnd, &ps);

	UINT index;
	for (index = 0; index < SHAPE_COUNT; index++)
	{
		if (ID_SHAPE_RECTANGLE == Shapes[index].shapeID)
		{
			::Rectangle	(	
						hdc, 
						Shapes[index].rect.left, 
						Shapes[index].rect.top, 
						Shapes[index].rect.right,
						Shapes[index].rect.bottom
						);
		}
		else
		{
			::Ellipse	(	
						hdc, 
						Shapes[index].rect.left, 
						Shapes[index].rect.top, 
						Shapes[index].rect.right,
						Shapes[index].rect.bottom
						);
		}
	}

	::EndPaint(hWnd, &ps);

	return 0;	
}

void DrawRubberBand(HWND hWnd)
{
	HDC hdc;
	hdc = ::GetDC(hWnd);

	::SetROP2(hdc, R2_NOT);
	::SelectObject(hdc, ::GetStockObject(NULL_BRUSH));
	HMENU hMenu			= ::GetMenu(hWnd);
	HMENU hShapeMenu	= ::GetSubMenu(hMenu, 1);

	if (::GetMenuState(hShapeMenu, ID_SHAPE_RECTANGLE, MF_BYCOMMAND) & MF_CHECKED)
	{
		::Rectangle	(	
					hdc, 
					ptStart.x, 
					ptStart.y, 
					ptCurrent.x,
					ptCurrent.y
					);
	}
	else
	{
		::Ellipse	(	
					hdc, 
					ptStart.x, 
					ptStart.y, 
					ptCurrent.x,
					ptCurrent.y
					);
	}
	::ReleaseDC(hWnd, hdc);
}
