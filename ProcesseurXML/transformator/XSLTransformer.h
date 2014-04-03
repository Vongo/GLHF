#ifndef XSLTRANSFORMER_h
#define XSLTRANSFORMER_h


#include <list>
#include <iostream>
#include <string.h>
#include <map>
#include "../model/ElementBalise.h"
#include "../model/Donnee.h"
#include "Template.h"
#include "../model/Document.h"

class XSLTransformer
{


public:
    XSLTransformer();
    XSLTransformer(Document docXml, Document docXsl);
private:

    Document docXml, docXsl;

    map <string, Template *> tree;
    char *typeXsl;
    char *applytemplates;
    char *valueof;
    char *foreach;
    void createTemplateTree();
    void addContent(Template t);
    Document *geneDoc();
    list<Element *> *executeTemplate(Element *currentNodeTemplate, Element *currentNodeModel);
    list<Element *> *applyTemplateOnChildren(Element *currentNode);



};
#endif