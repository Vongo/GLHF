#include "Document.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;

Document::Document()
{

}

Document::Document(list<EnTete *> *enTetes, Element *elementRacine)
{
    this->enTetes = enTetes;
    this->elementRacine = elementRacine;
}

Document::Document(Element *elementRacine)
{
    this->enTetes = 0;
    this->elementRacine = elementRacine;
}

Document::~Document()
{
    delete(this->enTetes);
    delete(this->elementRacine);
}

Element *Document::getRacine()
{
    return this->elementRacine;
}

char *Document::toString()
{
    cout<< this->elementRacine->toString()<<endl;
}
