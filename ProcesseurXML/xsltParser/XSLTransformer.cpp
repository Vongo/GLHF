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
		if (root->getType() == "xsl" && strcmp(root->getName,"stylesheet") == 0) {
			//Creation de la liste des templates
			list<Element *> children = *(root->getLesElements());
			for(list<Element*>::iterator it=children.begin(),it != children.end(), it++)
			{
					if(*(it)->getType() == "xsl" && strcmp(*(it)->getName,"template") == 0)
					{
						Template nemTemplate = new Template(*it);
						tree.push(newTemplate);
					}
			}	

			Template* first = tree.front();
			//foreach(Template t : tree) 
			set<Element*> *templates;
			//Traitement de tous les Templates
			for(list<Template*>::iterator itTemplate=tree.begin(),itTemplate != tree.end(), itTemplate++)
			{
				//recuperation list de fils
				*(itTemplate)->findXSLtemplate(templates);
				//parcours des balise xsl:templates decrivant les fils
				for (list<Element*>::iterator it=templates->begin(),it !=templates.end(),it++){
					//ajout de tous les templates comme fils
					if((*(it)->getLesAttributs())->empty())
					{
						//ajouter tous les templates comme fils
						*itTemplate->addChildren(&tree);
						it = templates->end();
					}
					else
					{
						*itTemplate->addChild(*tree.find((*(it)->getLesAttributs()).front()->getValue()));
					}
				}

				templates->clear();
			}
		}
	}
	
	Element* XSLTransformer::getXSLApply(ElementBalise* eb) {
		for(list<Element*>::iterator it=*(eb)->getLesElements.begin(),it != *(eb)->getLesElements.end(), it++)
		{
			if(*(it)->getType() == "xsl" && strcmp(*(it)->getName,"apply-templates") == 0)
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
				if (*(it)->getType() == "xsl" && name.equals("apply-templates" && child.getAttributes !empty)) {
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
