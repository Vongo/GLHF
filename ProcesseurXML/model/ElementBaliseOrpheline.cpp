#include "ElementBaliseOrpheline.h"

ElementBaliseOrpheline::ElementBaliseOrpheline(char *pNom, char *pContenu): Element(pContenu)
{
    this->nom = pNom;
}
ElementBaliseOrpheline::~ElementBaliseOrpheline()
{
    delete this->nom;
}