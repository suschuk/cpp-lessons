#include "Painter.h"
#include <stdio.h>

Painter* Painter::s_instance = NULL;

Painter* Painter::getInstance()
{
	if(!s_instance)
		s_instance = new Painter;
	return s_instance;
}

Painter::Painter()
{
	hWnd_ = 0;
	buffer = 0;
	hBitmap = 0;
}

void Painter::init(HWND& hWnd)
{
	hWnd_ = hWnd;

	HDC hdc = GetDC(hWnd_);

	RECT rc;
	GetClientRect(hWnd_, &rc);
	buffer = CreateCompatibleDC(hdc);
	hBitmap = CreateCompatibleBitmap(hdc,rc.right, rc.bottom);
	SelectObject(buffer, hBitmap);  

	Painter::net();

	ReleaseDC(hWnd_, hdc);

}
void Painter::pic( Gdiplus::Image* img, int x, int y)
{

	Gdiplus::Graphics gr(buffer);
	gr.DrawImage(img, x, y);
}
void Painter::mark( Gdiplus::Image* img, int x, int y)
{
	Gdiplus::Graphics gr(buffer);
	gr.DrawImage(img, x,y);
}

void Painter::net()
{
	Gdiplus::Graphics gr(buffer);

	// Create a Pen object.
	Gdiplus::Pen blackPen(Gdiplus::Color(255, 0, 0, 0), 3);

	gr.Clear(Gdiplus::Color::White);

	// Draw the lines.
	for(int x = 0; x <= X::HEIGHT; ++x)
		gr.DrawLine(&blackPen, x * X::SIZE, 0, x * X::SIZE, X::SIZE * X::HEIGHT);

	for(int y = 0; y <= X::WIDTH; ++y)
		gr.DrawLine(&blackPen, 0, y * X::SIZE, X::SIZE * X::HEIGHT, y * X::SIZE);
}
void Painter::text(char* str, int x, int y)
{
	WCHAR wc[64];
	swprintf(wc, 64, L"%hs", str);
	Gdiplus::Graphics gr(buffer);
	Gdiplus::Font font(&Gdiplus::FontFamily(L"Arial"), 12);

	Gdiplus::Pen pen(Gdiplus::Color(255,255, 0, 0), 3);


	Gdiplus::SolidBrush brush(Gdiplus::Color(255,255,0,0));
	Gdiplus::Status st = gr.DrawString(wc, -1, &font, Gdiplus::PointF(x, y), &brush);
}

void Painter::swapBuffer()
{
	HDC hdc = GetDC(hWnd_);

	RECT rc;
	GetClientRect(hWnd_, &rc);
	
	BitBlt(hdc, 0, 0, rc.right, rc.bottom, buffer,0,0, SRCCOPY);
	Painter::net();													//clean buffer and draw net
	
	ReleaseDC(hWnd_, hdc);
}
