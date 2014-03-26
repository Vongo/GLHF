#include "ElementBalise.h"

ElementBalise::ElementBalise(): Element("\0")
{
    this->lesAttributs = new list<Attribut *>();
    this->lesElements = new list<Element *>();
}
ElementBalise::ElementBalise(char *&nom, list<Element *> *elements [2],list<Attribut *> *&attributs): Element()
{
    this->lesAttributs = attributs;
    this->lesElements = elements;
    this->nom = nom;
}
ElementBalise::~ElementBalise()
{
    delete lesAttributs;
    delete nom;
}