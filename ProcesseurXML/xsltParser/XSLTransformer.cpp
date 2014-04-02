#include "Template.h"
#include "XSLTransformer.h"

using namespace std;

//TODO fonction de comparaison pour la map tree
//TODO implem verification du type réel des objets hériter d'élement avant toute opération
	XSLTransformer::XSLTransformer() {
		cout << "lolilol"<< endl;
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
			for(list<Element*>::iterator it=children.begin();it != children.end(); it++)
			{
					if((*it)->getType() == "xsl" && strcmp((*it)->getName,"template") == 0)
					{
						Template* newTemplate = new Template((ElementBalise*)*it);
						tree.insert(pair<char*,Template*>(newTemplate->getMatch(),newTemplate));
					}
			}	

			//foreach(Template t : tree) 
			set<Element*> templates;
			//Traitement de tous les Templates
			for(map<char*,Template*>::iterator itTemplate=tree.begin();itTemplate != tree.end();itTemplate++)
			{
				//recuperation list de fils
				itTemplate->second->findXSLtemplate(&templates);
				//parcours des balise xsl:templates decrivant les fils
				for (set<Element*>::iterator it=templates.begin();it !=templates.end();it++){
					//ajout de tous les templates comme fils
					if(((*it)->getLesAttributs())->empty())
					{
						//ajouter tous les templates comme fils
						itTemplate->second->addChildren(&tree);
						it = templates.end();
					}
					else
					{
						itTemplate->second->addChild(*tree.find(((*it)->getLesAttributs()).front()->getValue()));
					}
				}

				templates.clear();
			}
		}
	}
