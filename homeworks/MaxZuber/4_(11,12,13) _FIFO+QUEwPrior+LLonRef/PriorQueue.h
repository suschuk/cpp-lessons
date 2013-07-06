#ifndef PRIORQUEUE_H_
#define PRIORQUEUE_H_
#include "FIFO.h"
class PriorQueue: public FIFO
{
public:
	void push(DataItem&, unsigned prior);
};
#endif
