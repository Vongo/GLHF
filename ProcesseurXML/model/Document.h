#ifndef DOCUMENT_H
#define DOCUMENT_H
 
#include <iostream>
#include <vector> 
#include "Element.h"
using namespace std;
 
class Document
{
public:
  Document();
  Document(string path);
 
private: 
  Element elementRacine;

};
 
#endif