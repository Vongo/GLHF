
static const char *MANUAL = "Available commands are:\n ../xmltool -p file.xml : parse and display the xml file\n ../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result\n ../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl\n ../xmltool -h : displays this help\n";
static const char *NO_ARGUMENT_GIVEN = "No argument given\nAvailable commands are:\n ../xmltool -p file.xml : parse and display the xml file\n ../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result\n ../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl\n ../xmltool -h : displays this help\n";
static const char *UNKNOWN_ARGUMENT = "TODO unknown argument\n";
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