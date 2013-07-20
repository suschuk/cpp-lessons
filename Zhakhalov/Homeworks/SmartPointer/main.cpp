#include "SmartPointer.h"
#include <iostream>
#include <iomanip>

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

void foo(SharedPointer<Point> sp)
{

}

void main()
{		
	//SharedPointer<Point> sp1(new Point(20,34));
	//foo(sp1);
	//SharedPointer<Point> sp2 = sp1,
	//					 sp3(sp1);

	const int S = 20;

	int mat[S][S];

	for(int y = 0; y < S; ++y)
	{
		for(int x = 0; x < S; ++x)
		{
			mat[y][x] = y + x;
		}
	}


	for(int y = 0; y < S; ++y)
	{
		for(int x = 0; x < S; ++x)
		{
			std::cout << std::setw(3) << mat[y][x];
		}
		std::cout << std::endl;
	}
}