#pragma once
#include "vect.h"
class Matr
{
private:
	int** Mx_;
	int m_;
	int n_;

public:
	Matr();
	Matr(int& m, int& n);
	Matr(const Matr&);
	~Matr();

	Matr operator+(Matr&);
	Matr operator*(Matr&);
	Matr& operator=(Matr&);
	Matr operator*(vect&);

	void showM() const;
	void fillRandom();
};

