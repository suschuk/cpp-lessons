#include "MenuItem.h"
#include <vector>

class Menu
{
	friend std::ostream& operator << (std::ostream&, Menu& );
	public:
		Menu() : lst(0) {};
		void operator+=(MenuItem&);
		void operator[](const short& num) const  throw(std::length_error());

	private:
		Menu(MenuItem&);
		Menu(const Menu&);

	private:
		std::vector<MenuItem> lst;
};