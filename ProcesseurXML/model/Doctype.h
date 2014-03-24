#ifndef DOCTYPE_H
#define DOCTYPE_H
 
#include <iostream
>#include "EnTete.h"

using namespace std;
 
class Doctype: public EnTete
{
	public:
	  	Doctype(string nom1,string nom2,list<char*> valeurs);
	 
	private:
		string nom1;
		string nom2;
		list<char*> valeurs;
};
 
#endif