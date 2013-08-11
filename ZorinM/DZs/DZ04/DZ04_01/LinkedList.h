#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedItem.h"

template <typename T>
class LinkedList
{
private:
	ListItem<T>* head_;
	ListItem<T>* tail_;
	ListItem<T>* current_;
	int size;

public:
	LinkedList();
	~LinkedList();

	ListItem<T>* next();
	ListItem<T>* prev();
	ListItem<T>* head();
	ListItem<T>* tail();
	ListItem<T>* insert( T );

	void print();
	void print(int);
	int GetSize();
	T GetDataItem() const;
	T GetDataItem(int) const;
	void SetDataItem( T );
	
	void DelHead();
	void DelTail();
	void DelCurrent();
	void DelAll();
};

#endif