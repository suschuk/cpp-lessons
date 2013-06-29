//Добавить в строковый класс функцию, которая создает строку,
//содержащую пересечение двух строк, то есть общие символы для двух строк.
//Например, результатом пересечения строк "sdqcg" "rgfas34" будет строка "sg".
//Для реализации функции перегрузить оператор * (бинарное умножение).

#include <iostream>
#include "String_.h"

int main()
{
	String_ one("1111111111111111111");
	std::cout << one.getData() << "\n";

	String_ two("123");
	std::cout << two.getData() << "\n";

	String_ three;
	three=one*two;
	std::cout << three.getData() << "\n";

	system("pause");

	return 0;
}