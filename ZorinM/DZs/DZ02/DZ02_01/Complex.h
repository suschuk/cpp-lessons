#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using std::ostream;

class Complex
{
private:
	// complex number: z = a + b * i
	// i = sqr(-1)
	double a;
	double i; // imaginary part of a complex number: (b)

public:
	Complex();
	Complex(double, double);
	Complex(Complex&);

	friend ostream& operator << (ostream&, const Complex&);
	Complex& operator = (const Complex&);
	Complex operator + (const Complex&);
	Complex operator - (const Complex&);
	Complex operator * (const Complex&);
	Complex operator / (const Complex&);
};

#endif