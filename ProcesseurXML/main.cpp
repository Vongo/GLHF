#include "commun.h"
#include "model/Document.h"
#include <iostream>
#include <cstring>

using namespace std;

int xmlparse(Document **);
int xmlvalidation(FILE *xml, FILE *xsd);
int xmltransformation(FILE *xml, FILE *xsl);

// TEMP //

int xmlvalidation(FILE *xml, FILE *xsd)
{
    return 1;
}
int xmltransformation(FILE *xml, FILE *xsl)
{
    return 1;
}

// END TEMP //

int main(int argc, char const *argv[])
{
    Document **doc;
    Document 
    extern FILE *xmlin;
    int retour = 1;
    if (argc == 2)
    {
        switch (argv[1][1])
        {
        case 'h':
            cout << "CECI EST LE MANUEL OLOL" << endl;
            retour = 0;
            break;
        default:
            cout << "Argument non reconnu : " << argv[1][1] << endl;
        }
    }
    else if (argc == 3)
    {
        if (argv[0] == "-p")
        {
            cout << ">> PARSING <<" << endl;
            FILE *fid = fopen(argv[2], "r");
            if (!fid)
            {
                cout << "ACHTUNG OMFGWTF" << endl;
                return 1;
            }
            xmlin = fid;
            vRet = xmlparse(doc);
            fclose(fid);
        }
    }
    else if (argc == 4)
    {
        switch (argv[1][1])
        {
        case 'v':
        {
            FILE *xml = fopen(argv[2], "r");
            FILE *xsd = fopen(argv[3], "r");
            cout << ">> VALIDATION <<" << endl;
            retour = xmlvalidation(xml, xsd);
            fclose(xml);
            fclose(xsd);
            break;
        }
        case 't':
        {
            FILE *xml = fopen(argv[2], "r");
            FILE *xsl = fopen(argv[3], "r");
            cout << ">> TRANSFORMATION <<" << endl;
            retour = xmltransformation(xml, xsl);
            fclose(xml);
            fclose(xsl);
            break;
        }
        default:
            cout << "Argument non reconnu : " << argv[1][1] << endl;
        }
    }
    if (!vRet)
    {
        cout << "Mauvais format d'entree" << endl;
    }

    if (!retour)
    {
        cout << "Entrée standard reconnue" << endl;
    }
    else
    {
        cout << "Entrée standard non reconnue" << endl;
    }
    return 0;
}
