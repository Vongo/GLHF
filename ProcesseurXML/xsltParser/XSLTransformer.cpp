#include "Template.h"
#include "Document.h"
#include <list>
#include <iostream>
#include <string.h>

using namespace std;


	XSLTransformer::XSLTransformer() {
		cout << "lolilol"<< endline;
	}

	XSLTransformer::XSLTransformer(Document xmlRep, Document cat) {
		xml = xmlRep;
		catalog = cat;

		createTemplateTree();

	}

	void XSLTransformer::createTemplateTree() {
		Element* root = xml.getRacine(); // <xsl:stylesheet>
		if (strcmp(root->getName,"xsl:stylesheet") == 0) {
			//Creation de la liste des templates
			list<Element *> children = *(root->getLesElements());
			for(list<Element*>::iterator it=children.begin(),it != children.end(), it++)
			{
					if(strcmp(*(it)->getName,"xsl:template") == 0)
					{
						Template nemTemplate = new Template(*it);
						tree.push(newTemplate);
					}
			}	

			// iterate a second time over tree to add all Templates where no // parent is specified as children to the one without an apply-
			// templates match
			Template* first = tree.front();
			//foreach(Template t : tree) 
			for(list<Template*>::iterator it=tree.begin(),it != tree.end(), it++)
			{
				ElementBalise* eb = *(it)->getContent;
				getXSLApply(eb);
			}
		}
	}
	
	Element* XSLTransformer::getXSLApply(ElementBalise* eb) {
		for(list<Element*>::iterator it=*(eb)->getLesElements.begin(),it != *(eb)->getLesElements.end(), it++)
		{
			if(strcmp(*(it)->getName,"xsl:apply-templates") == 0)
			{
				return *(it);
			} else {
				return getXSLApply(*(it));
			}
		}
	}

	void XSLTransformer::addContent(Template t) {
        children = getContent().getChildren();
        for(list<Template>::iterator it=children.begin(),it!= children.end(),it++){
			if (child instanceOf Donnee) { // treat text nodes like "Title :"
				t.addToOutput(child);
			} else if (child instanceOf ElementBalise) {
				// récupérer le nom et tester le nom
				String name = child.getName();
				if (name.equals("xsl:apply-templates" && child.getAttributes !empty)) {
					Template filsT = tree.get(child.getAttribute("match"));
					t.addChild(filsT);
					filsT.setParent(t);
				} else if (name.equals("xsl:value-of")) {


				} else if (name.equals("xsl:for-each")) {

				}
			}
		}
	}
}
