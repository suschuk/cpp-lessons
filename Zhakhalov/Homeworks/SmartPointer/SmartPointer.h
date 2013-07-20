
template <class T>
class UniquePointer
{
public:
	UniquePointer(T* newItem): item(newItem){}
	~UniquePointer(){delete item;}

	T* operator->(){return item;}
	T& operator* (){return *item;}
private:

	T* item;
};

template <class T>
class SharedPointer
{
public:
	SharedPointer(T* newItem)
	{
		item = new T;
		item = newItem;
		nLink = new int(1);
	}

	SharedPointer(const SharedPointer &scource)
	{
		item = scource.item;
		nLink = scource.nLink;
		(*nLink)++;
	}

	~SharedPointer()
	{
		if(0 == *nLink)
		{
			delete item;	
			delete nLink;
		}
		else (*nLink)--;
	}

	T* operator->(){return item;}
	T& operator* (){return *item;}
	SharedPointer& operator= (const SharedPointer &right)
	{
		item = right.item;
		nLink = right.nLink;
		(*nLink)++;
	}

private:

	T* item;
	int* nLink; // num of links
};