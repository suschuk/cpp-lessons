/*
* Complex numbers class declaration
*/

#ifndef COMPLEX_H
#define COMPLEX_H

using std::ostream;

namespace complex {

class Complex
{
public:

	__declspec(dllexport) friend  ostream& operator<< (ostream& out, const Complex& z);

	__declspec(dllexport) Complex();
	__declspec(dllexport) Complex(double a, double b);
	__declspec(dllexport) Complex (Complex& z);

	__declspec(dllexport) Complex& operator= (Complex& z);
	__declspec(dllexport) Complex operator+ (Complex& z) const;
	__declspec(dllexport) Complex operator- (Complex& z) const;
	__declspec(dllexport) Complex operator* (Complex& z) const;
	__declspec(dllexport) Complex operator/ (Complex& z) const;
private:
	double r; // real part
	double i; // imaginary part
};

}
#endif