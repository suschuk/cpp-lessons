#include "Point.h"

Point::Point(void): _x(0.0f), _y(0.0f){}

Point::Point(float x, float y): _x(x), _y(y){}

Point::Point(const Point& p): _x(p._x), _y(p._y){}

Point::~Point(void){}

float Point::X(){return _x;}
float Point::Y(){return _y;}

void Point::X(float x){_x = x;}
void Point::Y(float y){_y = y;}
