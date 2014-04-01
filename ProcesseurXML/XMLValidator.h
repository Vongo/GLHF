#ifndef BALISE_H
#define BALISE_H

#include <string>
#include <map>
#include "./model/Document.h"


using namespace std;

class XMLValidator
{
public:
	XMLValidator(Document*, Document*);
	initMap();
	constructChoiceRegex();
	constructSeqRegex();
	int XmlValidation();

private:
	Document* XMLDocument;
	Document* XSDDocument;
	map<string,string> elementToRegex;
};

#endif