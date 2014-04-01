#include "commun.h"
#include "Errors.h"
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
    int retour = 1;

    //Check input format
    if (argc == 1)
        fputs(NO_ARGUMENT_GIVEN, stderr);
    else if (argc > 4)
        fputs(TOO_MANY_ARGUMENTS, stderr);
    else if (argc > 1)
    {
        else if (strlen(argv[1]) > 1 && argv[1][0] == '-')
        {
            switch (argv[1][1])
            {
            case 'h':
            {
                fputs (MANUAL, stderr);
                break;
            }
            case 'p':
            {
                break;
            }
            case 'v':
            {
                break;
            }
            case 't':
            {
                break;
            }
            default:
                fputs (UNKNOWN_ARGUMENT, stderr);
            }
        }
    }

    Document **doc;
    extern FILE *xmlin;
    else if (argc == 3)
    {
        switch (argv[1][1])
        {
        case 'p':
        {
            //cout << ">> PARSING <<" << endl;
            FILE *fid = fopen(argv[2], "r");
            if (!fid)
            {
                //cout << "ACHTUNG OMFGWTF" << endl;
                return 1;
            }
            xmlin = fid;
            retour = xmlparse(doc);
            fclose(fid);
            break;
        }
        default:
            break;
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
            //cout << ">> VALIDATION <<" << endl;
            retour = xmlvalidation(xml, xsd);
            fclose(xml);
            fclose(xsd);
            break;
        }
        case 't':
        {
            FILE *xml = fopen(argv[2], "r");
            FILE *xsl = fopen(argv[3], "r");
            //cout << ">> TRANSFORMATION <<" << endl;
            retour = xmltransformation(xml, xsl);
            fclose(xml);
            fclose(xsl);
            break;
        }
        default:
            //cout << "Argument non reconnu : " << argv[1][1] << endl;
            break;
        }
    }
    else
    {
        //cout << "Mauvais format d'entree" << endl;
    }

    if (!retour)
    {
        //cout << "Entrée standard reconnue" << endl;
    }
    else
    {
        //cout << "Entrée standard non reconnue" << endl;
    }
    return retour;
}
