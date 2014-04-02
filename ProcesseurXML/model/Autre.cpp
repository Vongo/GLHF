#include "Autre.h"

Autre::Autre(char *pNom, list<Attribut *> *attrs): EnTete()
{
    this->nom = pNom;
    this->attributs = attrs;
}

Autre::~Autre()
{
    delete(this->attributs);
}

char *Autre::toString()
{
    string buffer(format("<?"));
    buffer.append(this->nom);
    buffer.append(" ");

    for (list<Attribut *>::iterator it = this->attributs->begin(); it != this->attributs->end(); it++)
    {
        buffer.append(format((*it)->toString()));
        buffer.append(" ");
    }
    buffer.append("?>");
    char *cstr = new char[buffer.length() + 1];
    strcpy(cstr, buffer.c_str());
    return cstr;
}