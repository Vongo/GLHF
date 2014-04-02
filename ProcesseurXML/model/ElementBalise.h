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
    list<Element *> **getLesElements();
    char *getName();
    char *getType();
    ElementBalise(char *&, list<Element *> *[2], list<Attribut *> *&, char *);
    ElementBalise (ElementBalise& elemBalise);        //constructeur de copie   
    ~ElementBalise();
    char *toString();

private:
    char* type;
    char *nom;
    list<Attribut *> *lesAttributs;
    list<Element *> **lesElements;
};

#endif