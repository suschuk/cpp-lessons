#ifndef SMARTPTR_H
#define SMARTPTR_H

class RC	// Reffs Count
{
	int count;
public:
	void add()
	{ count++; }
	int release()
	{ return count--; }
	int getCount() const
	{
		return count;
	}
};

template <class T>
class smartPtr
{
	T* obj;
	RC* ref_count;
public:
	smartPtr () : obj (0), ref_count (0)
	{
		ref_count = new RC();
		ref_count->add(); 
	}
	smartPtr (T* obj) : obj (obj), ref_count (0)
	{
		ref_count = new RC();
		ref_count->add(); 
	}
	smartPtr (const smartPtr<T>& sp) : obj(sp.obj), ref_count (sp.ref_count)
	{
		ref_count->add(); 
	}
	~smartPtr()
	{
		if (ref_count->release() == 0)
		{
			delete obj;
			delete ref_count;
		}
	}

	T& operator * ()
	{
		return *obj;
	}

	T* operator -> ()
	{
		return obj;
	}

	smartPtr<T>& operator = (const smartPtr<T>& sp)
	{
		if (this != sp)
		{
			if(ref_count->release == 0)
			{
				delete obj;
				delete ref_count;
			}
			obj = sp.obj;
			ref_count = sp.ref_count;
			ref_count->add();
		}

		return *this;
	}

	int getRefCount() const
	{
		return ref_count->getCount();
	}
};

#endif