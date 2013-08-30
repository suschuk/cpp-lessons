#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

template <typename T>
class LinkedList;

template <typename T>
class ListItem
{
	friend class LinkedList<T>;
public:
	ListItem(T = 0);
	~ListItem();

	void print() const;

private:
	ListItem<T>* prev_;
	ListItem<T>* next_;
	T* data_;
};
template <typename T>
ListItem<T>::ListItem(T di)
{
	prev_ = 0;
	next_ = 0;
	data_ = new T(di);
}
template <typename T>
ListItem<T>::~ListItem()
{
	delete data_;
}
template <typename T>
void ListItem<T>::print() const
{
	std::cout << *data_ << std::endl;
}


template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	ListItem<T>* next();
	ListItem<T>* prev();
	ListItem<T>* head();
	ListItem<T>* tail();
	void insert(T);
	void remove();
	void clear();
	unsigned getSize() const;
	void print();
	T* getCurrData();

private:
	ListItem<T>* head_;
	ListItem<T>* tail_;
	ListItem<T>* current_;
	unsigned size;

};

#include <cassert>
template <typename T>
LinkedList<T>::LinkedList() : head_(0), tail_(0), current_(0), size(0)
{}
template <typename T>
LinkedList<T>::~LinkedList()
{
	delete head_;
}
template <typename T>
ListItem<T>* LinkedList<T>::next()
{
	if(current_->next_) 
		current_=current_->next_;
	return current_;
}
template <typename T>
ListItem<T>* LinkedList<T>::prev()
{
	if(current_->prev_) 
		current_=current_->prev_;
	return current_;
}
template <typename T>
ListItem<T>* LinkedList<T>::head()
{
	return current_ = head_;
}
template <typename T>
ListItem<T>* LinkedList<T>::tail()
{
	return current_ = tail_;
}
template <typename T>
void LinkedList<T>::insert(T newDataItem)
{
	ListItem<T>* newListItem = new ListItem<T>(newDataItem);
	assert(newListItem);

	if( 0 == current_ )
	{
		head_ = tail_ = current_ = newListItem;
	} else
	{
		newListItem->next_ = current_->next_;
		if(current_->next_)
		{
			current_->next_->prev_ = newListItem;
		} else
		{
			tail_ = newListItem;
		}

		newListItem->prev_ = current_;
		current_->next_ = newListItem;
		next();
	}

	size++;
}
template <typename T>
void LinkedList<T>::print() 
{
	head();
	for(unsigned i = 0; i < size; ++i)
	{
		current_->print();
		next();
	}
}
template <typename T>
void LinkedList<T>::remove()
{
	if(! current_)
		return;
	if(size == 1)
	{
		delete current_;
		size = 0;
		head_ = 0;
		tail_ = 0;
		current_ = 0;
		return;
	}
	ListItem* del = current_;
	if(current_ == head_)
	{
		current_->next_->prev_ = 0;
		head_ = current_->next_;
		current_ = current_->next_;
	}
	else if(current_ == tail_)
	{
		current_->prev_->next_ = 0;
		tail_ = current_->prev_;
		current_ = current_->prev_;
	}
	else
	{
		current_->prev_->next_ = current_->next_;
		current_->next_->prev_ = current_->prev_;
		current_ = current_->next_;
	}
	delete del;
	size--;
}
template <typename T>
unsigned LinkedList<T>::getSize() const
{
	return size;
}
template <typename T>
void LinkedList<T>::clear()
{
	head();
	if(! current_)
		return;
	while(current_->next_)
	{
		next();
		delete current_->prev_;
	}
	delete current_;
	size = 0;
	head_ = 0;
	tail_ = 0;
	current_ = 0;
}
template <typename T>
T* LinkedList<T>::getCurrData()
{
	return current_->data_;
}


#endif //_LINKED_LIST_H_