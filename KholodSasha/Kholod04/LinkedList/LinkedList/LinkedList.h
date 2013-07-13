#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "ListItem.h"

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	ListItem* next();
	ListItem* prev();
	ListItem* head();
	ListItem* tail();
	void insert(DataItem);
	void remove();
	void clear();
	unsigned getSize() const;
	void print();
	DataItem* getCurrData();

private:
	ListItem* head_;
	ListItem* tail_;
	ListItem* current_;
	unsigned size;

};

#endif //_LINKED_LIST_H_