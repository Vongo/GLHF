#include "Attribut.h"

#include <iostream>
using namespace std;

Attribut::Attribut(char *pName, char *pValue)
{
    this->name = pName;
    this->value = pValue;
}

Attribut::Attribut(const Attribut& osef)
{
    // this->value = osef.getValue();
    // this->name = osef.getName();
    cout<< "GET AWAY FROM HERE, YOU PERV"<<endl<<endl;
}

char *Attribut::getValue()
{
    return this->value;
}

char *Attribut::getName()
{
    return this->name;
}

Attribut::~Attribut()
{
    delete(this->name);
    delete(this->value);
}

char *Attribut::toString()
{
    return strcat(strcat(strcat(this->name, "=\""), this->value), "\"");
}
