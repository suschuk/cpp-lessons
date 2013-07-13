#ifndef LIST_H
#define LIST_H

#include "../Item/Item.h"

class List
{
friend class Queue;

public:
	List();
	~List();

	Item* next();
	Item* prev();
	Item* head();
	Item* tail();
	element getData();
	void setData(element);
	Item* insert(element);
	Item* insertBefore(element);
	void remove();
	void clear();

	void print();
	int getSize();

private:
	Item* _head;
	Item* _tail;
	Item* _curr;
	int _size;

};

#endif