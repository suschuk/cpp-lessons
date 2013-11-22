#include "Painter.h"
using namespace Gdiplus;

#include <stdio.h>



Painter* Painter::s_instance = NULL;

Painter* Painter::getInstance()
{
	if(!s_instance)
		s_instance = new Painter;

	return s_instance;
}


void Painter::setHDC(HDC& hdc)
{
	screen = hdc;
}
void Painter::releaseDC()
{
	screen = 0;
}

void Painter::pic(Gdiplus::Image* img, int x, int y)
{
	int w  = img->GetWidth();
	int h = img->GetHeight();
	Gdiplus::Graphics gr(screen);
	gr.DrawImage(img, x,y , w, h);
}

void Painter::mark( Gdiplus::Image* img, int x, int y)
{
	int w  = img->GetWidth();
	int h = img->GetHeight();

	Gdiplus::Graphics gr(screen);


	gr.DrawImage(img, x,y , w, h);
}



void Painter::net()
{
	Graphics graphics(screen);
	
	// Create a Pen object.
	Pen blackPen(Color(255, 0, 0, 0), 3);
	
	graphics.Clear(Gdiplus::Color::White);

	// Draw the lines.
	for(int x = 0; x <= HEIGHT; ++x)
			graphics.DrawLine(&blackPen, x * SIZE, 0, x * SIZE, SIZE * HEIGHT);

	for(int y = 0; y <= WIDTH; ++y)
		graphics.DrawLine(&blackPen, 0, y * SIZE, SIZE * HEIGHT, y * SIZE);

}

void Painter::text(char* str, int x, int y)
{
	WCHAR wc[64];
	swprintf(wc, 64, L"%hs", str);
	Graphics gr(screen);
	Gdiplus::Font font(&Gdiplus::FontFamily(L"Arial"), 12);

	Gdiplus::Pen pen(Gdiplus::Color(255,255, 0, 0), 3);


	SolidBrush brush(Color(255,255,0,0));
	Gdiplus::Status st = gr.DrawString(wc, -1, &font, Gdiplus::PointF((REAL)x, (REAL)y), &brush);
}