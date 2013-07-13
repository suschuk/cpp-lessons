#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList(const T& t) : tail(new ListItem<T>(t))
{
	current = head = const_cast<ListItem<T>*>(tail);
}

template <typename T>
const T& LinkedList<T>::get() const
{
	if( !(current && current != tail) )
		throw std::runtime_error("Bad pointer");
	const ListItem<T>& rTmp = (*current);
	return rTmp.data;
}

template <typename T>
void LinkedList<T>::print() 
{

	if(head == tail)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	current = head;
	do {
		std::cout << get() << std::endl;
	} while(next());

}


template <typename T>
void LinkedList<T>::del()
{
	if(current == tail)
		return;
	if(current != head)
	{
		current->next->prev = current->prev;
		current->prev->next = current->next;
		ListItem<T>* pLI = current;
		current = current->next;
		delete pLI;
		return;
	}
	else
	{
		current = head ->next;
		delete head;
		head = current;
		return;
	}
}
template <typename T>
void LinkedList<T>::ins(const T& t)
{
	if(head == tail) // empty list
	{
		ListItem<T>* tmp = const_cast<ListItem<T>*>(tail);
		tmp->prev = new ListItem<T>(t);
		tmp->prev->next = tmp;
		current = head = tmp->prev;
		return;
	}
	if(head == current)
	{
		current->prev = new ListItem<T>(t);
		current->prev->next = current;
		head = current = current->prev;
		return;
	}
	ListItem<T>* pTmp = new ListItem<T>(t);
	pTmp->next = current;
	pTmp->prev = current->prev;
	current->prev->next = pTmp;
	current->prev = pTmp;

}

template <typename T>
bool LinkedList<T>::next()
{
	if(current == tail)
		return false;
	current = current->next;
	return true;
}
template <typename T>
bool LinkedList<T>::prev()
{
	if(current == head)
		return false;
	current = current->prev;
	return true;
}


template <typename T>
void LinkedList<T>::head_()
{
	current = head;
}
template <typename T>
void LinkedList<T>::tail_()
{
	current = const_cast<ListItem<T>*>(tail);
}