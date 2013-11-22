#pragma once
#include "Painter.h"

class Node
{
public:
	enum colors{RED, GREEN, BLUE, YELLOW};
	Node(Node::colors = RED, int = 0, int = 0);
	Gdiplus::Image * getImg() const;
	colors getColor() const;

	void setXY(int x, int y);
	int getX() const;
	int getY() const;

private:
	Gdiplus::Image* img;
	colors color;
	int x_;
	int y_;
};