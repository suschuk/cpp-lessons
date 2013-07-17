/*
* Complex numbers class declaration
*/

#ifndef COMPLEX_H
#define COMPLEX_H

using std::ostream;

class Complex
{
friend ostream& operator<< (ostream& out, const Complex& z);

public:
	Complex();
	Complex(double a, double b);
	Complex (Complex& z);

	Complex& operator= (Complex& z);
	Complex operator+ (Complex& z) const;
	Complex operator- (Complex& z) const;
	Complex operator* (Complex& z) const;
	Complex operator/ (Complex& z) const;
private:
	double r; // real part
	double i; // imaginary part
};

#endif