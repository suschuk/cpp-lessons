#ifndef MENU_H_
#define MENU_H_

#include "MenuItem.h"
#include <vector>
#include <exception>

class BaseMenu {
public:
	virtual void operator[](const short& num) const {};
	virtual void print() {};
};

template <typename T>
class Menu: public BaseMenu
{
	template <typename T>
	friend std::ostream& operator << (std::ostream&, Menu<T>& );

	public:
		Menu(): lst(0) {};

		void operator+=(MenuItem<T>& mi)
		{
			lst.push_back(mi);
		}

		#pragma warning(disable:4290) //throw(...)
		void operator[](const short& num) const  throw(std::length_error());
		#pragma warning(default:4290)
		void print()
		{
			std::cout << *this;
		}


	private:
		Menu(const Menu&);
	private:
		std::vector<MenuItem<T> > lst;
};

#pragma warning(disable:4290)  //throw(...)
template <typename T>
void Menu<T>::operator[](const short& num) const throw(std::length_error())
{
	if(num >= short(lst.size()) || num < 0)
		throw std::length_error("Wrong index of menu");
	lst[num].cmd();
}
#pragma warning(default:4290)

template <typename T>
std::ostream& operator << (std::ostream& out, Menu<T>& m)
{

	auto it = m.lst.begin();

	while(it != m.lst.end())
	{
		out << *it << std::endl;
		++it;
	}
	return out;
}
#endif