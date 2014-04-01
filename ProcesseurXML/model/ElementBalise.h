#ifndef ELEMENT_BALISE_H
#define ELEMENT_BALISE_H

#include "Element.h"
#include <list>
#include "Attribut.h"

class ElementBalise: public Element
{
public:
    ElementBalise();
    list<Attribut *> *getLesAttributs();
    list<Element *> *getLesElements();
    char *getName();
    ElementBalise(char *&, list<Element *> *[2], list<Attribut *> *&);
    ~ElementBalise();
    char *toString();

private:
    char *nom;
    list<Attribut *> *lesAttributs;
    list<Element *> *lesElements;
};

#endif