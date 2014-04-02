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
    Autre(char *, list<Attribut *> *);
    ~Autre();
    char *toString();
    char *getName();
    list<Attribut *> *getLesAttributs();
private:
    list<Attribut *> *attributs;
    char *nom;
};

#endif