#ifndef ELEMENT_BALISE_ORPHELINE_H
#define ELEMENT_BALISE_ORPHELINE_H

class ElementBaliseOrpheline: public Element
{
public:
    ElementBaliseOrpheline(char *, char*);
    ~ElementBaliseOrpheline();

private:
	char *nom;
};

#endif