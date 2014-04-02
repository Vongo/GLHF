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
        //*/

    Document *doc =NULL;
    extern FILE *xmlin;
    int vRet = checkEntryFormat(argc, argv);
    if (vRet == 1)
        return vRet;
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
            FILE *xml = fopen(argv[2], "r");
            FILE *xsd = fopen(argv[3], "r");
            vRet = xmlvalidation(xml, xsd);
            fclose(xml);
            fclose(xsd);
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
