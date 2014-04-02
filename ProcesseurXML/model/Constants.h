#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <string.h>
using namespace std;

#define MAX_ATTRIBUTE_NAME_SIZE 20
#define MAX_ATTRIBUTE_VALUE_SIZE 255

typedef enum TypeBalise {OUVRANTE, FERMANTE, ORPHELINE} TypeBalise;
static int nbTab;
const char TAB = ' ';

static char *getTabulation()
{
    char *tabs = new char[nbTab + 1];
    for (int i = 0; i < nbTab; ++i)
    {
        tabs[i] = TAB;
    }
    tabs[nbTab] = '\0';
    return tabs;
}

static char *format(char *someLine)
{
    string newLine(getTabulation());
    newLine.append(someLine);
    char *cstr = new char[newLine.length() + 1];
    strcpy(cstr, newLine.c_str());
    return cstr;
}

static void moarIndent(){
	nbTab++;
}

static void lessIndent(){
	nbTab--;
}

#endif