#include "ElementBalise.h"

ElementBalise::ElementBalise(): Element("\0")
{
    this->lesAttributs = new list<Attribut *>();
    this->lesElements = new list<Element *>();
}
ElementBalise::ElementBalise(char *nom, char *contenu, list<Attribut *> *attributs, list<Element *> *elements): Element(contenu)
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