#include <iostream>
#include "Autre.h"

using namespace std;

Autre::Autre(list<Attribut *> *attrs)
{
    this->attributs = attrs;
}

Autre::~Autre()
{
    delete(this->attributs);
}