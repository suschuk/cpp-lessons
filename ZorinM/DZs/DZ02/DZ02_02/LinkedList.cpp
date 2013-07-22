#include <cassert>
#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;

LinkedList::LinkedList() : head_(0), tail_(0), current_(0), size(0) {}

LinkedList::~LinkedList()
{
	delete head_;
}

ListItem* LinkedList::next()
{
	if(current_->next_)
		current_ = current_->next_;
	
	return  current_;
}

ListItem* LinkedList::prev()
{
	if(current_->prev_)
		current_ = current_->prev_;
	
	return  current_;
}

ListItem* LinkedList::head()
{
	return current_ = head_;
}

ListItem* LinkedList::tail()
{
	return current_ = tail_;
}

ListItem* LinkedList::insert(ListItem* newListItem)
{
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

void LinkedList::print()
{
	ListItem* saved = current_;
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

void LinkedList::print(int pos)
{
	if(pos < 1 || pos > size)
	{
		cout << "Incorrect position\n";
		return;
	}

	ListItem* temp;
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

int LinkedList::GetSize()
{
	return size;
}

DataItem LinkedList::GetDataItem() const
{
	return *current_->data_;
}

DataItem LinkedList::GetDataItem(int pos) const
{
	if(pos < 1 || pos > size)
	{
		cout << "Incorrect position\n";
		return 0;
	}

	ListItem* temp = head_;
	
	for(int i = 1; i < pos; i++)
	{
		temp = temp->next_;
	}

	if(temp)
		return *temp->data_;
	else
		return 0;
}

void LinkedList::SetDataItem(DataItem di)
{
	*current_->data_ = di;
}

void LinkedList::DelTail()
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
		ListItem* temp = tail_->prev_;
		temp->next_ = 0;
		delete tail_;
		size--;
		tail_ = temp;
	}
}

void LinkedList::DelHead()
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
		
		ListItem* temp = head_->next_;
		temp->prev_ = 0;
		head_ = head_->next_;

		head_ = temp;
		size--;
	}
}

void LinkedList::DelCurrent()
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

void LinkedList::DelAll()
{
	while(head_)
	{
		DelHead();
	}
}

