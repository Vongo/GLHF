#include "ElementBaliseOrpheline.h"


ElementBaliseOrpheline::ElementBaliseOrpheline(char *pNom, list<Attribut*> *attributs, char *type):Element()
{
    this->nom = pNom;
    this->lesAttributs = attributs;
    this->type = type;
}

char* ElementBaliseOrpheline::getName()
{
	return nom;
}

char* ElementBaliseOrpheline::getType()
{
    return type;
}

list<Attribut *> * ElementBaliseOrpheline::getLesAttributs()
{
	return lesAttributs;
}

list<Element *> * ElementBaliseOrpheline::getLesElements()
{
    return new list<Element *>;
}

ElementBaliseOrpheline::~ElementBaliseOrpheline()
{
    delete this->nom;
}

char *ElementBaliseOrpheline::toString()
{
    string buffer(format("<"));

    buffer.append(this->type);
    buffer.append(":");
    buffer.append(this->nom);

    for (list<Attribut *>::iterator it = this->lesAttributs->begin(); it != this->lesAttributs->end(); it++)
    {
        buffer.append(" ");
        buffer.append((*it)->toString());
    }
    buffer.append("/>");

    char *cstr = new char[buffer.length() + 1];
    strcpy(cstr, buffer.c_str());
    return cstr;
}