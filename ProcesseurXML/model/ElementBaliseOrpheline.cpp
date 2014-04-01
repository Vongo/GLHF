#include "ElementBaliseOrpheline.h"


ElementBaliseOrpheline::ElementBaliseOrpheline(char *pNom, list<Attribut*> *attributs, char *type):Element()
{
    this->nom = pNom;
    this->lesAttributs = attributs;
    this->type = type;
}

char* ElementBaliseOrpheline::getName()
{
	return nom;
}

char* ElementBaliseOrpheline::getType()
{
    return type;
}

list<Attribut *> * ElementBaliseOrpheline::getLesAttributs()
{
	return lesAttributs;
}

ElementBaliseOrpheline::~ElementBaliseOrpheline()
{
    delete this->nom;
}