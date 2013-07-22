#include <iostream>
#include "LinkedItem.h"

ListItem::ListItem(DataItem di)
{
	prev_ = NULL;
	next_ = NULL;
	data_ = new DataItem(di);
}

ListItem::~ListItem()
{
	delete data_;
	delete next_;
}

void ListItem::print() const
{
	std::cout << *data_ << " ";
}