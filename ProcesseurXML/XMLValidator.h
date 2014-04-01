#ifndef BALISE_H
#define BALISE_H

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