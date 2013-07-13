#pragma once

#include <iostream>
#include "ListItem.h"

template <typename T>
class LinkedList
{
public:
	LinkedList(const T& = T());

private:
	LinkedList(const LinkedList& ); // prohibited
public:

	const T& get() const;
	void del();
	void ins(const T& = T());
	bool next();
	bool prev();
	void print();
	void head_();
	void tail_();

private:

	ListItem<T>* current;
	ListItem<T>* head;
	const ListItem<T>* tail;
};
