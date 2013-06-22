#include "ComplexNumber.h"
#include <iostream>


ComplexNumber& ComplexNumber::operator+(ComplexNumber& cn)
{
	return ComplexNumber(real_part + cn.real_part, imagine_part + cn.imagine_part);
}
ComplexNumber& ComplexNumber::operator-(ComplexNumber& cn)
{
	return ComplexNumber(real_part - cn.real_part, imagine_part - cn.imagine_part);
}
ComplexNumber& ComplexNumber::operator*(ComplexNumber& cn)
{
	return ComplexNumber(real_part * cn.real_part - imagine_part * cn.imagine_part,
		real_part * cn.imagine_part + imagine_part * cn.real_part);
}
ComplexNumber& ComplexNumber::operator/(ComplexNumber& cn)
{
	return ComplexNumber( ((real_part * cn.real_part) + (imagine_part * cn.imagine_part)) / (pow(cn.real_part, 2) + pow(cn.imagine_part, 2) ),
		(imagine_part * cn.real_part - real_part * cn.imagine_part) /  (pow(cn.real_part, 2) + pow(cn.imagine_part, 2)));
}
ComplexNumber* ComplexNumber::operator=(ComplexNumber cn)
{
	real_part = cn.real_part;
	imagine_part = cn.imagine_part;
	return this;
}

std::ostream& operator<<(std::ostream& ostr, const ComplexNumber& cn)
{	
	ostr << cn.real_part;

	std::cout.setf(std::ios::showpos);
	ostr << " " << cn.imagine_part << "i";
	std::cout.unsetf(std::ios::showpos);
	
	return ostr;
}
std::istream& operator>>(std::istream& istr, ComplexNumber& cn)
{
	std::cout << "\nEnter real part: " ;
	istr >> cn.real_part;
	std::cout << "\nEnter imagine part: ";
	istr >> cn.imagine_part;

	return istr;
}

ComplexNumber& ComplexNumber::operator+=(double d)
{
	real_part += d;
	return *this;
}
ComplexNumber& ComplexNumber::operator-=(double d)
{
	real_part -= d;
	return *this;
}