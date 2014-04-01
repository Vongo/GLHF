#include "Donnee.h"
#include <iostream>

using namespace std;

Donnee::Donnee(char *contenu, int codeType):Element()
{
	this->contenu = contenu;
    this->codeType = codeType;
}

string toString()
{
	switch(this->codeType)
	{
		case 0: //Texte
		{
			string stringContenu(this->contenu);
			return stringContenu;
		}
		case 1: //CDATA
		{
			string stringContenu = "<![CDATA[";
			stringContenu+= this->contenu;
			stringContenu+= "]]>";

			return stringContenu;			
		}
		case 2: //Commentaire
		{
			string stringContenu = "<!-- ";
			stringContenu+= this->contenu;
			stringContenu+= " -->";

			return stringContenu;
		}
	}
}