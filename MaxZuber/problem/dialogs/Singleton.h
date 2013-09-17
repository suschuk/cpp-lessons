


class Singleton
{
public:
	static Singleton* getInctance();
	HIMAGELIST* getLrg();
	HIMAGELIST* getSml();

private:
	Singleton();
	~Singleton();
	Singleton(const Singleton&);



private:

	static Singleton* s_inctance;

	HIMAGELIST hLrg;
	HIMAGELIST hSml;

};

/*HIMAGELIST hLrg = 0;
HIMAGELIST hSml = 0;
GetSystemImageLists(&hLrg, &hSml);*/