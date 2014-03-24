#include "Doctype.h"
#include <iostream>

using namespace std;

Doctype::Doctype(char* nom1,char* nom2,list<char*> valeurs)
{
	this->nom1 = nom1;
	this->nom2 = nom2;
	this->valeurs = valeurs;
}

Doctype::~Doctype()
{
	delete(this->nom1);
	delete(this->nom2);
	for(list<char*>::iterator it = valeurs.begin() ; it != valeurs.end() ; it++)
	{
		delete(it);
	}
}