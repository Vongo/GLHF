#include "Doctype.h"
#include <iostream>

using namespace std;

Doctype::Doctype(string nom1,string nom2,list<char*> valeurs)
{
	this->nom1 = nom1;
	this->nom2 = nom2;
	this->valeurs = valeurs;
}