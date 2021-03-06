#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include "./Constants.h"
#include <string.h>
#include <stdio.h>
using namespace std;

class Attribut
{
public:
    Attribut(const Attribut &);        //constructeur de copie   
    Attribut(char *, char *);
    char* getValue();
    char* getName();
    ~Attribut();
    char *toString();

    /* data */
private:
    char *value;
    char *name;
};


#endif