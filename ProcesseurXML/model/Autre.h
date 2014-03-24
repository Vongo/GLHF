#ifndef AUTRE_H
#define AUTRE_H
#include "Attribut.h"
#include "EnTete.h"

class Autre public EnTete
{
public:
	Autre(list<Attribut> attrs);
private:
	list<Attribut> attributs;
};

#endif