#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include "./Constants.h"

class Attribut
{
public:
    Attribut(const char *);
    Attribut(char *, char *);
    char* getValue();
    char* getName();
    ~Attribut();

    /* data */
private:
    char *value;
    char *name;
};


#endif