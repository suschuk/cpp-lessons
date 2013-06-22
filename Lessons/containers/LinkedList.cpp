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


	return current_;
}
void LinkedList::print() 
{
	ListItem* saved = current_;
	head();
	
	while(current_) {
		current_ -> print();
		if(current_->next_) {
			next();
		} else {
			break;
		}
	}

	current_ = saved;
}
