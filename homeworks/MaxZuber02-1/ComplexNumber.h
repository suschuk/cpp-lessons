#ifndef COMPLEXNUMBER_H_
#define COMPLEXNUMBER_H_
#include <iostream>
class ComplexNumber
{
public:
	

	ComplexNumber(double a = 0, double b = 0): real_part(a), imagine_part(b) {};

	//ComplexNumber(const ComplexNumber&);

	ComplexNumber& operator+(ComplexNumber&);
	ComplexNumber& operator-(ComplexNumber&);
	ComplexNumber& operator*(ComplexNumber&);
	ComplexNumber& operator/(ComplexNumber&);

	ComplexNumber& operator+=(double);
	ComplexNumber& operator-=(double);

	ComplexNumber* operator=(ComplexNumber);

	friend std::ostream& operator<<(std::ostream&, const ComplexNumber&);
	friend std::istream& operator>>(std::istream&, ComplexNumber&);

private:
	double real_part;
	double imagine_part;
};

#endif
