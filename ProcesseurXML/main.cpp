#include "commun.h"
#include "Errors.h"
#include "model/Document.h"
#include "model/Constants.h"
#include "transformator/XSLTransformer.h"
#include "validator/XMLValidator.h"
#include <iostream>
#include <cstring>

using namespace std;

int xmlparse(Document **);
int xmlvalidation(FILE *xml, FILE *xsd);
int xmltransformation(FILE *xml, FILE *xsl);

int xmlvalidation(const char *xml, Document *xsd)
{
    XMLValidator xmlValidate(xml, xsd);
    int resultat = xmlValidate.XmlValidation();
    // /////////////////////////////////////cout << endl << endl << resultat << endl << endl;
    return resultat;
    // return 1;
}

// TEMP //

int xmltransformation(FILE *xml, FILE *xsl)
{
    extern FILE *xmlin;

    Document *docXml;
    Document *docXsl;


    xmlin = xml;
    int vRet = xmlparse(&docXml);
    // cout << docXml->toString() << endl;

    xmlin = xsl;
    vRet = xmlparse(&docXsl);


    XSLTransformer *oPrime = new XSLTransformer(*docXml, *docXsl);
    // oPrime->geneDoc();
    cout << "la narmol la transformation elle est bon"<<endl;



    Document *lol = oPrime->geneDoc();
    cout << lol->toString() << endl;
    return 1;
}

// END TEMP //

//*/
int main(int argc, char const *argv[])
{
/*/// TEST ZONE //
int main(int argcT, char const *argvT[])
{
    int argc = 4;
    const char **argv = (const char **) calloc(argc, sizeof(char *));
    argv[0] = "./xmltool";
    argv[1] = "-t";
    argv[2] = "./files/catalog.xml";
    argv[3] = "./files/catalog_apply_templates.xsl";
    //*/
    int vRet = checkEntryFormat(argc, argv);
    /*/
    int vRet = 0;
    //*/
    if (vRet == 1)
        return vRet;
    Document *doc;
    extern FILE *xmlin;
    if (argc == 3)
    {
        if (argv[1][1] == 'p') // Redundant
        {
            FILE *fid = fopen(argv[2], "r");
            xmlin = fid;
            vRet = xmlparse(&doc);
            if (doc != NULL)
            {
                if (vRet == 1)
                {
                    fputs(NO_ROOT_ELEMENT, stderr);
                    return vRet;
                }
                cout << doc->toString() << endl;
            }
            fclose(fid);
        }
    }
    else if (argc == 4)
    {
        switch (argv[1][1])
        {
        case 'v':
        {
            FILE *xsd = fopen(argv[3], "r");
            xmlin = xsd;
            vRet = xmlparse(&doc);
            if (doc != NULL)
            {
                if (vRet == 1)
                {
                    fputs(NO_ROOT_ELEMENT, stderr);
                    return vRet;
                }
            }
            int retour = xmlvalidation(argv[2], doc);
            fclose(xsd);
            string chaineRetour = "The file " + string(argv[2]);
            if (retour == 0)
            {
                chaineRetour += " is valid wrt ";
            }
            else
            {
                chaineRetour += " is not valid wrt ";
            }
            chaineRetour += string(argv[3]);
            fputs(chaineRetour.c_str(), stdout);
            vRet = vRet && retour;
            break;
        }
        case 't':
        {
            FILE *xml = fopen(argv[2], "r");
            FILE *xsl = fopen(argv[3], "r");
            // vRet = xmltransformation(xml, xsl);
            vRet = 1;
            fclose(xml);
            fclose(xsl);
            break;
        }
        }
        if (!vRet)
        {
            // TODO stuff
        }
    }
    return vRet;
}
