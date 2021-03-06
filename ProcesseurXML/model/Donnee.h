#ifndef DONNEE_H
#define DONNEE_H

#include "Attribut.h"
#include <iostream>
#include <string>
#include "Element.h"
using namespace std;

class Donnee: public Element
{
public:
    Donnee(char *, int);
    char *toString();
    list<Attribut *> *getLesAttributs();
    list<Element *> *getLesElements();
    virtual int getCodeType();
    virtual char *getContenu();
    virtual char *getName();
    virtual char *getType();
    void addElement(list<Element*>*tet){};
private:
    char *contenu;
    int codeType; //0:texte 1:CDATA 2:Commentaire
};

#endif