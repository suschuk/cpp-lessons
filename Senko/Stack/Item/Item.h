#ifndef ITEM_H
#define ITEM_H

typedef int element;


class Item
{
friend class List;

public:
	Item(element = 0);
	~Item();

	void print() const;

private:
	Item* _prev;
	Item* _next;
	element* _data;
};

#endif