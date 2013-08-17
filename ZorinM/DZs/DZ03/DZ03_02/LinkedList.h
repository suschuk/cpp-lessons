#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedItem.h"

class LinkedList
{
private:
	ListItem* head_;
	ListItem* tail_;
	ListItem* current_;
	int size;

public:
	LinkedList();
	~LinkedList();

	ListItem* next();
	ListItem* prev();
	ListItem* head();
	ListItem* tail();
	ListItem* insert(ListItem*);

	void print();
	void print(int);
	int GetSize();
	DataItem GetDataItem() const;
	DataItem GetDataItem(int) const;
	void SetDataItem(DataItem);
	
	void DelHead();
	void DelTail();
	void DelCurrent();
	void DelAll();
};

#endif