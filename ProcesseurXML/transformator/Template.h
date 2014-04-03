#ifndef TEMPLATE_H
#define TEMPLATE_H value

#include <string>
#include <list>
#include "../model/ElementBalise.h"
#include "../model/Donnee.h"
#include <set>
#include <map>

using namespace std;

class Template
{

private:
    list<Template *> children;
    Template *parent;

    ElementBalise *content;
    char *match;

public:
    Template(ElementBalise *rootTemplate);

    void addChild(Template *t);
    void addChildren(map<string, Template *> *t);
    void setParent(Template *t);
    char *getMatch();
    Element *getContent();
    Template *getParent();
    Template *getChild(char *match);
    list<Template *> getChildren();
    set<Element *> findXSLtemplate(set<Element *> *t);
};
#endif