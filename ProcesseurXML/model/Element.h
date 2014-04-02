#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
// #include <vector>
// using namespace std;

class Element
{
public:
  	//variable contenu = de la balise ouvrante a la fermante incluses
  	Element();
  	Element(const Element &){}        //constructeur de copie   
  	virtual char *toString(){return 0;}

private:
	// vector<Element> elementsIncluded;

};

#endif