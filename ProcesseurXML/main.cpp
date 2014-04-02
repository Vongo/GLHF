#include "commun.h"
#include "Errors.h"
#include "model/Document.h"
#include "model/Constants.h"
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
    /////////////////////////////////////cout << endl << endl << resultat << endl << endl;
    return resultat;
}

// TEMP //

int xmltransformation(FILE *xml, FILE *xsl)
{
    return 1;
}

// END TEMP //

//*/
int main(int argc, char const *argv[])
{
    /*/// TEST ZONE //
    int main(int argcT, char const *argvT[])
    {
        int argc = 3;
        const char **argv = (const char **) calloc(3, sizeof(char *));
        argv[0] = "./xmltool";
        argv[1] = "-p";
        argv[2] = "./files/personne.xml";
        /*/

    /*/
    int vRet = checkEntryFormat(argcT, argvT);
    /*/
    int vRet = checkEntryFormat(argc, argv);
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
                // cout << "DO NOT MISS ME" << endl;
                cout << doc->toString() << endl;
                // doc->toString();
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
            //FILE *xml = fopen(argv[2], "r");
            FILE *xsd = fopen(argv[3], "r");
            xmlin = xsd;
            vRet = xmlparse(&doc);
            int retour = xmlvalidation(argv[2], doc);
            //fclose(xml);
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
            break;
        }
        case 't':
        {
            FILE *xml = fopen(argv[2], "r");
            FILE *xsl = fopen(argv[3], "r");
            vRet = xmltransformation(xml, xsl);
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
