#include <cassert>
#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;

template <typename T>
LinkedList<T>::LinkedList() : head_(0), tail_(0), current_(0), size(0) {}

template <typename T>
LinkedList<T>::~LinkedList()
{
	delete head_;
}

template <typename T>
ListItem<T>* LinkedList<T>::next()
{
	if(current_->next_)
		current_ = current_->next_;
	
	return  current_;
}

template <typename T>
ListItem<T>* LinkedList<T>::prev()
{
	if(current_->prev_)
		current_ = current_->prev_;
	
	return  current_;
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
ListItem<T>* LinkedList<T>::insert( T in )
{
	ListItem<T>* newListItem = new ListItem<T>(in);
	*(newListItem->data_) = in;
	if ( current_ == 0)
	{
		head_ = tail_ = current_ = newListItem;
		size++;
	}
	else
	{
		newListItem->next_ = current_->next_;

		if(current_->next_)
		{
			current_->next_->prev_ = newListItem;
		}
		else
		{
			tail_ = newListItem;
		}

		newListItem->prev_ = current_;
		current_->next_ = newListItem;
		next();
		size++;
	}

	return current_;
}

template <typename T>
void LinkedList<T>::print()
{
	ListItem<T>* saved = current_;
	head();

	while(current_)
	{
		current_ -> print();
		if(current_->next_)
		{
			next();
		}
		else
			break;
	}

	current_ = saved;
}

template <typename T>
void LinkedList<T>::print(int pos)
{
	if(pos < 1 || pos > size)
	{
		cout << "Incorrect position\n";
		return;
	}

	ListItem<T>* temp;
	int i = 1;

	if(pos <= size / 2)
	{
		temp = head_;
		while(i < pos)
		{
			i++;
			temp = temp->next_;
		}
	}
	else
	{
		temp = tail_;
		while( i >= size - pos)
		{
			i++;
			temp = temp->prev_;
		}
	}

	cout << pos << "-th element is: " << *temp->data_ << endl;
}

template <typename T>
int LinkedList<T>::GetSize()
{
	return size;
}

template <typename T>
T LinkedList<T>::GetDataItem() const
{
	return *current_->data_;
}

template <typename T>
T LinkedList<T>::GetDataItem(int pos) const
{
	if(pos < 1 || pos > size)
	{
		cout << "Incorrect position\n";
		return 0;
	}

	ListItem<T>* temp = head_;
	
	for(int i = 1; i < pos; i++)
	{
		temp = temp->next_;
	}

	if(temp)
		return *temp->data_;
	else
		return 0;
}

template <typename T>
void LinkedList<T>::SetDataItem(T di)
{
	*current_->data_ = di;
}

template <typename T>
void LinkedList<T>::DelTail()
{
	if(size == 0)
	{
		return;
	}
	else if(size == 1)
	{
		delete head_;
		head_ = tail_ = current_ = 0;
		size = 0;
		return;
	}
	else
	{
		if(current_ == tail_)
			current_ = tail_->prev_;
		ListItem<T>* temp = tail_->prev_;
		temp->next_ = 0;
		delete tail_;
		size--;
		tail_ = temp;
	}
}

template <typename T>
void LinkedList<T>::DelHead()
{
	if (size == 0)
	{
		return;
	}
	else if (size == 1)
	{
		delete head_;

		head_ = tail_ = current_ = 0;
		size = 0;
		return;
	}
	else
	{
		if(current_ == head_)
			current_ = head_->next_;
		
		ListItem<T>* temp = head_->next_;
		temp->prev_ = 0;
		head_ = head_->next_;

		head_ = temp;
		size--;
	}
}

template <typename T>
void LinkedList<T>::DelCurrent()
{
	if (size == 0)
	{
		return;
	}
	else if (size == 1)
	{
		delete current_;
		delete head_;
		delete tail_;
		current_ = head_ = tail_ = 0;
		size = 0;
	}
	else if(current_ == head_)
	{
		DelHead();
	}
	else if (current_ == tail_)
	{
		DelTail();
	}
	else
	{
		current_->prev_->next_ = current_->next_;
		current_->next_->prev_ = current_->prev_;
		current_ = current_->next_;
		size--;
	}

}

template <typename T>
void LinkedList<T>::DelAll()
{
	while(head_)
	{
		DelHead();
	}
}

