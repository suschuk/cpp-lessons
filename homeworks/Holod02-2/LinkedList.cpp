#include <cassert>
#include "LinkedList.h"

LinkedList::LinkedList() : head_(0), tail_(0), current_(0), size(0)
{}
LinkedList::~LinkedList()
{
	delete head_;
}

ListItem* LinkedList::next()
{
	if(current_->next_) 
		current_=current_->next_;
	return current_;
}
ListItem* LinkedList::prev() {
	if(current_->prev_) 
		current_=current_->prev_;
	return current_;
}
ListItem* LinkedList::head() {
	return current_ = head_;
}
ListItem* LinkedList::tail() {
	return current_ = tail_;
}
ListItem* LinkedList::insert(ListItem* newListItem) {
	assert(newListItem);

	if( 0 == current_ ) {
		head_ = tail_ = current_ = newListItem;
	} else {
		newListItem->next_ = current_->next_;
		if(current_->next_)
		{
			current_->next_->prev_ = newListItem;
		} else {
			tail_ = newListItem;
		}

		newListItem->prev_ = current_;
		current_->next_ = newListItem;
		next();
	}

	size++;
	return current_;
}
void LinkedList::print() 
{
	head();
	for(unsigned i = 0; i < size; ++i)
	{
		current_->print();
		next();
	}
}

void LinkedList::remove()
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

unsigned LinkedList::getSize() const
{
	return size;
}

void LinkedList::removeAll()
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

ListItem* LinkedList::operator[] (unsigned pos)
{
	if(pos > size)
		throw 1;
	else
	{
		ListItem* saveCurr = current_;
		ListItem* ret;
		head();
		for(unsigned i = 0; i < pos; ++i)
			ret = next();
		current_ = saveCurr;
		return ret;
	}
}