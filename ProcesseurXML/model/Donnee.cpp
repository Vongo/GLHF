#include "Donnee.h"

Donnee::Donnee(char *contenu, int codeType): Element()
{
    this->contenu = contenu;
    this->codeType = codeType;
}

list<Attribut *> *Donnee::getLesAttributs()
{
    return new list<Attribut *>;
}

list<Element *> *Donnee::getLesElements()
{
    return new list<Element *>;
}

char* Donnee::getName()
{
    return "";
}

char* Donnee::getType()
{
    return "";
}

char* Donnee::getContenu()
{
    return contenu;
}

char *Donnee::toString()
{
    switch (this->codeType)
    {
    case 0: //Texte
    case 2: //Commentaire
    {
        return format(this->contenu);
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
    }
}