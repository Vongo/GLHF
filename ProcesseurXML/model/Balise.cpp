#include <iostream>
#include "Balise.h"
#include <iterator>
#include <iostream>
using namespace std;

Balise::Balise(char *chaine)
{
    attributs = new list<Attribut>();
    int indice = 0;
    int indiceChevronOuvrant;
    int indiceFinNom;
    int indiceChevronFermant;
    int indiceFinAttributs;
    //On se place au niveau du premier chevron ouvrant
    while (chaine[indice] != '<')
    {
        indice ++;
    }
    indiceChevronOuvrant = indice;
    if (chaine[indiceChevronOuvrant + 1] == '/')
    {
        typeBalise = FERMANTE;
        indice += 2;
        indiceChevronOuvrant++;
    }
    else
    {
        typeBalise = OUVRANTE;
    }

    //On se place au niveau de la fin du nom de la balise
    while (chaine[indice] != '>' && chaine[indice] != ' ' && chaine[indice] != '/')
    {
        indice ++;
    }
    indiceFinNom = indice - 1;

    //Construction du nom de la balise
    char *nomBalise = new char[indiceFinNom - indiceChevronOuvrant];
    for (int i = 0 ; i < indiceFinNom - indiceChevronOuvrant ; i++)
    {
        nomBalise[i] = chaine[i + indiceChevronOuvrant + 1];
    }
    ////////////////////////////////////////////////////////
    //std::cout << nomBaliseTemp;




    //On se place au niveau à la fin
    while (chaine[indice] != '>' && chaine[indice] != '/')
    {
        indice ++;
    }
    if (chaine[indice] == '/')
    {
        typeBalise = ORPHELINE;
        indiceChevronFermant = indice + 1;
    }
    else if (chaine[indice] == '>')
    {
        indiceChevronFermant = indice;
    }
    indiceFinAttributs = indice;

    //Construction des attributs
    char *listeAttributs = new char[indiceFinAttributs - indiceFinNom];
    for (int i = 0 ; i < indiceFinAttributs - indiceFinNom - 1 ; i++)
    {
        listeAttributs[i] = chaine[i + indiceFinNom + 1];
    }

    //Seperattion des differents attributs :
    int indiceGuillemetPrecedent = 0;
    int indiceGuillemetSuivant = 0;
    int nbGuillemets = 0;
    for (int i = 0 ; i < indiceFinAttributs - indiceFinNom - 1 ; i++)
    {
        if (listeAttributs[i] == '"')
        {
            nbGuillemets ++;
        }
        if (nbGuillemets == 2)
        {
            indiceGuillemetSuivant = i;
            char *unAttribut = new char[indiceGuillemetSuivant - indiceGuillemetPrecedent + 1];
            for (int j = 0 ; j < indiceGuillemetSuivant - indiceGuillemetPrecedent ; j++)
            {
                unAttribut[j] = listeAttributs[j + indiceGuillemetPrecedent + 1];
            }
            attributs.push_back(unAttribut);
            //std::cout << "un attribut : " << unAttribut << std::endl;
            delete unAttribut;
            nbGuillemets = 0;
            indiceGuillemetPrecedent = indiceGuillemetSuivant;
        }
    }

    //attributs = Attributs(listeAttributs);
    /////////////////////////////////////////////////////////
    //std::cout << listeAttributs;
    delete listeAttributs;
    //std::cout << typeBalise;

}

Balise::~Balise()
{
    delete attributs;
    delete nomBalise;
}

Balise::toString()
{
	if (typeBalise == 0)
	{
		cout << "<" << nomBalise <<;
	}
	else if (typeBalise == 1)
	{
		cout << "</" << nomBalise <<;
	}
	else
	{
		cout << "<" << nomBalise <<;
	}
    for (Attribut::const_iterator att = Attribut.begin(); att != Attribut.end()
	{
		cout << Attribut[att] << "," << ;
	}
	cout << ">" << endl;
// cout typeBalise
// boucle Attribut (iterator).toString()
// cout nomBalise
}
