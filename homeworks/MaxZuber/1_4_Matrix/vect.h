#pragma once

class vect
{
private:
	int* vec_;
	int m_;
public:
	vect();
	vect(int&);
	vect(const vect&);
	~vect();

	void fillRanom();

	int getNum(int&);
	int getVectSize();
	void printVect();

};

