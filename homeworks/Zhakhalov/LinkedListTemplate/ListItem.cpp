#include "ListItem.h"


ListItem::ListItem(DataItem item, int priority)
{
	_priority = priority;
	_next = 0;
	_prev = 0;
	_data = new DataItem(item);
}

ListItem::ListItem(DataItem item)
{
	_priority = 0;
	_next = 0;
	_prev = 0;
	_data = new DataItem(item);
}


ListItem::~ListItem(void)
{
	delete _data;
	delete _next;
}
