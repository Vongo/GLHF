#include "XMLValidator.h"
#include <fstream>
#include <boost/regex.hpp>


using namespace std;

XMLValidator::XMLValidator(Document* XMLDocument, Document* XSDDocument)
{
	this->XMLDocument = XMLDocument;
	this->XSDDocument = XSDDocument;
}

XMLValidator::initMap()
{
	Element* elementRacine = (*XSDDocument)->getElementRacine();
	list<Element *> fils = (*elementRacine->getLesElements());

	for(list<Element *>::iterator it = fils.begin() ; it != fils.end() ; it++) 
	{
		Element * eltComplexType = (*(**it)->getLesElements())[0];
		Element * petitFils = ((*eltComplexType)->getLesElements())[0];

		if( strcmp((*petitFils)->getName(), "sequence") == 0 )
		{
			string regex = constructSeqRegex((*petitFils)->getLesElements());
			Attribut * attrName =  (*(**it)->getLesAttributs())[0];
			elementToRegex[(*attrName)->getValue()] = regex;
		}
		else if(strcmp((*petitFils)->getName(), "choice") == 0)
		{
			string regex = constructChoiceRegex((*petitFils)->getLesElements());
			Attribut * attrName =  (*(**it)->getLesAttributs())[0];
			elementToRegex[(*attrName)->getValue()] = regex;
		}
	}
}

XMLValidator::constructChoiceRegex(List<Element*> * elements)
{
	string regex = "";

	for(list<Element *> *::iterator it = elements.begin() ; it != elements.end() ; it++)
	{
		Attribut * attr1 = (*(**it)->getLesAttributs())[0];
		Attribut * attr2 = (*(**it)->getLesAttributs())[1];

		if( strcmp((*attr1)->getName(), "name") == 0  )
		{
			if ( strcmp((*attr2)->getValue(), "xsd:string") == 0 )
			{
				regex = regex + "<" + (*attr1)->getValue() + ">.*</" + (*attr1)->getValue() + ">" ;
				if (it != elements.end()) 
				{
					regex = regex + "|";
				}
				
			}
			else if ( strcmp((*attr2)->getValue(), "xsd:date") == 0 )
			{

				regex = regex + "<" + (*attr1)->getValue() + ">[0-9]{4}-[0-9]{2}-[0-9]{2}</" + (*attr1)->getValue() + ">" ;
				if (it != elements.end()) 
				{
					regex = regex + "|";
				}
			}
		}
	}

	return regex;
}

XMLValidator::constructSeqRegex(List<Element*> * elements)
{
	string regex = "";

	for(list<Element *> *::iterator it = elements.begin() ; it != elements.end() ; it++)
	{
		Attribut * attr1 = (*(**it)->getLesAttributs())[0];
		Attribut * attr2 = (*(**it)->getLesAttributs())[1];

		if( strcmp((*attr1)->getName(), "name") == 0  )
		{
			if ( strcmp((*attr2)->getValue(), "xsd:string") == 0 )
			{
				regex = regex + "<" + (*attr1)->getValue() + ">.*</" + (*attr1)->getValue() + ">" ;
				if (it != element.end() )
				{
					regex = regex + "$^";
				}
			}
			else if ( strcmp((*attr2)->getValue(), "xsd:date") == 0 )
			{
				regex = regex + "<" + (*attr1)->getValue() + ">[0-9]{4}-[0-9]{2}-[0-9]{2}</" + (*attr1)->getValue() + ">" ;
				if (it != element.end() )
				{
					regex = regex + "$^";
				}
			}
		}
		else if ( strcmp((*attr1)->getName(), "ref") == 0 )
		{
			for(map<string,string>::iterator it = elementToRegex.begin() ; it != elementToRegex.end() ; it++)
			{
				if ( strcmp( (*attr1)->getValue(), it->first) == 0 ))
				{
					
				}
			}
		}
	}

	return regex;
}

XMLValidator::XmlValidation()
{
	ifstream myfile;
	myfile.open ("./files/personne.xml");
	string line;

	while ( getline (myfile,line) )
    {
       string regex = "<personne.*";
       if (boost::regex_match(line, boost::regex(regex)))
       {
       		cout << "youyou";
       }

    }
    myfile.close();
}


