#include "ElementBaliseOrpheline.h"

ElementBaliseOrpheline::ElementBaliseOrpheline(char *pNom){
	this->nom = pNom;
}
ElementBaliseOrpheline::~ElementBaliseOrpheline(){
	delete this->nom;
}