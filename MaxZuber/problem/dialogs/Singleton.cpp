
#include "stdafx.h"
#include "HIMLAPI.h"

Singleton* Singleton::s_inctance = NULL;

Singleton* Singleton::getInctance()
{

	if(!s_inctance)
	s_inctance = new Singleton();	
	return s_inctance;
}
HIMAGELIST* Singleton::getLrg()
{
	return &hLrg;
}
HIMAGELIST* Singleton::getSml()
{
	return &hSml;
}


Singleton::Singleton()
{
	hLrg = 0;
	hSml = 0;
	GetSystemImageLists(&hLrg, &hSml);
}
Singleton::~Singleton()	
{
	//hSml->
	delete s_inctance;	

}
