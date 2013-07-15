#include "Complex.h"
#include <iomanip>

using std::endl;
using std::setprecision;

Complex::Complex()
{
	a = 0;
	i = 0;
}

Complex::Complex(double dA, double dI)
{
	a = dA;
	i = dI;
}

Complex::Complex(Complex& rZ)
{
	a = rZ.a;
	i = rZ.i;
}

ostream& operator << (ostream& out_, const Complex& z)
{
	if(z.i == 0)
	{
		out_ << setprecision(2) << z.a << endl;
	}
	else if(z.a == 0)
	{
		out_ << setprecision(2) << z.i << "i" << endl;
	}
	else
	{
		if (z.i < 0) 
			out_ << setprecision(2) << z.a << " - " << -z.i << "i" << endl;
		else
			out_ << setprecision(2) << z.a << " + " << z.i << "i" << endl;
	}
	return out_;
}

Complex& Complex::operator = (const Complex& rZ)
{
	a = rZ.a;
	i = rZ.i;
	return *this;
}

Complex Complex::operator + (const Complex& rZ)
{
	Complex res;

	res.a = a + rZ.a;
	res.i = i + rZ.i;

	return res;
}

Complex Complex::operator - (const Complex& rZ)
{
	Complex res;

	res.a = a - rZ.a;
	res.i = i - rZ.i;

	return res;
}

Complex Complex::operator * (const Complex& rZ)
{
	Complex res;
	
	// (a + bi) * (c + di) = (a * c - b * d) + (b * c + a * d)i
	res.a = a * rZ.a - i * rZ.i;
	res.i = i * rZ.a + a * rZ.i;

	return res;
}

Complex Complex::operator / (const Complex& rZ)
{
	Complex res;
	
	// (a + bi) / (c + di) = (ac + bd) / (cc + dd) + ((bc - ad) / (cc + dd)) i
	if ((a == 0 && i == 0) || (rZ.a == 0 && rZ.i == 0))
	{
		return res;
	}
	else
	{
		res.a = (a * rZ.a + i * rZ.i) / (rZ.a * rZ.a + rZ.i * rZ.i);
		res.i = (i * rZ.a - a * rZ.i) / (rZ.a * rZ.a + rZ.i * rZ.i);
	}

	return res;
}

