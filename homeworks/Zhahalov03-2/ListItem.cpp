#include "ListItem.h"


ListItem::ListItem(DataItem item)
{
	_next = 0;
	_prev = 0;
	_data = new DataItem(item);
}


ListItem::~ListItem(void)
{
	delete _data;
	delete _next;
}
