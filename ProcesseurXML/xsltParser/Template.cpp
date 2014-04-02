#include "Template.h"

using namespace std;

Template::Template(ElementBalise* rootTemplate){
	//Init match

    list<Attribut *> attributs = *(rootTemplate->getLesAttributs());
    match = attributs.front()->getValue();
    //Init Content
    content = rootTemplate;   
}

void Template::addChild(Template* t) {
	children.push_back(t);
}
void Template::addChildren(map<char*,Template*> *t){

	for(map<char*,Template*>::iterator itAjout = t->begin();itAjout != t->end();itAjout++)
	{
		this->addChild(itAjout->second);
	}
}
list<Element*> findXSLtemplate(set<Template*> *t)
{
	/*for(list<Element*>::iterator it=*(eb)->getLesElements.begin();it != *(eb)->getLesElements.end(); it++)
	{
		if(*(it)->getTypes() == "xsl" && strcmp(*(it)->getName,"apply-templates") == 0)
		{
			return *(it);
		} else {
			return getXSLApply(*(it));
		}
	}*/
}
void Template::setParent(Template* t){
	this->parent = t;
}

void Template::addToOutput(string o) {
	output += o;
}

string Template::getOutput() {
	return output;
}

char* Template::getMatch() {
	return match;
}

ElementBalise* Template::getContent() {
	return content;
}

Template* Template::getParent() {
	return parent;
}

Template* Template::getChild(char* match) {
	for (list<Template*>::iterator it = children.begin(); it != children.end(); it++)
	{
		if (strcmp((*it)->getMatch(),match) == 0) {
			return *it;
		}
	}

	return nullptr;
}

list<Template*> Template::getChildren() {
	return children;
}
