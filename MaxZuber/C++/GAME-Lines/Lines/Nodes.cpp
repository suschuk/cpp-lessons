#include "Nodes.h"

Nodes::Nodes()
{
	for(int i = 0; i < WIDTH * HEIGHT; ++i)
		field.push_back(Node(static_cast<Node::colors>(rand()% 4)));
}
void Nodes::draw(Painter& p)
{
	p.net();
	Gdiplus::Image* im;
	for(int y = 0; y < HEIGHT; ++y)
		for(int x = 0; x< WIDTH; ++x)
		{
			im = field[y * HEIGHT + x].getImg();
			p.pic(im, 4 + x * (im->GetWidth() + 7), 3 + y * (im->GetHeight() + 6));
		}


}

std::vector<POINT>* Nodes::swap(POINT& p1, POINT& p2)
{
	
	if((p1.x + 1 == p2.x && p1.y == p2.y) 
		|| (p1.x - 1 == p2.x && p1.y == p2.y) 
		|| (p1.x == p2.x && p1.y + 1 == p2.y) 
		|| (p1.x == p2.x && p1.y - 1 == p2.y))
	{
		

			Node tmp = field[p1.y * HEIGHT + p1.x];
			field[p1.y * HEIGHT + p1.x] = field[p2.y * HEIGHT + p2.x];
			field[p2.y * HEIGHT + p2.x] = tmp;

			findLine(field[p2.y * HEIGHT + p2.x].getColor(), p2.x, p2.y);

			if(pointInLine.size() < 3)
			{
				Node tmp = field[p1.y * HEIGHT + p1.x];
				field[p1.y * HEIGHT + p1.x] = field[p2.y * HEIGHT + p2.x];
				field[p2.y * HEIGHT + p2.x] = tmp;
			}
	}


	return &pointInLine;
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

		if( field[y * HEIGHT + x].getColor() != c)
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
		field[it->y * HEIGHT + it->x] = Node(static_cast<Node::colors>(rand()%4));
	}
}

