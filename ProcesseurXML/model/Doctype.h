#ifndef DOCTYPE_H
#define DOCTYPE_H
 
#include <iostream>
#include <string.h>
#include <list>
#include "EnTete.h"

using namespace std;
 
class Doctype: public EnTete
{
	public:
	  	Doctype(char*& nom1,char*& nom2,list<char*>*& valeurs);
	  	~Doctype();
	  	char *toString();
	 	char *getName1();
	 	char *getName2();
	 	list<char*> *getValeurs();

	private:
		char *nom1;
		char *nom2;
		list<char*> *valeurs;
};
 
#endif