#include <process.h>
#include <Windows.h>
#include <iostream>

int _threads;

void foo(void* args)
{
	static int i = 0;
	while(i <= 10)
	{
		std::cout << "foo" << i++ << std::endl;
		Sleep(2000);
	}
	_threads--;
	_endthread();
}

void bar(void* args)
{
	static int i = 0;

	while(i <= 10)
	{
		std::cout << "bar" << i++ << std::endl;
		Sleep(1500);
	}	
	_threads--;
	_endthread();
}

int main()
{
	_threads = 0;

	_beginthread(foo,0,0);
	_threads++;
	_beginthread(bar,0,0);
	_threads++;

	while(_threads);
	std::cout << "END";

	char c;	std::cin >> c;
	return 0;
}