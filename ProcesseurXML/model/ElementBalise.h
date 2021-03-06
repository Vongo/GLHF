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
    char *getType();
    ElementBalise(char *&, list<Element *> *, list<Attribut *> *&, char *);
    ElementBalise (ElementBalise& elemBalise);  //constructeur de copie   
    ~ElementBalise();
    char *toString();
    void addElement(list<Element*>*);
    list<Element*> *getElementsByName(char* name);

private:
    char* type;
    char *nom;
    list<Attribut *> *lesAttributs;
    list<Element *> *lesElements;
};

#endif