#include "Stack.h"

void Stack::push(element inData)
{
	_stack.tail();
	_stack.insert(inData);
}
void Stack::pop()
{
	_stack.tail();
	_stack.remove();
}
void Stack::print()
{
	_stack.print();
}