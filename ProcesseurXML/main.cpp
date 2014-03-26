#include "commun.h"
#include "model/Document.h"
#include <iostream>
#include <cstring>

using namespace std;

int xmlparse(Document **);
int xmltransformation(const char *, const char *);
int xmlvalidation(const char *, const char *);

// TEMP //

int xmltransformation(const char *, const char *)
{
    return 1;
}
int xmlvalidation(const char *, const char *)
{
    return 1;
}

// END TEMP //

int main(int argc, char const *argv[])
{
    Document **doc;
    extern FILE *xmlin;
    int retour = 0;
    if (argc == 2)
    {
        switch (argv[1][1])
        {
        case 'h':
            cout << "CECI EST LE MANUEL OLOL" << endl;
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
            retour = xmlparse(doc);
            fclose(fid);
        }
    }
    else if (argc == 4)
    {
        switch (argv[1][1])
        {
        case 'v':
            cout << ">> VALIDATION <<" << endl;
            retour = xmlvalidation(argv[2], argv[3]);
            break;
        case 't':
            cout << ">> TRANSFORMATION <<" << endl;
            retour = xmltransformation(argv[2], argv[3]);
            break;
        default:
            cout << "Argument non reconnu : " << argv[1][1] << endl;
        }
    }
    else
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
