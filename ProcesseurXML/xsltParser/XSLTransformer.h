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

	/*struct cmp_str
	{
   		bool operator()(char const *a, char const *b)
		{
			return strcmp(a, b) < 0;
   		}
	};*/

		Document xml;
		Document catalog;
		map <string,Template*> tree;
		
		void createTemplateTree();
		void addContent(Template t);
		Document* geneDoc();
		list<Element*>* executeTemplate(Template* t,Element* currentNode);
		list<Element*>* applyTemplateOnChildren(Element* currentNode);



};
#endif