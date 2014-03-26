#ifndef AUTRE_H
#define AUTRE_H
#include "Attribut.h"
#include "EnTete.h"
#include <list>

class Autre: public EnTete
{
public:
    Autre(list<Attribut *> *);
    ~Autre();
private:
    list<Attribut *> *attributs;
};

#endif