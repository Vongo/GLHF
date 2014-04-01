#include "ElementBalise.h"

ElementBalise::ElementBalise(): Element()
{
    this->lesAttributs = new list<Attribut *>();
    this->lesElements = new list<Element *>();
}

ElementBalise::ElementBalise(char *&nom, list<Element *> *elements [2], list<Attribut *> *&attributs): Element()
{
    this->lesAttributs = attributs;
    this->lesElements = *elements;
    this->nom = nom;
}

list<Element *> *ElementBalise::getLesElements()
{
    return lesElements;
}

list<Attribut *> *ElementBalise::getLesAttributs()
{
    return lesAttributs;
}

char *ElementBalise::getName()
{
    return nom;
}

ElementBalise::~ElementBalise()
{
    delete lesAttributs;
    delete nom;
}

char* toString()
{
	string stringContenu="<";
	stringContenu+=this->nom;

	//Boucle pour les arguments
	for (list<Attribut *>::iterator it = this->attributs.begin(); it != fifth.end(); it++)
	{
		stringContenu+= " ";
		stringContenu+= *it->toString();
	}
	stringContenu+=" >"

	//Boucle pour les elements
	for (list<Element *>::iterator it = this->attributs.begin(); it != fifth.end(); it++)
	{
		stringContenu+= "\n\r";
		stringContenu+= *it->toString();
	}


	stringContenu+="</";
	stringContenu+=this->nom;
	stringContenu+=">"

}