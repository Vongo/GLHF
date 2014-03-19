#include <iostream>
#include "Balise.h"

Balise::Balise(char *chaine)
{
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
    //On se place au niveau de la fin du nom de la balise
    while (chaine[indice] != '>' && chaine[indice] != ' ' && chaine[indice] != '/')
    {
        indice ++;
    }
    indiceFinNom = indice - 1;

    //Construction du nom de la balise
    char *nomBaliseTemp = new char[indiceFinNom - indiceChevronOuvrant];
    for (int i = 0 ; i < indiceFinNom - indiceChevronOuvrant ; i++)
    {
        nomBaliseTemp[i] = chaine[i + indiceChevronOuvrant + 1];
    }
    //nomBalise = Nom(nomBaliseTemp);
    ////////////////////////////////////////////////////////
    std::cout << nomBaliseTemp;
    delete nomBaliseTemp;

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
        typeBalise = OUVRANTE;
        indiceChevronFermant = indice;
    }
    indiceFinAttributs = indice;

    //Construction des attributs
    char *listeAttributs = new char[indiceFinAttributs - indiceFinNom];
    for (int i = 0 ; i < indiceFinAttributs - indiceFinNom - 1 ; i++)
    {
        listeAttributs[i] = chaine[i + indiceFinNom + 1];
    }
    //attributs = Attributs(listeAttributs);
    /////////////////////////////////////////////////////////
    std::cout << listeAttributs;
    delete listeAttributs;


}

Balise::~Balise()
{
}
