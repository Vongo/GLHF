#ifndef DONNEE_H
#define DONNEE_H

#include <iostream>
#include "Element.h"
using namespace std;

class Donnee: public Element
{
public:
    Donnee(char *contenu, int codeType);

private:
	char *contenu;
    int codeType; //0:texte 1:CDATA 2:Commentaire
};

#endif