#include <iostream>
#include "ListItem.h"


ListItem::ListItem(DataItem di, unsigned prior) {
	prev_ = 0;
	next_ = 0;
	data_ = new DataItem(di);
	prior_ = prior;
}

ListItem::~ListItem() {
	delete data_;
	//delete next_;
}

void ListItem::print() const
{
	std::cout << *data_ << std::endl;
}

