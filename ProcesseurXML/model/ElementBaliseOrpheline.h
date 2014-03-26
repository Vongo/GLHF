#ifndef ELEMENT_BALISE_ORPHELINE_H
#define ELEMENT_BALISE_ORPHELINE_H

class ElementBaliseOrpheline: public Element
{
public:
    ElementBaliseOrpheline(char *, list<Attribut *> *);
    ~ElementBaliseOrpheline();
    list<Attribut *> * getLesAttributs();
    char* getName();

private:
	char *nom;
	list<Attribut *> *lesAttributs;
};

#endif