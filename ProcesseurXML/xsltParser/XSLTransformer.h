#ifndef XSLTRANSFORMER_h
#define XSLTRANSFORMER_h


#include <list>
#include <iostream>
#include <string.h>
#include <map>
#include "ElementBalise.h"
#include "Template.h"
#include "Document.h"

class XSLTransformer {

	
	public:
		XSLTransformer();
		XSLTransformer(Document xmlRep,Document cat);
	private:

		Document xml;
		Document catalog;
		map <string,Template*> tree;
		static char * typeXsl;
		static char * applytemplates;
		static char * valueof;
		static char * foreach;
		void createTemplateTree();
		void addContent(Template t);
		Document* geneDoc();
		list<Element*>* executeTemplate(Element* currentNodeTemplate,Element* currentNodeModel);
		list<Element*>* applyTemplateOnChildren(Element* currentNode);



};
#endif