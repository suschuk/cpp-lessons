#include <iostream>
#include <iomanip>
#include "complex.h"

using std::endl;
using std::setprecision;

Complex::Complex()
{
	r = 0;
	i = 0;
}

Complex::Complex(double a, double b)
{
	r = a;
	i = b;
}
Complex::Complex (Complex& z)
{
	r = z.r;
	i = z.i;
}

ostream& operator<< (ostream& out, const Complex& z)
{
	if (z.i < 0) 
		out << z.r << z.i << "i" << endl;  
	else
		out << setprecision(2) << z.r << '+'<< setprecision(2) << z.i << "i" << endl;
	
	return out;
}

Complex& Complex::operator= (Complex& z)
{
	r = z.r;
	i = z.i;

	return *this;
}
Complex Complex::operator+ (Complex& z) const
{
	Complex tmp;
	tmp.r = r + z.r;
	tmp.i = i + z.i;

	return tmp;
}
Complex Complex::operator- (Complex& z) const
{
	Complex tmp;
	tmp.r = r - z.r;
	tmp.i = i - z.i;

	return tmp;
}
Complex Complex::operator* (Complex& z) const
{
	Complex tmp;
	tmp.r = r*z.r - i*z.i;	
	tmp.i = r*z.i + i*z.r;

	return tmp;
}
Complex Complex::operator/ (Complex& z) const
{
	Complex tmp;
	tmp.r = (r*z.r + i*z.i)/(z.r*z.r+z.i*z.i);	//Zero division check?
	tmp.i = (r*z.i - i*z.r)/(z.r*z.r+z.i*z.i);

	return tmp;
}


