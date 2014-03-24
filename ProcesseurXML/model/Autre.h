#ifndef AUTRE_H
#define AUTRE_H
#include "Attribut.h"
#include "EnTete.h"

class Autre: public EnTete
{
public:
	Autre(list<Attribut*>* attrs);
	~Autre();
private:
	list<Attribut*>* attributs;
};

#endif