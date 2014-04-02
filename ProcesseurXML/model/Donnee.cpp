#include "Donnee.h"

Donnee::Donnee(char *contenu, int codeType): Element()
{
    this->contenu = contenu;
    this->codeType = codeType;
}

char *Donnee::toString()
{
    switch (this->codeType)
    {
    case 0: //Texte
    case 2:
    {
        return this->contenu;
    }
    case 1: //CDATA
    {
        string buffer("<![CDATA[");
        buffer.append(this->contenu);
        buffer.append("]]>");
        char *cstr = new char[buffer.length() + 1];
        strcpy(cstr, buffer.c_str());
        return cstr;
    }
   /* case 2: //Commentaire
    {
        string buffer("");
        buffer.append(this->contenu);
        buffer.append("");
        char *cstr = new char[buffer.length() + 1];
        strcpy(cstr, buffer.c_str());
        return cstr;
    }*/
    }
}