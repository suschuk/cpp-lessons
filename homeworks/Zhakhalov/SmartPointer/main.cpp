#include "SmartPointer.h"

class Point
{
public:
	Point(): _x(0), _y(0){}
	Point(int x, int y): _x(x), _y(y){}

	void X(int x){_x = x;}
	void Y(int y){_y = y;}

	int X() const{return _x;}
	int Y() const{return _y;}

private:
	int _x;
	int _y;
};

void main()
{		
	SmartPointer<Point> spP(new Point(3,5));

	spP->X(7);
}