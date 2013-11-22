#include "Nodes.h"
#include <GdiPlus.h>

Nodes::Nodes()
{
	for(int i = 0; i < X::WIDTH * X::HEIGHT; ++i)
		field.push_back(Node(static_cast<Node::colors>(rand()% 4), i % X::WIDTH, i / X::HEIGHT));
}
void Nodes::draw(Painter& p)
{
	std::vector<Node>::iterator node = field.begin();

	for(; node < field.end(); ++node)
	{
		p.pic(node->getImg(), 4 + node->getX() * X::SIZE, 3 + node->getY() * X::SIZE);

	}
	for(auto it = markedNodes.begin(); it < markedNodes.end(); ++it)
	{
		p.mark(Gdiplus::Image::FromFile(L"../mark.png", FALSE), 4 + it->x * X::SIZE, 3 + it->y * X::SIZE); //x+4 and y+3 to set right position on board
	}

	p.swapBuffer();
}

int Nodes::swap(POINT& p1, POINT& p2)
{

	if((p1.x + 1 == p2.x && p1.y == p2.y) 
		|| (p1.x - 1 == p2.x && p1.y == p2.y) 
		|| (p1.x == p2.x && p1.y + 1 == p2.y) 
		|| (p1.x == p2.x && p1.y - 1 == p2.y))
	{

		int x1,x2, y1, y2;
		x1 = field[p1.y * X::HEIGHT + p1.x].getX();
		y1 = field[p1.y * X::HEIGHT + p1.x].getY();
		x2 = field[p2.y * X::HEIGHT + p2.x].getX();
		y2  = field[p2.y * X::HEIGHT + p2.x].getY();

		Node tmp = field[p1.y * X::HEIGHT + p1.x];
		field[p1.y * X::HEIGHT + p1.x] = field[p2.y * X::HEIGHT + p2.x];
		field[p2.y * X::HEIGHT + p2.x] = tmp;

		//change xy cords in swaped Nodes
		field[p1.y * X::HEIGHT + p1.x].setXY(x1,y1);
		field[p2.y * X::HEIGHT + p2.x].setXY(x2,y2);


		findLine(field[p2.y * X::HEIGHT + p2.x].getColor(), p2.x, p2.y);

		if(pointInLine.size() < 3)
		{
			//if move not alowed redo last swap;
			Node tmp = field[p1.y * X::HEIGHT + p1.x];
			field[p1.y * X::HEIGHT + p1.x] = field[p2.y * X::HEIGHT + p2.x];			
			field[p2.y * X::HEIGHT + p2.x] = tmp;

			field[p1.y * X::HEIGHT + p1.x].setXY(x1,y1);
			field[p2.y * X::HEIGHT + p2.x].setXY(x2,y2);
		}
	}

	if(pointInLine.size() < 3)
		pointInLine.clear();

	return pointInLine.size();
}

void Nodes::findLine(const Node::colors& c, int x, int y)
{

	if(x < 0 || y < 0 || x >= 10|| y >= 10)
		return;

	POINT point = {x ,y};


	if(pointInLine.size() == 0)
	{
		pointInLine.push_back(point);
	}
	else
	{
		auto it = pointInLine.begin();


		for(; it < pointInLine.end(); ++it)
		{
			if(it->x == x && it->y == y)
			{
				return;
			}
		}

		if( field[y * X::HEIGHT + x].getColor() != c)
		{
			return;
		}
		else
		{
			pointInLine.push_back(point);
		}
	}

	findLine(c, x + 1, y);
	findLine(c, x - 1, y);
	findLine(c, x , y + 1);
	findLine(c, x , y - 1);
}

void Nodes::deleteSolidLine()
{

	auto it = pointInLine.begin();

	for(; it < pointInLine.end(); ++it)
	{
		field[it->y * X::HEIGHT + it->x] = Node(static_cast<Node::colors>(rand() % 4), it->x, it->y);
	}

	pointInLine.clear();
}

void Nodes::mark(POINT& point)
{
	markedNodes.push_back(point);
}
void Nodes::animate()
{
	Nodes::clearMarkedPoint();
	for (auto it = pointInLine.begin(); it != pointInLine.end(); ++it)
	{
		Nodes::mark(*it);
		Nodes::draw(*Painter::getInstance());
		Sleep(150);
	}
}

void Nodes::clearMarkedPoint()
{
	markedNodes.clear();
}