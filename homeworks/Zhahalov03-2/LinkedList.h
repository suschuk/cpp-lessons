#pragma once
#include "ListItem.h"

class LinkedList
{
public:
	LinkedList(void);
	~LinkedList(void);

	ListItem* Next();
	ListItem* Prev();
	ListItem* Head();
	ListItem* Tail();

	void Add(DataItem);
	void Insert(DataItem);
	void Remove();	

	DataItem GetItem() const;

	int List() const;

private:

	ListItem* _head;
	ListItem* _tail;
	ListItem* _curr;
	int size;


};

