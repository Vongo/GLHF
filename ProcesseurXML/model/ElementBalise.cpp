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

    this->lesAttributs = elemBalise.lesAttributs;
    this->lesElements = elemBalise.lesElements;
    this->nom = elemBalise.nom;
    this->type = elemBalise.type;
}

list<Element *> *ElementBalise::getLesElements()
{
    // cout << "oukay" << endl;
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

list<Element *> *ElementBalise::getElementsByName(char *name)
{
    list<Element *> *elementsOk = new list<Element *>();
    for (list<Element *>::iterator it = this->lesElements->begin(); it != this->lesElements->end(); it++)
    {
        // if (strcmp((*it)->getName, name) == 0)
        // {
        //     elementsOk->push_back(*it);
        // }
    }
    return elementsOk;
}
ElementBalise::~ElementBalise()
{
    //delete lesAttributs;
    //delete nom;
}

char *ElementBalise::toString()
{
    // cout << "ELEMENT_BALISE_TOSTRING" << endl;
    // cout<< "J'ai "<< this->lesElements[0]->size()<<this->lesElements[1]->size()<<" enfants."<<endl;
    string buffer(format("<"));

    char *b = new char [80];
    if (strcmp(this->type, "xml"))
    {
        strcpy(b, this->type);
        strcat(b, ":");
        strcat(b, this->nom);
    }
    else
        strcpy(b, this->nom);
    buffer.append(b);

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
        moarIndent();
        buffer.append(format((*it)->toString()));
        lessIndent();
    }

    buffer.append("\n");
    buffer.append(format("</"));
    buffer.append(b);
    buffer.append(">");

    char *cstr = new char[buffer.length() + 1];
    strcpy(cstr, buffer.c_str());
    return cstr;
}

void ElementBalise::addElement(list<Element*>* tutu){
    this->lesElements->insert(this->lesElements->begin(),tutu->begin(),tutu->end());
}