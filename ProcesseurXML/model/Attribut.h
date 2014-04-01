#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include "./Constants.h"
#include <string.h>
#include <stdio.h>
using namespace std;

class Attribut
{
public:
    Attribut(const char *);
    Attribut(char *, char *);
    char* getValue();
    char* getName();
    ~Attribut();
    // string toString();
    char *toString();

    /* data */
private:
    char *value;
    char *name;
};


#endif