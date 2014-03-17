#include "Attribut.h"

Attribut::Attribut(const char *in)
{
    this->name = new char[MAX_ATTRIBUTE_NAME_SIZE];
    this->value = new char[MAX_ATTRIBUTE_VALUE_SIZE];

    int i;
    int iName = 0, iValue = 0;
    for (i = 0; in[i] != '=' && in[i] != '\0'; ++i)
    {
        this->name[iName++] = in[i];
    }
    if (in[i] == '\0')
    {
        // TODO raise flag error
        return;
    }
    i += 1;
    // check comilla
    if (in[i] == '"')
    {
        for (i += 1; in[i] != '"' && in[i] != '\0'; ++i)
        {
            this->value[iValue++] = in[i];
        }
        if (in[i] == '\0')
        {
            // TODO raise flag error
            return;
        }
    }

}
Attribut::~Attribut()
{
	delete(this->name);
	delete(this->value);
}

// <Robert color="pruple"> Blabla </Robert>