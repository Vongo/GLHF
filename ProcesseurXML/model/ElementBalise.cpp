#include "ElementBalise.h"

ElementBalise::ElementBalise(): Element()
{
    this->lesAttributs = new list<Attribut *>();
    // this->lesElements = (list<Element*>**) calloc(2, sizeof(list<Element*>*));
    this->lesElements = new list<Element *>();
}

ElementBalise::ElementBalise(char *&nom, list<Element *> *elements, list<Attribut *> *&attributs, char *type): Element()
{
    this->lesAttributs = attributs;
    this->lesElements = elements;
    this->nom = nom;
    this->type = type;
}

ElementBalise::ElementBalise(ElementBalise &elemBalise): Element((Element)elemBalise)
{
    cout <<"kikoo1"<< endl;
    // this->lesAttributs = list(*(elemBalise.getLesAttributs()));
    this->lesAttributs = new list<Attribut *>;
    this->lesAttributs = elemBalise.lesAttributs;
    // this->lesElements = new list<Element *>;
    //this->lesElements = elemBalise.getLesElements();
    cout <<"kikoo2"<<endl;
    nom = elemBalise.nom;
    cout <<"kikoo3"<<endl;
    type = elemBalise.type;
    cout<<"kikoo4"<<endl;
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
    // cout << "ELEMENT_BALISE_TOSTRING" << endl;
    // cout<< "J'ai "<< this->lesElements[0]->size()<<this->lesElements[1]->size()<<" enfants."<<endl;
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

    buffer.append("\n");
    buffer.append("</");
    buffer.append(this->nom);
    buffer.append(">");
    
    char *cstr = new char[buffer.length() + 1];
    strcpy(cstr, buffer.c_str());
    return cstr;
}