#pragma once

#include "Point.h"

typedef Point DataItem;

class ListItem
{
friend class LinkedList;

public:
	ListItem(DataItem item);
	~ListItem(void);
private:

	ListItem* _prev;
	ListItem* _next;
	DataItem* _data;
};

