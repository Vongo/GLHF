#include "ElementBaliseOrpheline.h"


ElementBaliseOrpheline::ElementBaliseOrpheline(char *pNom, list<Attribut*> *attributs):Element()
{
    this->nom = pNom;
    this->lesAttributs = attributs;
}

char* ElementBaliseOrpheline::getName()
{
	return nom;
}

list<Attribut *> * ElementBaliseOrpheline::getLesAttributs()
{
	return lesAttributs;
}

ElementBaliseOrpheline::~ElementBaliseOrpheline()
{
    delete this->nom;
}

char *ElementBaliseOrpheline::toString()
{
    string buffer("<");
    buffer.append(this->nom);

    for (list<Attribut *>::iterator it = this->lesAttributs->begin(); it != this->lesAttributs->end(); it++)
    {
        buffer.append(" ");
        buffer.append((*it)->toString());
    }
    buffer.append(" /");
    buffer.append(" >");

    char *cstr = new char[buffer.length() + 1];
    strcpy(cstr, buffer.c_str());
    return cstr;
}