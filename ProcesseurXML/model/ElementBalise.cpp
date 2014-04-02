#include "ElementBalise.h"

ElementBalise::ElementBalise(): Element()
{
    this->lesAttributs = new list<Attribut *>();
    this->lesElements = new list<Element *>();
}

ElementBalise::ElementBalise(char *&nom, list<Element *> *elements [2], list<Attribut *> *&attributs, char * type): Element()
{
    this->lesAttributs = attributs;
    this->lesElements = *elements;
    this->nom = nom;
    this->type = type;
}

ElementBalise::ElementBalise(ElementBalise& elemBalise):Element((Element)elemBalise)     
{   
    // this->lesAttributs = list(*(elemBalise.getLesAttributs()));
    this->lesAttributs = new list<Attribut *>;
    this->lesAttributs = elemBalise.getLesAttributs();
    this->lesElements = new list<Element *>;
    this->lesElements = elemBalise.getLesElements();
    strcpy(this->nom, elemBalise.nom);
    strcpy(this->type, elemBalise.type);
    // this->lesAttributs=new list<Attribut>(*(elemBalise.getLesAttributs()));  
   // this->lesElements=new list<Element>(*(elemBalise.getLesElements())); 
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

char *ElementBalise::getType()
{
    return type;
}

ElementBalise::~ElementBalise()
{
    delete lesAttributs;
    delete nom;
}

char *ElementBalise::toString()
{
    cout << "kikoo" << endl;
    string buffer("<");
    buffer.append(this->nom);

    for (list<Attribut *>::iterator it = this->lesAttributs->begin(); it != this->lesAttributs->end(); it++)
    {
        buffer.append(" ");
        buffer.append((*it)->toString());
    }
    buffer.append(">");
    
    //Boucle pour les elements
    for (list<Element *>::iterator it = this->lesElements->begin(); it != this->lesElements->end(); it++)
    {
        buffer.append("\n");
        buffer.append((*it)->toString());
    }
    
    buffer.append("</");
    buffer.append(this->nom);
    buffer.append(">");

    char *cstr = new char[buffer.length() + 1];
    strcpy(cstr, buffer.c_str());
    return cstr;
}