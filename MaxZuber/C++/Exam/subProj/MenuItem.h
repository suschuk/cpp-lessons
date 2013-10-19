#ifndef MENUITEM_H_
#define MENUITEM_H_
#include <string>
#include "MenuItem.h"
#include <iostream>


template <typename T>
class MenuItem
{
	template <typename T>
	friend std::ostream& operator << (std::ostream&, const MenuItem<T>&);
public:
	MenuItem<T>() : name_(0), obj (0), command(0) {};
	MenuItem<T>(std::string& s, T* object, void(T::*cmd)(void)) : name_(s), obj(object), command(cmd) {} ;
	void cmd() const;
private:
	std::string name_;
	T* obj;
	void (T::*command)(void);
};


template <typename T>
std::ostream& operator << (std::ostream& out, const MenuItem<T>& mi)
{
	out << mi.name_;
	return out;
}

template<typename T>
void MenuItem<T>::cmd() const
{
	(obj->*command)();
}
#endif