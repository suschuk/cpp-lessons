#pragma  once

#include "Node.h"
#include "Painter.h"
#include "vector"
#include "define.h"

class Nodes
{
public:
	Nodes();
	void draw(Painter& p);
	std::vector<POINT>* swap(POINT& p1, POINT& p2);
	void findLine(const Node::colors& c, int x, int y);
	void deleteSolidLine();

private:

	std::vector<Node> field;
	std::vector<POINT> pointInLine;
};