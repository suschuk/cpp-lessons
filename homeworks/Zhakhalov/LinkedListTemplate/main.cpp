#include "LinkedList.h"

void main()
{
	LinkedList<float> list;

	list.Add(11.1f);
	list.Add(22.2f);
	list.Add(33.3f);

	list.Head();
	float a = list.GetItem();
	list.Remove();
	a = list.GetItem();
	list.Tail();
	a = list.GetItem();

}