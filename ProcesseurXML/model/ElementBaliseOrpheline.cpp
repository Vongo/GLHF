#include "ElementBaliseOrpheline.h"

ElementBaliseOrpheline::ElementBaliseOrpheline(char *pNom, list<Attribut*> *attributs):Element()
{
    this->nom = pNom;
    this->lesAttributs = attributs;
}
ElementBaliseOrpheline::~ElementBaliseOrpheline()
{
    delete this->nom;
}