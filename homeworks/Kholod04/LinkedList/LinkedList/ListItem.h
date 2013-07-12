#ifndef _LIST_ITEM_H_
#define _LIST_ITEM_H_

typedef int DataItem;


class ListItem
{
	friend class LinkedList;
public:
	ListItem(DataItem = 0);
	~ListItem();

	void print() const;

private:
	ListItem* prev_;
	ListItem* next_;
	DataItem* data_;
};

#endif //_LIST_ITEM_H_