#include "Donnee.h"
#include <iostream>

using namespace std;

Donnee::Donnee(char *contenu, int codeType):Element()
{
	this->contenu = contenu;
    this->codeType = codeType;
}