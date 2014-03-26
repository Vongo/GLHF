#include "ElementBalise.h"

ElementBalise::ElementBalise(): Element("\0")
{
    this->lesAttributs = new list<Attribut *>();
    this->lesElements = new list<Element *>();
}
ElementBalise::ElementBalise(char *nom, list<Attribut *> *attributs, list<Element *> *elements): Element(contenu)
{
    this->lesAttributs = attributs;
    this->lesElements = elements;
    this->nom = nom;
}

list<Element *> * ElementBalise::getLesElements()
{
	return lesElements;
}

list<Attribut *> * ElementBalise::getLesAttributs
{
	return lesAttributs;
}

char* ElementBalise::getName()
{
	return nom;
}

ElementBalise::~ElementBalise()
{
    delete lesAttributs;
    delete nom;
}