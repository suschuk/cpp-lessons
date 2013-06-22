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

	void print() ;

private:
	ListItem* head_;
	ListItem* tail_;
	ListItem* current_;
	int size;

};