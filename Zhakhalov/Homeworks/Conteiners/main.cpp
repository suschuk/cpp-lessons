#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
#include <Windows.h>

using namespace std;

void ListCheck(int nElements)
{
	int pushMs = 0;
	int popMs = 0;
	int pickMs = 0;

	list<int> List;

	pushMs = clock();
	for(int i = 0; i < nElements; ++i)
	{
		List.push_back(i);		
	}
	pushMs = clock() - pushMs;

	pickMs = clock();

	list<int>::iterator it = List.begin();
	advance(it, nElements / 2);

	int val = *it;

	pickMs = clock() - pickMs;

	List.front();   // ??? -- you get the value of first element but doesn't use it. Why?

	popMs = clock();
	while(List.size())
	{
		List.pop_back();
	}
	popMs = clock() - popMs;

	cout << "List: Elements:" << nElements;
	cout << "\r\nPush: " << pushMs << " ms\r\n"; 
	cout << "Pick: " << pickMs << " ms\r\n"; 
	cout << "Pop:  " << popMs  << " ms\r\n" << endl;

}

void ArrayCheck()
{
	const int nElements = 100000;    // It would be a good idea to make nElements global const

	int pushMs = 0;
	int pickMs = 0;

	array<int,nElements> Array;

	pushMs = clock();
	for(int i = 0; i < nElements; ++i)
	{
		Array[i] = i;		
	}
	pushMs = clock() - pushMs;

	pickMs = clock();
	int val = Array[nElements / 2];
	pickMs = clock() - pickMs;

	cout << "Array: Elements:" << nElements;
	cout << "\r\nPush: " << pushMs << " ms\r\n"; 
	cout << "Pick: " << pickMs << " ms\r\n"<< endl;

}

void DequeCheck(int nElements)
{
	int pushMs = 0;
	int popMs = 0;
	int pickMs = 0;

	deque<int> Deque;

	pushMs = clock();
	for(int i = 0; i < nElements; ++i)
	{
		Deque.push_back(i);		
	}
	pushMs = clock() - pushMs;

	deque<int>::iterator it = Deque.begin();
//	advance(it, nElements / 2);                     // Random access iterator, you can use *(it + nElements/2)

	int val = *(it + nElements/2);

	pickMs = clock() - pickMs;

	popMs = clock();
	while(Deque.size())
	{
		Deque.pop_back();
	}
	popMs = clock() - popMs;

	cout << "Deque: Elements:" << nElements;
	cout << "\r\nPush: " << pushMs << " ms\r\n"; 
	cout << "Pick: " << pickMs << " ms\r\n"; 
	cout << "Pop:  " << popMs  << " ms\r\n" << endl;
}

void VectorCeck(int nElements)
{
	int pushMs = 0;
	int popMs = 0;
	int pickMs = 0;

	vector<int> Vector;

	pushMs = clock();
	for(int i = 0; i < nElements; ++i)
	{
		Vector.push_back(i);		
	}
	pushMs = clock() - pushMs;

	pickMs = clock();
	int val = Vector[nElements / 2];
	pickMs = clock() - pickMs;

	Vector.front();   // see above

	popMs = clock();
	while(Vector.size())
	{
		Vector.pop_back();
	}
	popMs = clock() - popMs;	

	cout << "Vector: Elements:" << nElements;
	cout << "\r\nPush: " << pushMs << " ms\r\n"; 
	cout << "Pick: " << pickMs << " ms\r\n"; 
	cout << "Pop:  " << popMs  << " ms\r\n" << endl;
}

void main()
{
	int nElements = 100000;

	ListCheck(nElements);
	DequeCheck(nElements);
	VectorCeck(nElements);
	ArrayCheck();

	int ms = clock();
	Sleep(250);
	ms = clock() - ms;
}