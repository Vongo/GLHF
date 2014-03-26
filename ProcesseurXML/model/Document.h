#ifndef DOCUMENT_H
#define DOCUMENT_H
 
#include <iostream>
#include <vector> 
#include "Element.h"
#include "EnTete.h"
using namespace std;
 
class Document
{
public:
  Document();
  Document(string path);
  Document(list<EnTete*>*, Element*);
  Element* getElementRacine();
 
private:
  Element* elementRacine;
  list<EnTete*> *enTetes;
};
 
#endif