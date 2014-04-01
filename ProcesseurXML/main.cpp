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
    Document **doc;
    extern FILE *xmlin;
    int vRet = checkEntryFormat(argc, argv);
    if (vRet == 1)
        return vRet;
    cout << "On est toujours là"<<endl;
    if (argc == 3)
    {
        if (argv[0][1] == 'p') // Redundant
        {
            FILE *fid = fopen(argv[2], "r");
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
