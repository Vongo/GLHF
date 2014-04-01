#include "ElementBalise.h"
#include <string>
#include <list>
#include "Template.h"

using namespace std;

Template::Template() { }

Template::Template(Element* rootTemplate){
	//Init match
    list<Attribut *> attributs = *(rootTemplate->getLesAttributs());
    match = string(*(attributs.front())->getValue());
    //Init Content
    content = rootTemplate;   
}

void Template::addChild(Template t) {
	children.push_back(t);
}

void Template::setParent(Template t) : parent(t) { }

void Template::addToOutput(string o) {
	output += o;
}

string Template::getOutput() {
	return output;
}

string Template::getMatch() {
	return match;
}

ElementBalise* Template::getContent() {
	return content;
}

Template Template::getParent() {
	return parent;
}

Template Template::getChild(string match) {
	for (list<Template>::iterator it = children.begin(); it != children.end(); ++it)
	{
		Template child = *it;
		if (match.compare(child.getMatch()) != 0) {
			it++;
		} else {
			return child;
		}
	}

	return null;
}

list<Template> Template::getChildren() {
	return children;
}
