//((fn)((hwnd), (int)(LOWORD(wParam)), (HWND)(lParam), (UINT)HIWORD(wParam)), 0L)
//(LRESULT)(DWORD)(UINT)(BOOL)(fn)((hwnd), (HWND)(wParam), lParam)

void WndOnCommand(HWND, int, HWND, UINT);
void WndOnDestroy(HWND);
INT_PTR AboutOnInitDialog(HWND, HWND, LPARAM);
INT_PTR AboutOnCommand(HWND, int, HWND, UINT);


INT_PTR DlgOnInitDialog(HWND, HWND, LPARAM);
INT_PTR DlgOnCommand(HWND, int, HWND, UINT);
