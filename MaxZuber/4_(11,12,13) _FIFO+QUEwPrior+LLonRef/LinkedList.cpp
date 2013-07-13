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

void LinkedList::next()
{
	if(current_->next_) 
		current_=current_->next_;
}
void LinkedList::prev() {
	if(current_->prev_) 
		current_=current_->prev_;
}
void LinkedList::head() {
current_ = head_;
}
void LinkedList::tail() {
	current_ = tail_;
}
void LinkedList::insert(DataItem& newDataItem, unsigned p) {
	assert(newDataItem);

	ListItem* newListItem = new ListItem(newDataItem, p);

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

void LinkedList::prior_add(DataItem& newDataItem, unsigned p)
{
	ListItem* newListItem = new ListItem(newDataItem, p);
	if(size == 0)
	{
		head_ = tail_ = current_ = newListItem;
		++size;
	}
	else if(size == 1)
	{
		head();
		if(current_ ->prior_ < p)
		{
			current_ ->next_ = newListItem;
			newListItem ->prev_ = current_;
			tail_ = newListItem;
		}
		else
		{
			newListItem ->next_ = current_;
			current_ ->prev_ = newListItem;

			head_ = newListItem;
			tail_ = current_;
		}
		++size;
	}
	else
	{
		head();

		while(current_ ->prior_ < p && current_ ->next_ )
		{
			current_ = current_ ->next_;
		}

		if(current_ ->prev_ == 0)
		{
			bg_add(newDataItem, p);
		}
		else if(current_ == 0)
		{
			tail();
			insert(newDataItem, p);
		}
		else
		{
			if(current_ ->prior_ >= p)
			{
				prev();
			}
			
			insert(newDataItem, p);
		}
	}
}


void LinkedList::bg_add(DataItem& newDataItem, unsigned p)
{
	ListItem* newListItem = new ListItem(newDataItem, p);

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


void LinkedList::del()
{
	if(size == 0) return;
	if(size == 1)
	{
		delete current_;
		tail_ = head_ = current_ = 0;
	}
	else if(current_ ->prev_ == 0)
	{
		current_->next_ ->prev_ = 0;
		head_ = current_ ->next_;
		delete current_;
		current_ = head_;
	}
	else if(current_ ->next_ == 0)
	{
		current_ ->prev_ -> next_ = 0;
		tail_ = current_ ->prev_;
		delete current_;
		current_ = tail_;
	}
	else
	{
		ListItem* tmp = current_->prev_;

		current_->prev_->next_ = current_->next_;
		current_->next_->prev_ = current_->prev_;

		delete current_;
		current_ = tmp;
	}
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

DataItem LinkedList::getCurrentData() const
{
	return *current_ ->data_;
}