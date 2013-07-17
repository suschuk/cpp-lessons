#include <iostream>
#include "../List/list.h"


using std::cout;
using std::endl;

int main()
{
	cout << "INT LINCKED LIST:" << endl;

	List<int> A;
	
	cout << "Linked list <int> filling [100 .. 105]..." << endl;

	for(int i = 100; i <= 105; ++i)
		A.insert(i);
	
	cout << "List <int> tail element setting to 555..." << endl;
	A.setData(555);
	
	A.print();
	
	cout << "Head item removing ..." << endl;
	A.head();
	A.remove();
	
	cout << "Tail item removing..." << endl;
	A.tail();
	A.remove();
	
	cout << "Second item removing..." << endl;
	A.head();
	A.next();
	A.remove();
	
	A.print();

	cout << "List <int> clearing..." << endl;
	A.clear();
	cout << "Empty list <int> printing..." << endl;
	A.print();

	//Lincked list on double

	cout << endl << "DOUBLE LINCKED LIST:" << endl;
	List<double> B;

	cout << "Linked list <double> filling [10.1 .. 10.5]..." << endl;

	for(int i = 1; i <= 5; ++i)
		B.insert(10+0.1*i);
	
	cout << "List <double> tail element setting to 0.5..." << endl;
	B.setData(.5);
	
	B.print();
	
	cout << "Head item removing ..." << endl;
	B.head();
	B.remove();
	
	cout << "Tail item removing..." << endl;
	B.tail();
	B.remove();
	
	cout << "Second item removing..." << endl;
	B.head();
	B.next();
	B.remove();
	
	B.print();

	cout << "List <double> clearing..." << endl;
	B.clear();
	cout << "Empty list <double> printing..." << endl;
	B.print();

	return 0;
}
