#ifndef LINKEDITEM_H
#define LINKEDITEM_H

typedef int DataItem;

class ListItem
{
	friend class LinkedList;

private:
	ListItem* prev_;
	ListItem* next_;
	DataItem* data_;

public:
	ListItem(DataItem = 0);
	~ListItem();

	void print() const;
};

#endif