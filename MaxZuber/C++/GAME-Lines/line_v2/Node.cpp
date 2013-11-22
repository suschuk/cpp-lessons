#include "Node.h"

Node::Node(Node::colors c, int x, int y ): x_(x), y_(y) {
	static const struct
	{
		Gdiplus::Image* im;
	} col[] = {
		Gdiplus::Image::FromFile(L"../red.png", FALSE),
		Gdiplus::Image::FromFile(L"../green.png", FALSE),
		Gdiplus::Image::FromFile(L"../blue.png", FALSE),
		Gdiplus::Image::FromFile(L"../yellow.png", FALSE)
	};

	img = col[c].im;
	color = c;
};


Gdiplus::Image * Node::getImg() const
{
	return img;
}

Node::colors Node::getColor() const
{
	return color;
}

void Node::setXY(int x, int y)
{
	x_ = x;
	y_ = y;
}
int Node::getX() const
{
	return x_;
}
int Node::getY() const
{
	return y_;
}