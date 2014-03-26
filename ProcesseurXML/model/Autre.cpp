#include <iostream>
#include "Autre.h"

using namespace std;

<<<<<<< HEAD
Autre::Autre(list<Attribut*>* attrs) 
=======
Autre::Autre(list<Attribut*> * attrs) 
>>>>>>> 6ee51042a7a0921318f213538edb488c50fdd244
{
	this->attributs = attrs;
}

Autre::~Autre()
{
	delete(this->attributs);
}