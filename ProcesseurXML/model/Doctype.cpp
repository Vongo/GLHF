#include "Doctype.h"
#include <iostream>

using namespace std;

Doctype::Doctype(char *&nom1,char *&nom2,list<char*> *&valeurs)
{
	this->nom1 = nom1;
	this->nom2 = nom2;
	this->valeurs = valeurs;
}

Doctype::~Doctype()
{
	delete(this->nom1);
	delete(this->nom2);
	for(list<char*>::iterator it = valeurs->begin() ; it != valeurs->end() ; it++)
	{
		delete(&it);
	}
}

//<!DOCTYPE html>

char *Doctype::toString()
{
	string buffer("<");
	buffer.append("!DOCTYPE ");
    buffer.append(this->nom1);
    buffer.append(" ");
    buffer.append(this->nom2);
    buffer.append(" ");

    for (list<char*>::iterator it = this->valeurs->begin(); it != this->valeurs->end(); it++)
    {
        buffer.append(" ");
        buffer.append("\"");
        buffer.append(*it);
        buffer.append("\"");
    }
    buffer.append(">");

    char *cstr = new char[buffer.length() + 1];
    strcpy(cstr, buffer.c_str());
    return cstr;
}

char *Doctype::getName1() 
{
    return nom1;
}

char *Doctype::getName2() 
{
    return nom2;
}

list<char*> *Doctype::getValeurs()
{
    return valeurs;
}

