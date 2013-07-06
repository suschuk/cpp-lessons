#include<iostream>
#include "../FIFO/FIFO.h"
#include "../Priority_queue/PriorityQueue.h"
#include "../matrix_template/TemplMatrix.h"

using namespace std;

int main()
{
	// FIFO examples
	FIFO queue;
	cout << "IsEmpty: " << queue.isEmpty() << endl;
	queue.push(10);
	cout << "IsEmpty: " << queue.isEmpty() << endl;
	queue.push(11);
	queue.push(12);
	queue.push(13);
	queue.print();
	cout << endl;

	const DataItem* a = queue.back();
	cout << "Back: " << *a << endl;
	a  = queue.front();
	cout << "Front: " << *a << endl;

	queue.pop();
	cout << endl;
	queue.print();

	cout << endl;
	cout << "Size: " << queue.getSize() << endl;

	///////////////////////////////////////////
	//Priority queue examples
	cout << endl <<"----------Priority queue----------" << endl;
	PriorityQueue prQueue;
	cout << "IsEmpty: " << prQueue.isEmpty() << endl;
	prQueue.push(3);
	prQueue.push(5);
	prQueue.push(4);
	prQueue.push(2);
	prQueue.push(6);

	prQueue.print();
	cout << endl;
	prQueue.pop();
	prQueue.print();

	cout << "Size: " << prQueue.getSize() << endl;
	const DataItem* data = prQueue.top();
	cout << "Top: " << *data << endl;

	///////////////////////////////////////////
	//Template matrix examples
	cout << endl <<"----------Template matrix----------" << endl;

	TemplMatrix<int> tInt;
	tInt.init();
	tInt.showMatrix();

	TemplMatrix<double> tDouble;
	tDouble.init();
	tDouble.showMatrix();

	TemplMatrix<char> tChar;
	tChar.init();
	tChar.showMatrix();
	tChar.setCol(7);
	tChar.init();
	tChar.showMatrix();

	return 0;
}