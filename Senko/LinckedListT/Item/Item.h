#ifndef ITEM_H
#define ITEM_H

template <typename T> class List;

template <typename T>
class Item
{
friend class List<T>;

public:
	Item(T = 0);
	~Item();

	void print() const;

private:
	Item* _prev;
	Item* _next;
	T* _data;
};


#endif