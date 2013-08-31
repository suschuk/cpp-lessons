#include <string>

class Menu
{
public:
	Menu(std::string t, void (*f)(void)):text_(t),function_(f) { }
	void Print();
	void Work_function(); 
private:
	std::string text_;
	void (*function_)(void);
};