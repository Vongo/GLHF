#ifndef DOCTYPE_H
#define DOCTYPE_H
 
#include <iostream>
#include "EnTete.h"

using namespace std;
 
class Doctype: public EnTete
{
	public:
	  	Doctype(char* nom1,char* nom2,list<char*> valeurs);
	 
	private:
		char* nom1;
		char* nom2;
		list<char*> valeurs;
};
 
#endif