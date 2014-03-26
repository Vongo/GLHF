#include "ElementBaliseOrpheline.h"


ElementBaliseOrpheline::ElementBaliseOrpheline(char *pNom, list<Attribut*> *attributs):Element()
{
    this->nom = pNom;
    this->lesAttributs = attributs;
}

char* ElementBaliseOrpheline::getName()
{
	return nom;
}

list<Attribut *> * ElementBaliseOrpheline::getLesAttributs()
{
	return lesAttributs;
}

ElementBaliseOrpheline::~ElementBaliseOrpheline()
{
    delete this->nom;
}