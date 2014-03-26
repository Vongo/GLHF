#ifndef XSLTRANSFORMER_H
#define XSLTRANSFORMER_H


class XSLTransformer {

	Document xml;
	Document catalog;
	List<Template> tree;
	
	public:
		XSLTransformer();
		XSLTransformer(XML xmlRep, XMLRep cat);
	private:
		void createTemplateTree();
		void addContent(Template t);


}