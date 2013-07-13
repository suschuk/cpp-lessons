#pragma once

template <typename T> class LinkedList;

template <typename T>
class ListItem
{
	friend class LinkedList<T>;
public:
	ListItem(const T& = T()); 

private:
	T data;
	ListItem* prev;
	ListItem* next;
};

