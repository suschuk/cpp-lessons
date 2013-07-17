#ifndef LIST_H
#define LIST_H

#include "item.h"

class List
{
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
	void remove();
	void clear();

	void print()  ;

private:
	Item* _head;
	Item* _tail;
	Item* _curr;
	int _size;

};

#endif