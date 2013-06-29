#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

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
	ListItem* insert(DataItem*);

	void bg_add(DataItem*);					//add to begin of list
	void end_add(DataItem*);				//add to end of list
	void pos_add_bef(DataItem*, int);		//add after position pointed
	void pos_add_aft(DataItem*, int);		//add before position pointed


	void del();								//delete element from list on current position
	void bg_del();							//delete element from begin of list
	void end_del();							//delte element from end of list
	void pos_del(int);						//delete element from position pointed


	ListItem* search(DataItem& DItem);		//search element in list

	void sort();							//merge sort
	void print() ;							//print list

	int getSize() const;
	DataItem* getCurrentData() const;

private:
	ListItem* merge_sort(ListItem* head, int count);								//help function for sort()
	ListItem* merge(ListItem* lHead, int lCount, ListItem* rHead, int rCount);		//help function for sort()

	ListItem* head_;
	ListItem* tail_;
	ListItem* current_;
	int size;

};

#endif