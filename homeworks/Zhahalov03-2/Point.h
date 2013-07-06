#pragma once
class Point
{
public:
	Point(void);
	Point(float x, float y);
	Point(const Point&);
	~Point(void);

	float X();
	float Y();

	void X(float x);
	void Y(float y);

private: 
	float _x;
	float _y;
};

