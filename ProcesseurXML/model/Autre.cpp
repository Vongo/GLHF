#include "Autre.h"

Autre::Autre(list<Attribut *> *attrs):EnTete()
{
    this->attributs = attrs;
}

Autre::~Autre()
{
    delete(this->attributs);
}