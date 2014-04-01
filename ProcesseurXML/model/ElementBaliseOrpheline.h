#ifndef ELEMENT_BALISE_ORPHELINE_H
#define ELEMENT_BALISE_ORPHELINE_H
#include "Element.h"
#include "Attribut.h"
#include <list>

class ElementBaliseOrpheline: public Element
{
public:
    ElementBaliseOrpheline(char *, list<Attribut*>*, char *&type="xml");
    ~ElementBaliseOrpheline();
    list<Attribut *> * getLesAttributs();
    char* getName();

private:
	char* type;
	char *nom;
	list<Attribut*> *lesAttributs;
};

#endif