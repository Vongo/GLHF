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
    int vRet = checkEntryFormat(argc, argv);

    if (!vRet)
        return vRet;

    Document **doc;
    extern FILE *xmlin;
    if (argc == 3)
    {
        switch (argv[1][1])
        {
        case 'p':
        {
            FILE *fid = fopen(argv[2], "r");
            if (!fid)
            {
                return 1;
            }
            xmlin = fid;
            vRet = xmlparse(doc);
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

    }
    return vRet;
}
