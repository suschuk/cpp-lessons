#include "PriorQueue.h"

void PriorQueue::push(DataItem& newDataItem, unsigned prior)
{
	DataItem* tmp = new DataItem(newDataItem);
	list.prior_add(*tmp, prior);
}