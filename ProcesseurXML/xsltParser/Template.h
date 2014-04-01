#include <ElementBalise>
#include <string>
#include <list>
#include <Template>

using namespace std;

class Template {

	list<Template> children;
	Template parent;
	string output;
	ElementBalise content;
	string match;
	
	public:
		Template(string, ElementBalise);
		Template();
		void addChild(Template);
		void setParent(Template);
		void addToOutput(string);
		string getOutput();
		string getMatch();
		ElementBalise getContent();
		Template getParent();
		Template getChild(string);
		list<Template> getChildren();
}