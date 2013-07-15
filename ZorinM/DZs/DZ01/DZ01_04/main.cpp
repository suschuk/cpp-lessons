/*
	1. Добавить в строковый класс функцию, которая создает строку, содержащую 
	пересечение двух строк, то есть общие символы для двух строк. Например, 
	результатом пересечения строк "sdqcg" "rgfas34" будет строка "sg". Для 
	реализации функции перегрузить оператор * (бинарное умножение).
*/
#include "String_.h"
#include <iostream>
using namespace std;

int main()
{
	String_ s1, s2("rgfas34"), res;
	s1.setStr("sdqcg");
	
	res = s1 * s2;
	cout << "s1 * s2 = " << res.getStr() << "\n\n";

	s1.setStr("abcdefghi");
	s2.setStr("ghiablkj");
	
	res = s1 * s2;
	cout << "s1 * s2 = " << res.getStr() << "\n\n";

	return 0;
}