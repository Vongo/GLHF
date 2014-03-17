#ifndef ATTRIBUT
#define ATTRIBUT

#include "./Constants.h"

class Attribut
{
public:
    Attribut(const char *);
    ~Attribut();

    /* data */
private:
    char *value;
    char *name;
};


#endif