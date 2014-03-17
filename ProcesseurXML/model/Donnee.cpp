#include "Donnee.h"
#include <iostream>

using namespace std;

Donnee::Donnee(string contenu,int codeType):Element(contenu)
{
	this.codeType=codeType;
}