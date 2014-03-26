#include "ElementBaliseOrpheline.h"

ElementBaliseOrpheline::ElementBaliseOrpheline(char *pNom, list<Attribut *> *lesAttributs): Element(pContenu)
{
    this->nom = pNom;
    this->lesAttributs->lesAttributs;
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