#pragma  once

#include "Node.h"
#include "Painter.h"
#include "vector"
#include "define.h"
#include <GdiPlus.h>

class Nodes
{
public:
	Nodes();
	void draw(Painter& p);
	int swap(POINT& p1, POINT& p2);
	void animate();
	void findLine(const Node::colors& c, int x, int y);
	void deleteSolidLine();
	void mark(POINT& point);
	void clearMarkedPoint();

private:

	std::vector<Node> field;
	std::vector<POINT> pointInLine;
	std::vector<POINT> markedNodes;
};