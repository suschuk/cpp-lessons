#include "ListItem.h"

template<typename T>
ListItem<T>::ListItem(const T& t) : data(t), prev(0), next(0) { }