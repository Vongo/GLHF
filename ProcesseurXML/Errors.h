#include <string.h>
#include <iostream>
using namespace std;

static const char *MANUAL = "Available commands are:\n ../xmltool -p file.xml : parse and display the xml file\n ../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result\n ../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl\n ../xmltool -h : displays this help\n";
static const char *NO_ARGUMENT_GIVEN = "No argument given\nAvailable commands are:\n ../xmltool -p file.xml : parse and display the xml file\n ../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result\n ../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl\n ../xmltool -h : displays this help\n";
static const char *UNKNOWN_ARGUMENT = "Unknown argument\n";
static const char *TOO_MANY_ARGUMENTS = "Too many arguments\n";
static const char *UNPROVIDED_ARGUMENT_P = "You must provide an argument to the command -p\n";
static const char *UNPROVIDED_ARGUMENT_T = "You must provide two arguments to the command -t: an xml file and an xsl file\n";
static const char *UNPROVIDED_ARGUMENT_V = "You must provide two arguments to the command -v: an xml file and an xsd file\n";
static const char *CANNOT_OPEN_XML1 = "Unable to open ";
static const char *CANNOT_OPEN_XML2 = "Unable to open file ";
static const char *CANNOT_OPEN_XSL = "Unable to open file ";
static const char *CANNOT_OPEN_XSD = "Unable to open file ";
static const char *NO_ROOT_ELEMENT = "No root markup\n";

char *setComposedMessage(const char *err, const char *file)
{
    char *vRet = new char[strlen(err) + strlen(file)];
    strcpy(vRet, "");
    strcat(vRet, err);
    strcat(vRet, file);
    strcat(vRet, "\n");
    return vRet;
}

int checkEntryFormat(int argc, char const *argv[])
{
    //Check input format
    int vRet = 0; // 0 is "No error found"
    if (argc == 1)
    {
        fputs(NO_ARGUMENT_GIVEN, stderr);
        vRet = 1;
    }
    else if (argc > 4)
    {
        fputs(TOO_MANY_ARGUMENTS, stderr);
        vRet = 1;
    }
    else if (argc > 1)
    {
        char *composedMessage = new char[80];
        composedMessage = "";
        if (strlen(argv[1]) > 1 && argv[1][0] == '-')
        {
            switch (argv[1][1])
            {
            case 'h':
            {
                fputs (MANUAL, stderr);
                vRet = 1;
                break;
            }
            case 'p':
            {
                if (argc != 3)
                {
                    if (argc > 3)
                    {
                        fputs(TOO_MANY_ARGUMENTS, stderr);
                        vRet = 1;
                    }
                    else
                    {
                        fputs(UNPROVIDED_ARGUMENT_P, stderr);
                        vRet = 1;
                    }
                }
                else
                {
                    FILE *fid = fopen(argv[2], "r");
                    if (!fid)
                    {
                        fputs(setComposedMessage(CANNOT_OPEN_XML1, argv[2]), stderr);
                        vRet = 1;
                    }
                    else
                        fclose(fid);
                }
                break;
            }
            case 'v':
            {
                if (argc < 4)
                {
                    fputs(UNPROVIDED_ARGUMENT_V, stderr);
                    vRet = 1;
                }
                else
                {
                    FILE *xml = fopen(argv[2], "r");
                    FILE *xsd = fopen(argv[3], "r");
                    if (!xml)
                    {
                        fputs(setComposedMessage(CANNOT_OPEN_XML2, argv[2]), stderr);
                        vRet = 1;
                    }
                    else if (!xsd)
                    {
                        fputs(setComposedMessage(CANNOT_OPEN_XSD, argv[3]), stderr);
                        vRet = 1;
                    }
                    if (xsd)
                        fclose(xsd);
                    if (xml)
                        fclose(xml);
                }
                break;
            }
            case 't':
            {
                if (argc != 4)
                {
                    fputs(UNPROVIDED_ARGUMENT_T, stderr);
                    vRet = 1;
                }
                else
                {
                    FILE *xml = fopen(argv[2], "r");
                    FILE *xsl = fopen(argv[3], "r");
                    if (!xml)
                    {
                        fputs(setComposedMessage(CANNOT_OPEN_XML2, argv[2]), stderr);
                        vRet = 1;
                    }
                    else if (!xsl)
                    {
                        fputs(setComposedMessage(CANNOT_OPEN_XSL, argv[3]), stderr);
                        vRet = 1;
                    }
                    if (xsl)
                        fclose(xsl);
                    if (xml)
                        fclose(xml);
                }
                break;
            }
            default:
                fputs (UNKNOWN_ARGUMENT, stderr);
                vRet = 1;
            }
        }
    }
    return vRet;
}