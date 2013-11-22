#pragma once
#include <Windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include "define.h"

class Painter
{
public:

	void draw(HDC& screen);
	void setHDC(HDC& screen);
	void releaseDC();
	void pic( Gdiplus::Image*, int x, int y);
	void mark( Gdiplus::Image*, int x, int y);
	void net();
	void text(char*, int x, int y);
	static Painter* getInstance();

private:
	Painter() {};
	static Painter* s_instance;
	HDC buffer;
	HDC screen;
};