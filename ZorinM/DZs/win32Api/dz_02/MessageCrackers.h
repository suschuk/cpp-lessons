void OnPaint(HWND);
void OnMouseMove(HWND, int, int, UINT);
void OnLButtonDown(HWND, BOOL, int, int, UINT);
void OnRButtonDown(HWND, BOOL, int, int, UINT);
void LButtonDblClk(HWND, BOOL, int, int, UINT);
void RButtonDblClk(HWND, BOOL, int, int, UINT);
//void OnRButtonUp(HWND, int, int, UINT);
void OnDestroy(HWND);
bool LoadBMP(LPCWSTR, HDC);