#pragma once



#include "Painter.h"
#include "Nodes.h"
#include "define.h"



class Game
{
public:

	Game(unsigned = 0);

	void draw(Painter& p, HDC& hdc);
	void move(Painter& p, HDC& hdc,int x, int y);
	void timer();

private:

	unsigned points;
	Nodes nodes;
	HDC buffer;
	HBITMAP hBitmap;
	bool dclick;
	Gdiplus::Image* img;

};