
template <class T>
class SmartPointer
{
public:
	SmartPointer(T* newItem): item(newItem){}
	~SmartPointer(){delete item;}

	T* operator->(){return item;}
	T& operator* (){return *item;}
private:

	T* item;
};