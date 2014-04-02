#ifndef TEMPLATE_H
#define TEMPLATE_H value

#include <string>
#include <list>
#include <ElementBalise.h>
#include <set>
#include <map>

using namespace std;

class Template{

private:
	list<Template *> children;
	Template* parent;
	string output;
	ElementBalise* content;
	char* match;
	
public:
	Template(ElementBalise* rootTemplate);

	void addChild(Template* t);
	void addChildren(map<string,Template*>* t);
	void setParent(Template* t);
	void addToOutput(string);
	string getOutput();
	char* getMatch();
	ElemenT* getContent();
	Template* getParent();
	Template* getChild(char* match);
	list<Template*> getChildren();
	set<Element*> findXSLtemplate(set<Element*> *t);
};
#endif