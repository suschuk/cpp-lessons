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
	unsigned int getPriority();
	void setPriority(unsigned int);

private:
	Item* _prev;
	Item* _next;
	element* _data;
	unsigned int _priority;
};

#endif