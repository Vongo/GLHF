#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <vector>
using namespace std;

class Element
{
public:
<<<<<<< HEAD
    //variable contenu = de la balise ouvrante a la fermante incluses
    Element(char *contenu);
=======
  	//variable contenu = de la balise ouvrante a la fermante incluses
  	Element(char* contenu);
>>>>>>> 64de018374f0b6d33c6252c04158808c52c208cf

private:
<<<<<<< HEAD
    char *contenu;
    vector<Element> elementsIncluded;
=======
	char* contenu;
	vector<Element> elementsIncluded;

>>>>>>> 64de018374f0b6d33c6252c04158808c52c208cf
};

#endif