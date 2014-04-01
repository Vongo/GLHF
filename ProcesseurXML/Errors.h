#include <string.h>
using namespace std;

static const char *MANUAL = "Available commands are:\n ../xmltool -p file.xml : parse and display the xml file\n ../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result\n ../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl\n ../xmltool -h : displays this help\n";
static const char *NO_ARGUMENT_GIVEN = "No argument given\nAvailable commands are:\n ../xmltool -p file.xml : parse and display the xml file\n ../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result\n ../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl\n ../xmltool -h : displays this help\n";
static const char *UNKNOWN_ARGUMENT = "TODO unknown argument\n";
static const char *TOO_MANY_ARGUMENTS = "TODO Too many arguments\n";
static const char *UNPROVIDED_ARGUMENT_P = "You must provide an argument to the command -p\n";
static const char *UNPROVIDED_ARGUMENT_T = "You must provide two arguments to the command -t: an xml file and an xsl file\n";
static const char *UNPROVIDED_ARGUMENT_V = "You must provide two arguments to the command -v: an xml file and an xsd file\n";
static const char *BAD_MARKUP_1 = "Non matching element names title and titre\n";
static const char *BAD_MARKUP_2 = "Non matching element namespaces ns and badns\n";
static const char *BAD_MARKUP_3 = "Non matching element names catalog and catalogue\n";
static const char *BAD_MARKUP_4 = "Non matching element namespaces ns and badns\nNon matching element names catalog and catalogue\n";
static const char *CANNOT_OPEN_XML = "Unable to open does_not_exist.xml\n";
static const char *LEXICAL_ERROR = "Lexical Error (character ?)\nLexical Error (character !)\nsyntax error\nNo root markup\n";
static const char *MISSING_MARKUP = "Non matching element names artist and cd\nNon matching element names cd and catalog\nsyntax error\nNo root markup\n";
static const char *SYNTAX_ERROR = "Parsage d'un fichier correct au niveau lexical mais dont la syntaxe n'est pas bonne.l\n";
static const char *CANNOT_OPEN_XSL = "Unable to open file does_not_exist.xsl\n";
static const char *CANNOT_OPEN_XSD = "Unable to open file does_not_exist.xsd\n";



int checkEntryFormat(int argc, char const *argv[])
{
    //Check input format
    int vRet = 1;
    if (argc == 1)
    {
        fputs(NO_ARGUMENT_GIVEN, stderr);
    }
    else if (argc > 4)
    {
        fputs(TOO_MANY_ARGUMENTS, stderr);
    }
    else if (argc > 1)
    {
        if (strlen(argv[1]) > 1 && argv[1][0] == '-')
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
                if (argc != 3)
                {
                    if (argc > 3)
                        fputs(TOO_MANY_ARGUMENTS, stderr);
                    else
                        fputs(UNPROVIDED_ARGUMENT_P, stderr);
                }
                else
                {
                    FILE *fid = fopen(argv[2], "r");
                    if (!fid)
                        fputs(CANNOT_OPEN_XML, stderr);
                    fclose(fid);
                }
                break;
            }
            case 'v':
            {
                if (argc != 4)
                {

                }
                else
                {

                }
                break;
            }
            case 't':
            {
                if (argc != 4)
                {
                    fputs(UNPROVIDED_ARGUMENT_T, stderr);
                }
                else
                {
                    FILE *xml = fopen(argv[2], "r");
                    FILE *xsl = fopen(argv[3], "r");
                    if (!xml)
                        fputs(CANNOT_OPEN_XML, stderr);
                    if (!xsl)
                        fputs(CANNOT_OPEN_XSL, stderr);
                    fclose(xml);
                    fclose(xsl);
                }
                break;
            }
            default:
                fputs (UNKNOWN_ARGUMENT, stderr);
            }
        }
    }
    return vRet;
}