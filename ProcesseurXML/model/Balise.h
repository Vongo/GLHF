#ifndef BALISE_H
#define BALISE_H
#include<list>
#include "Constants.h"
#include "Attribut.h"
class Balise
{
public:
    Balise(char *);
    ~Balise();
private:
    TypeBalise typeBalise;
    char *nomBalise;
    list<Attribut> attributs;
};
#endif