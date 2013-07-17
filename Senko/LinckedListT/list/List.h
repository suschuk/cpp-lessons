#ifndef LIST_H
#define LIST_H

#include "../Item/Item.h"

template <typename T>
class List
{
public:
	List();
	~List();

	Item<T>* next();
	Item<T>* prev();
	Item<T>* head();
	Item<T>* tail();
	T getData();
	void setData(T);
	Item<T>* insert(T);
	void remove();
	void clear();

	void print();
	int getSize();

private:
	Item<T>* _head;
	Item<T>* _tail;
	Item<T>* _curr;
	int _size;

};


#endif