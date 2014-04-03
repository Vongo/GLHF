#ifndef ELEMENT_BALISE_ORPHELINE_H
#define ELEMENT_BALISE_ORPHELINE_H
#include "Element.h"
#include "Attribut.h"
#include <list>

class ElementBaliseOrpheline: public Element
{
public:
    ElementBaliseOrpheline(char *, list<Attribut*>*, char *);
    ~ElementBaliseOrpheline();
    ElementBaliseOrpheline (ElementBaliseOrpheline& elemBaliseOrph);
    list<Attribut *> * getLesAttributs();
    list<Element *> *getLesElements();
    char* getName();
    char *toString();
    char* getType();

private:
	char *type;
	char *nom;
	list<Attribut*> *lesAttributs;
};

#endif