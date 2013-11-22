#pragma once


#include "Painter.h"

class Node
{
public:
	enum colors{RED, GREEN, BLUE, YELLOW};
	Node(Node::colors);
	Gdiplus::Image * getImg() const;
	colors getColor() const;

private:
	Gdiplus::Image* img;
	colors color;
};