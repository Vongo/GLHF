#ifndef BALISE_H
#define BALISE_H

#include <fstream>
#include <boost/regex.hpp>
#include <string>
#include <map>
#include "../model/Document.h"
#include "../model/Attribut.h"

using namespace std;

typedef struct regOccur
{
	string exprReg;
	int maxOccur;
}regOccur;

class XMLValidator
{
public:
	XMLValidator(const char*, Document*);
	void initMap();
	regOccur constructChoiceRegex(list<Element*> * elements);
	regOccur constructSeqRegex(list<Element*> * elements);
	int XmlValidation();

private:
	const char *XMLDocument;
	Document *XSDDocument;
	map<string,regOccur> elementToRegex;
};

#endif
