#ifndef AUTRE_H
#define AUTRE_H

#include <list>
#include <string>
#include "Attribut.h"
#include "EnTete.h"

using namespace std;

class Autre: public EnTete
{
public:
    Autre(list<Attribut *> *);
    ~Autre();
private:
	string hoho;
    list<Attribut *> *attributs;
};

#endif