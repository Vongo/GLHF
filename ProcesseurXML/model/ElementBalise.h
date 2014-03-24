#ifndef ELEMENT_BALISE_H
#define ELEMENT_BALISE_H

#include "Element.h"
#include <list>
#include "Attribut.h"

class ElementBalise: public Element
{
public:
    ElementBalise();
    ElementBalise(char *, char *, list<Attribut *> *, list<Element *> *);
    ~ElementBalise();

private:
    char *nom;
    list<Attribut *> *lesAttributs;
    list<Element *> *lesElements;
};

#endif