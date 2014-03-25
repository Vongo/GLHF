#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <vector>
using namespace std;

class Element
{
public:
  	Element(char* contenu);

private:
	char* contenu;
	vector<Element> elementsIncluded;
};

#endif