#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <list>
#include <vector>
#include "Element.h"
#include "EnTete.h"
using namespace std;

class Document
{
public:
    Document();
    Document(Element *);
    Document(list<EnTete *> *, Element *);
    ~Document();

private:
    Element *elementRacine;
    list<EnTete *> *enTetes;
};

#endif