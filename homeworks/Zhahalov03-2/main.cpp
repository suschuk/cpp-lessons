
#include "LinkedList.h"
#include "StackFIFO.h"
#include "StackLIFO.h"
#include <iostream>


void main()
{
	/*LinkedList list;
	Point p1(17.0f,12.5f);
	Point p2(1.0f,99.0f);
	Point p3(38.0f,1.2f);

	list.Add(p1);
	list.Add(p2);
	list.Add(p3);

	list.Head();

	std::cout << list.GetItem().X() << std::endl;
	std::cout << list.GetItem().Y() << std::endl << std::endl;

	list.Next();

	std::cout << list.GetItem().X() << std::endl;
	std::cout << list.GetItem().Y() << std::endl << std::endl;

	list.Prev();

	std::cout << list.GetItem().X() << std::endl;
	std::cout << list.GetItem().Y() << std::endl << std::endl;

	list.Tail();

	std::cout << list.GetItem().X() << std::endl;
	std::cout << list.GetItem().Y() << std::endl << std::endl;

	LinkedList list2;

	list2.Add(Point(99,55));
	list2.Add(Point(88,55));
	list2.Add(Point(77,55));
	list2.Add(Point(66,55));

	list2.Head();

	std::cout << list2.GetItem().X() << std::endl;
	std::cout << list2.GetItem().Y() << std::endl << std::endl;

	list2.Next();

	std::cout << list2.GetItem().X() << std::endl;
	std::cout << list2.GetItem().Y() << std::endl << std::endl;

	list2.Tail();

	std::cout << list2.GetItem().X() << std::endl;
	std::cout << list2.GetItem().Y() << std::endl << std::endl;

	list2.Prev();

	std::cout << list2.GetItem().X() << std::endl;
	std::cout << list2.GetItem().Y() << std::endl << std::endl;

	list2.Remove();

	std::cout << list2.GetItem().X() << std::endl;
	std::cout << list2.GetItem().Y() << std::endl << std::endl;

	list2.Remove();

	std::cout << list2.GetItem().X() << std::endl;
	std::cout << list2.GetItem().Y() << std::endl << std::endl;

	list2.Head();

	std::cout << list2.GetItem().X() << std::endl;
	std::cout << list2.GetItem().Y() << std::endl << std::endl;

	list2.Remove();

	std::cout << list2.GetItem().X() << std::endl;
	std::cout << list2.GetItem().Y() << std::endl << std::endl;

	StackFIFO StackF;

	StackF.Add(Point(99,11));
	StackF.Add(Point(88,11));
	StackF.Add(Point(77,11));
	StackF.Add(Point(66,11));
	StackF.Add(Point(55,11));

	Point p1 = StackF.Get();
	Point p2 = StackF.Get();*/

	StackLIFO StackL;

	StackL.Add(Point(99,11));
	StackL.Add(Point(88,11));
	StackL.Add(Point(77,11));
	StackL.Add(Point(66,11));
	StackL.Add(Point(55,11));

	Point p1 = StackL.Get();
	Point p2 = StackL.Get();

}