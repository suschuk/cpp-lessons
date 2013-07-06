#ifndef NEWLISTITEM_H_
#define NEWLISTITEM_H_
#include "ListItem.h"

class newListItem: public ListItem
{
public:
	newListItem(DataItem di = 0, unsigned prior = 0): ListItem(di)
	{
		prior_ = new unsigned (prior);
	};

	~newListItem();
	unsigned getPrior();
private:
	unsigned* prior_;
};

#endif