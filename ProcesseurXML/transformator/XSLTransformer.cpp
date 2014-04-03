#include "XSLTransformer.h"
#include <typeinfo>




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
    // cout<<this->docXml.toString()<<endl;
    this->docXsl = docXsl;

    typeXsl = "xsl";
    applytemplates = "apply-templates";
    valueof = "value-of";
    foreach = "for-each";
    createTemplateTree();

    cout << tree.size() << endl;
    geneDoc();
}

Document *XSLTransformer::geneDoc()
{

    Element *currentNode  = docXml.getRacine();
    list<Element *> *result;
    Document *docTrans;
    // on cherche le template special s'appliquant a root

    map<string, Template *>::iterator itTemplateRoot = tree.find("/");

    if (itTemplateRoot != tree.end())
    {
        cout << "tutu" << endl;
        cout << currentNode->toString() << endl;
        cout << "louliu" << endl;
        result = executeTemplate(&*(itTemplateRoot->second)->getContent(), currentNode);
        cout << "toto" << endl;
        cout << result->front()->toString() << endl;
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
            docTrans = new Document(nRoot);
        }
        else
        {
            docTrans = new Document(docXml.getEnTete(), nRoot);
        }
    }
    return docTrans;
}
list<Element *> *XSLTransformer::applyTemplateOnChildren(Element *currentNode)
{
    cout << "applyTemplateOnChildren" << endl;
    list<Element *> *resultChild = new list<Element *>();
    list<Element *> *result = new list<Element *>();

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

    cout << "executeTemplate" << endl;
    cout << currentNodeTemplate->toString() << endl;
    // list<Element *> *children = currentNodeModel->getLesElements();
    list<Element *> *children = currentNodeTemplate->getLesElements();
    list<Element *> *resultChild = new list<Element *>();

    list<Element *> *result = new list<Element *>();
    // cout<<currentNodeModel->getName()<<endl;
    cout << children->size() << endl;
    for (list<Element *>::iterator itChildren = children->begin(); itChildren != children->end(); itChildren++)
    {
        cout << "on parcours les fils" << endl;

        Element **nElement;

        if (typeid(*(*itChildren)).name() == typeid(ElementBalise).name())
        {
            *nElement = new ElementBalise(*((ElementBalise *)*itChildren));

        }
        else if (typeid(*(*itChildren)).name() == typeid(ElementBaliseOrpheline).name())
        {
            *nElement = new ElementBaliseOrpheline(*((ElementBaliseOrpheline *)*itChildren));

        }
        else if (typeid(*(*itChildren)).name() == typeid(Donnee).name())
        {
            *nElement = new Donnee((*itChildren)->getContenu(), (*itChildren)->getCodeType());

        }

        cout << (*itChildren)->getType() << endl;
        if (strcmp((*itChildren)->getType(), "xsl") != 0)
        {
            cout << "balise pas xsl" << endl;
            resultChild = executeTemplate(*itChildren, currentNodeModel);


        }
        else
        {
            //<xsl:apply-templates...>
            if (strcmp((*itChildren)->getName(), "apply-templates") == 0)
            {
                cout << "c'est un apply-template>" << endl;
                //test si select dans apply-template
                if ((*itChildren)->getLesAttributs() != NULL)
                {

                    char *match = (*itChildren)->getLesAttributs()->front()->getValue();
                    cout << match << endl;
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
                    cout << "orpheline" << endl;
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
        cout << "on tente le size" << endl;
        cout<<resultChild->size()<<endl;
        (*nElement)->addElement(resultChild);
        cout << "aga" << endl;
        result->push_back(*nElement);
    }
    return result;
}

void XSLTransformer::createTemplateTree()
{
    Element *root = docXsl.getRacine(); // <xsl:stylesheet>
    // cout << root->toString()<<endl;
    // cout << root->getType()<<endl;
    // cout << root->getName()<<endl;
    if (strcmp(root->getType(), "xsl") == 0 && strcmp(root->getName(), "stylesheet") == 0)
    {
        //Creation de la liste des templates
        list<Element *> children = *(root->getLesElements());
        for (list<Element *>::iterator it = children.begin(); it != children.end(); it++)
        {
            if (strcmp((*it)->getType(), "xsl") == 0 && strcmp((*it)->getName(), "template") == 0)
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
