#include "../DLL-Demo/MathFuncDLL.h"
#include <iostream>


int main()
{
	double a = 15;
	double b = 12;

	std::cout << MathFuncs::MyMathFuncs::Add(a,b) << std::endl;
	std::cout << MathFuncs::MyMathFuncs::Subtract(a,b) << std::endl;
	std::cout << MathFuncs::MyMathFuncs::Multiply(a,b) << std::endl;
	std::cout << MathFuncs::MyMathFuncs::Divide(a,b) << std::endl;

	char c;	std::cin >> c;

	return 0;
}