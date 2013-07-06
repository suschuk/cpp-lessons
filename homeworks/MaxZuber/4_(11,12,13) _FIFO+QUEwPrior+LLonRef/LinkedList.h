#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "ListItem.h"

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void next();
	void prev();
	void head();
	void tail();
	void insert(DataItem&, unsigned = 0);
	

	void prior_add(DataItem&, unsigned);
	void bg_add(DataItem&, unsigned = 0);					//add to begin of list
	void del();								//delete element from list on current position


	ListItem* search(DataItem& DItem);		//search element in list

	void sort();							//merge sort
	void print() ;							//print list

	int getSize() const;
	DataItem getCurrentData() const;

private:
	ListItem* merge_sort(ListItem* head, int count);								//help function for sort()
	ListItem* merge(ListItem* lHead, int lCount, ListItem* rHead, int rCount);		//help function for sort()

	ListItem* head_;
	ListItem* tail_;
	ListItem* current_;
	int size;

};

#endif