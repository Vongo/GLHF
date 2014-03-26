#ifndef ELEMENT_BALISE_ORPHELINE_H
#define ELEMENT_BALISE_ORPHELINE_H
#include "Element.h"

class ElementBaliseOrpheline: public Element
{
public:
    ElementBaliseOrpheline(char *, list<Attribut*>*);
    ~ElementBaliseOrpheline();

private:
	char *nom;
	list<Attribut*> *lesAttributs;
};

#endif