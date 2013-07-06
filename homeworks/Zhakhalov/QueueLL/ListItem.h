#pragma once

#include "Point.h"

typedef Point DataItem;

class ListItem
{
friend class LinkedList;

public:
	ListItem(DataItem);
	ListItem(DataItem, int);
	~ListItem(void);
private:

	int _priority;
	ListItem* _prev;
	ListItem* _next;
	DataItem* _data;
};

