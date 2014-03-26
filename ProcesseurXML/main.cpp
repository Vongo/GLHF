#include "commun.h"
#include "model/Document.h"
#include <iostream>
#include <cstring>

using namespace std;

int xmlparse(Document **);

int main(int argc, char const *argv[])
{
    Document **doc;
    extern FILE *xmlin;
    int retour = 1;
    if (argc == 2 && argv[0] == "-p")
    {
        FILE *fid = fopen(argv[1], "r");
        if (!fid)
        {
            cout << "ACHTUNG OMFGWTF" << endl;
            return 1;
        }
        xmlin = fid;
        retour = xmlparse(doc);
        fclose(fid);
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
