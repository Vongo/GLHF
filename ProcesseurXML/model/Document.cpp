#include "Document.h"
#include "./Constants.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
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
    this->enTetes = new list<EnTete *>();
    this->elementRacine = elementRacine;
}

Document::~Document()
{
    delete(this->enTetes);

}

Element *Document::getRacine()
{
    return this->elementRacine;
}

char *Document::toString()
{
    nbTab = 0;
    string buffer("");
    for (list<EnTete *>::iterator it = this->enTetes->begin(); it != this->enTetes->end(); it++)
    {
        buffer.append((*it)->toString());
        buffer.append("\n");
    }
    buffer.append(this->elementRacine->toString());
    char *cstr = new char[buffer.length() + 1];
    strcpy(cstr, buffer.c_str());
    return cstr;
}

bool Document::hasEnTete()
{
    return !(this->enTetes->empty());
}

list<EnTete *> *Document::getEnTete()
{
    return this->enTetes;
}