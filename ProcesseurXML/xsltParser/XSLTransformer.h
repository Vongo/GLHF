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
		map <char*,Template*> tree;
		
		void createTemplateTree();
		void addContent(Template t);



};
#endif