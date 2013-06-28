#include <cassert>
#include "LinkedList.h"

LinkedList::LinkedList() : head_(0), tail_(0), current_(0), size(0)
{}
LinkedList::~LinkedList()
{
	head();
	ListItem* tmp = current_;
	while(current_)
	{
		current_ = current_->next_;
		delete tmp;
		tmp = current_;
	}
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
ListItem* LinkedList::insert(DataItem* newDataItem) {
	assert(newDataItem);

	ListItem* newListItem = new ListItem(*newDataItem);

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

void LinkedList::bg_add(DataItem* newDataItem)
{
	ListItem* newListItem = new ListItem(*newDataItem);

	newListItem->next_ = head_;

	if(size == 0)
	{
		tail_ = newListItem;
	}
	else
	{
		head_ ->prev_ = newListItem;
	}

	head_ = newListItem;

	size++;
}
void LinkedList::end_add(DataItem* newDataItem)
{
	ListItem* newListItem = new ListItem(*newDataItem);
	if(size == 0)
	{	
		head_ = newListItem;
	}
	else
	{
		tail_->next_ = newListItem;
	}
	newListItem->prev_ = tail_;
	tail_ = newListItem;
	size++;
}
void LinkedList::pos_add_bef(DataItem* newDataItem, int pos)
{
	ListItem* newListItem = new ListItem(*newDataItem);
	if(pos > size || pos < 1)
	{
		return;
	}
	else if(pos == 1)
	{
		bg_add(newDataItem);
	}
	else
	{
		ListItem* tmp = current_;

		head();
		pos -= 2;

		for(int i = 0; i < pos; i++)
		{
			current_ = current_->next_;
		}

		insert(newDataItem);

		current_ = tmp;

	}
}
void LinkedList::pos_add_aft(DataItem* newDataItem, int pos)
{
	ListItem* newListItem = new ListItem(*newDataItem);

	if(pos > size || pos < 1)
	{
		return;
	}
	else if(pos == size)
	{
		end_add(newDataItem);
	}
	else
	{
		ListItem* tmp = current_;

		head();
		pos--;

		for(int i = 0; i < pos; i++)
		{
			current_ = current_->next_;
		}

		insert(newDataItem);

		current_ = tmp;
	}
}

void LinkedList::bg_del()
{
	if(size == 0)
		return;
	else if(size == 1)
	{
		delete head_;
		head_ = 0;
		tail_= 0;
		size--;
	}
	else
	{
		ListItem* tmp = head_->next_;
		tmp->prev_ = 0;
		tail_ = 0;
		delete head_;
		head_ = tmp;
		size--;
	}


}
void LinkedList::end_del()
{
	if(size == 1)
	{
		delete head_;
		head_ = 0;
		tail_ = 0;
		size--;
		return;
	}
	else if(size == 0)
	{
		return;
	}
	else
	{
		ListItem* tmp  = tail_ -> prev_;

		tmp->next_ = 0;

		delete tail_;

		tail_ = tmp;

		size--;
	}


}
void LinkedList::pos_del(int pos)
{
	if(pos > size || pos < 1)
	{
		return;
	}
	else if(pos == 1)
	{
		bg_del();
	}
	else if (pos == size)
	{
		end_del();
	}
	else
	{
		ListItem* tmp =current_;
		head();

		pos--;
		for(int i = 0; i < pos; i++)
		{
			current_ = current_ ->next_;
		}

		del();

		current_ = tmp;

	}

}
void LinkedList::del()
{
	ListItem* tmp = current_->prev_;

	current_->prev_->next_ = current_->next_;
	current_->next_->prev_ = current_->prev_;

	delete current_;
	current_ = tmp;

	size--;
}


ListItem* LinkedList::search(DataItem& DItem) 
{
	ListItem* tmp = current_;
	head();

	while(current_)
	{
		if(*(current_ ->data_) == DItem )
		{
			return current_;            
		}
		current_ = current_ ->next_;
	}
	return current_;
}

ListItem* LinkedList::merge_sort(ListItem* head, int count)
{
	if(count < 1) return head;
	if(count < 2) 
	{	
		head ->next_ = 0; 
		return head;
	}

	int half = count / 2;
	ListItem* second_head = head;

	
	for(int i = 0; i < half; i++)	
		second_head = second_head ->next_;


	head = merge_sort(head, half);
	second_head = merge_sort(second_head, count - half);

	return merge(head, half, second_head, count - half);

}

ListItem* LinkedList::merge(ListItem* lHead, int lCount, ListItem* rHead, int rCount)
{
	ListItem* tmp = new ListItem;
	tmp ->next_ = 0;
	ListItem* ptrTmp = tmp;

	while(lCount > 0 && rCount > 0)
	{
		if(*lHead ->data_ <= *rHead ->data_)
		{
			ptrTmp ->next_ = lHead;
			ptrTmp = lHead;
			lHead = lHead->next_;
			lCount--;
		}
		else
		{
			ptrTmp ->next_ = rHead;
			ptrTmp = rHead;
			rHead = rHead ->next_;
			rCount--;
		}	
	}


	if(lCount)			ptrTmp->next_ = lHead;
	else if(rCount)		ptrTmp->next_ = rHead;


	ptrTmp = tmp;
	tmp = tmp->next_;

	delete ptrTmp;
	return tmp;
}

void LinkedList::sort()
{
	head_ = merge_sort(head_, size);



	/*restore 'prev_' pointers*/

	head();
	current_ ->prev_ = 0;

	while(current_ ->next_)
	{
		current_ ->next_ ->prev_ = current_;
		current_ = current_ ->next_;
	}
	tail_ = current_;
}

int LinkedList::getSize() const
{
	return size;
}

DataItem* LinkedList::getCurrentData() const
{
	return current_ ->data_;
}