#include "Donnee.h"
#include <iostream>

using namespace std;

Donnee::Donnee(char* contenu, int codeType): Element(contenu)
{
    this->codeType = codeType;
}