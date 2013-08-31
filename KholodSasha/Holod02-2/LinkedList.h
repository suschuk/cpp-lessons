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
	ListItem* insert(ListItem*);
	void remove();
	void removeAll();
	unsigned getSize() const;
	void print();

	ListItem* operator[] (unsigned pos);

private:
	ListItem* head_;
	ListItem* tail_;
	ListItem* current_;
	unsigned size;

};