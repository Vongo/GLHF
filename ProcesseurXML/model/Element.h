#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <vector>
using namespace std;

class Element
{
public:
    //variable contenu = de la balise ouvrante a la fermante incluses
    Element(char *contenu);

private:
    char *contenu;
    vector<Element> elementsIncluded;
};

#endif