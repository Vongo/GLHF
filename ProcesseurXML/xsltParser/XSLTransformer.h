#ifndef XSLTRANSFORMER_H
#define XSLTRANSFORMER_H


class XSLTransformer {

	
	public:
		XSLTransformer();
		XSLTransformer(Document xmlRep,Document cat);
	private:

		Document xml;
		Document catalog;
		map<char* match,Template*> tree;
		
		void createTemplateTree();
		void addContent(Template t);


}