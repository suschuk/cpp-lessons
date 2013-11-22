#pragma once

#include <Windows.h>
#include <GdiPlus.h>
#include "define.h"
/*
*Use painter after init() function
*
*Use paniter for non-resize window
*/

class Painter
{
public:

	void init(HWND& hWnd);
	void pic( Gdiplus::Image*, int x, int y);
	void mark( Gdiplus::Image*, int x, int y);
	void net();
	void text(char*, int x, int y);

	void swapBuffer();

	static Painter* getInstance();

private:
	Painter();
	static Painter* s_instance;
	HWND hWnd_;
	HDC buffer;
	HBITMAP hBitmap;
};