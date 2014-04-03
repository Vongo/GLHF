#include "XSLTransformer.h"




using namespace std;

//TODO fonction de comparaison pour la map tree
//TODO implem verification du type réel des objets hériter d'élement avant toute opération
XSLTransformer::XSLTransformer()
{
    cout << "lolilol" << endl;
}

XSLTransformer::XSLTransformer(Document docXml, Document docXsl)
{
    this->docXml = docXml;
    this->docXsl = docXsl;

    typeXsl = "xsl";
    applytemplates = "apply-templates";
    valueof = "value-of";
    foreach = "for-each";
    createTemplateTree();

}

Document *XSLTransformer::geneDoc()
{
    Element *currentNode  = docXml.getRacine();
    list<Element *> *result;
    // on cherche le template special s'appliquant a root

    map<string, Template *>::iterator itTemplateRoot = tree.find("/");

    if (itTemplateRoot != tree.end())
    {
        result = executeTemplate(&*(itTemplateRoot->second)->getContent(), &*currentNode);
    }
    else
    {
        //on cherche les template pour les fils de root
        result = applyTemplateOnChildren(currentNode);
    }
    if (result->size() == 1)
    {
        ElementBalise *nRoot = (ElementBalise *)result->front();
        if (!docXml.hasEnTete())
        {
            Document *docTrans = new Document(nRoot);
        }
        else
        {
            Document *docTrans = new Document(docXml.getEnTete(), nRoot);
        }


    }
}
list<Element *> *XSLTransformer::applyTemplateOnChildren(Element *currentNode)
{
    list<Element *> *resultChild;
    list<Element *> *result;

    list<Element *> *children = currentNode->getLesElements();

    for (list<Element *>::iterator itChildren = children->begin(); itChildren != children->end(); itChildren++)
    {
        map<string, Template *>::iterator itTemplateRoot = tree.find(string(currentNode->getName()));

        if (itTemplateRoot != tree.end())
        {
            resultChild = executeTemplate(itTemplateRoot->second->getContent(), *itChildren);
            result->insert(result->begin(), resultChild->begin(), resultChild->end());

        }
        else
        {
            resultChild = applyTemplateOnChildren(*itChildren);
            result->insert(result->begin(), resultChild->begin(), resultChild->end());
        }
    }
    return result;
}

list<Element *> *XSLTransformer::executeTemplate(Element *currentNodeTemplate, Element *currentNodeModel)
{

    list<Element *> *children = currentNodeModel->getLesElements();
    list<Element *> *resultChild;
    list<Element *> *result;
    for (list<Element *>::iterator itChildren = children->begin(); itChildren != children->end(); itChildren++)
    {

        Element *nElement = new Element(*(*itChildren));

        if (strcmp((*itChildren)->getType(), typeXsl) > 0)
        {

            resultChild = executeTemplate(*itChildren, currentNodeModel);

        }
        else
        {
            //<xsl:apply-templates...>
            if (strcmp((*itChildren)->getName(), this->applytemplates) == 0)
            {
                //test si select dans apply-template
                if ((*itChildren)->getLesAttributs() != NULL)
                {

                    char *match = (*itChildren)->getLesAttributs()->front()->getValue();
                    //recuperation du template par match
                    Template *templateCourant = tree.find(string(match))->second;
                    //recuperation des enfants donc le nom correspond au template
                    list<Element *> *childrenOk = currentNodeModel->getElementsByName(match);
                    //execution du template pour chaque enfants
                    for (list<Element *>::iterator it = childrenOk->begin(); it != childrenOk->end(); it++)
                    {
                        resultChild = executeTemplate(templateCourant->getContent(), *it);
                    }
                }//si apply template orpheline
                else
                {
                    for (map<string, Template *>::iterator itTemplate = tree.begin(); itTemplate != tree.end(); itTemplate++)
                    {
                        for (list<Element *>::iterator itChildren = children->begin(); itChildren != children->end(); itChildren++)
                        {
                            resultChild = executeTemplate(itTemplate->second->getContent(), *itChildren);
                        }
                    }
                }
            }
            //<xsl:value-of...>
            else if (strcmp((*itChildren)->getName(), this->valueof) == 0)
            {
                //recuperation valeur du select
                char *select = (*itChildren)->getLesAttributs()->front()->getValue();
                if (strcmp(select, ".") == 0)
                {
                    //todo
                }
                list<Element *> *children = currentNodeModel->getElementsByName(select);
                Donnee *nDonnee = new Donnee(children->front()->getContenu(), children->front()->getCodeType());
                resultChild->push_front(nDonnee);

            }
            else if (strcmp((*itChildren)->getName(), this->foreach) == 0)
            {
                char *select = (*itChildren)->getLesAttributs()->front()->getValue();

                string selectString = string(select);
                int pos = selectString.find_last_of("/");
                string node = selectString.substr(pos, string::npos);

                list<Element *> *bite = docXml.getRacine()->getElementsByName((char *)node.c_str());
                for (list<Element *>::iterator itBite = bite->begin(); itBite != bite->end(); itBite++)
                {
                    resultChild = executeTemplate(((*itChildren)->getLesElements()->front()), *itBite);
                }
            }

        }
        nElement->addElement(resultChild);
        result->push_back(nElement);
    }
    return result;
}

void XSLTransformer::createTemplateTree()
{
    Element *root = docXsl.getRacine(); // <xsl:stylesheet>
    if (root->getType() == "xsl" && strcmp(root->getName(), "stylesheet") == 0)
    {
        //Creation de la liste des templates
        list<Element *> children = *(root->getLesElements());
        for (list<Element *>::iterator it = children.begin(); it != children.end(); it++)
        {
            if ((*it)->getType() == "xsl" && strcmp((*it)->getName(), "template") == 0)
            {
                Template *newTemplate = new Template((ElementBalise *)*it);
                tree.insert(pair<string, Template *>(newTemplate->getMatch(), newTemplate));
            }
        }

        /*//foreach(Template t : tree)
        set<Element *> templates;
        //Traitement de tous les Templates
        for (map<string, Template *>::iterator itTemplate = tree.begin(); itTemplate != tree.end(); itTemplate++)
        {
            //recuperation list de fils
            itTemplate->second->findXSLtemplate(&templates);
            //parcours des balise xsl:templates decrivant les fils
            for (set<Element *>::iterator it = templates.begin(); it != templates.end(); it++)
            {
                //ajout de tous les templates comme fils
                if (((*it)->getLesAttributs())->empty())
                {
                    //ajouter tous les templates comme fils
                    itTemplate->second->addChildren(&tree);
                    it = templates.end();
                }
                else
                {
                    string strLol = string((*it)->getLesAttributs()->front()->getValue());
                    itTemplate->second->addChild(tree.find(strLol));
                }
            }

            templates.clear();
        }*/
    }
}
