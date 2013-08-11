#ifndef LINKEDITEM_H
#define LINKEDITEM_H

// typedef int DataItem;
template <typename T> class LinkedList;

template <typename T>
class ListItem
{
	friend class LinkedList<T>;

private:
	ListItem<T>* prev_;
	ListItem<T>* next_;
	T* data_;

public:
	ListItem(T = 0);
	~ListItem();

	void print() const;
};

#endif