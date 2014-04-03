#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <list>
#include "Attribut.h"
// #include <vector>
using namespace std;

class Element
{
public:
    //variable contenu = de la balise ouvrante a la fermante incluses
    Element();
    Element(const Element &) {}       //constructeur de copie
    virtual char *toString()
    {
        cout << "YOU SHOULDN'T BE HERE" << endl;
        return 0;
    }
    virtual list<Element *> *getLesElements()
    {
        cout << "YOU SHOULDN'T BE HERE" << endl;
        return 0;
    }
    virtual char *getName()
    {
        cout << "YOU SHOULDN'T BE HERE" << endl;
        return 0;
    }
    virtual list<Attribut *> *getLesAttributs()
    {
        cout << "YOU SHOULDN'T BE HERE" << endl;
        return 0;
    }

    virtual char *getType()
    {
        cout << "YOU SHOULDN'T BE HERE" << endl;
        return 0;
    }
    virtual void addElement(list<Element *> *)
    {
        cout << "YOU SHOULDN'T BE HERE OLOL" << endl;
    }
    virtual list<Element *> *getElementsByName(char *)
    {
        cout << "YOU SHOULDN'T BE HERE" << endl;
        return 0;
    }
    virtual char *getContenu()
    {
        cout << "YOU SHOULDN'T BE HERE" << endl;
        return 0;
    }
    virtual int getCodeType()
    {
        cout << "YOU SHOULDN'T BE HERE" << endl;
        return 0;
    }
private:
    // vector<Element> elementsIncluded;

};

#endif
