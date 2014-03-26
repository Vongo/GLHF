#include "Template.h"
#include "Document.h"
#include <list>
#include <iostream>

using namespace std;


	XSLTransformer::XSLTransformer() {
		cout << "lolilol"<< endline;
	}

	XSLTransformer::XSLTransformer(Document xmlRep, Document cat) {
		xml = xmlRep;
		catalog = cat;

		createTemplateTree();

		for (list<Template>::iterator it=tree.begin(),it != tree.end() , it++){
			addContent(*it)
		}
	}

	void XSLTransformer::createTemplateTree() {
		Element* root = xml.getRacine(); // <xsl:stylesheet>
		if (root-> = "xsl:stylesheet") {
			// List<Template> tempList = new List<Template>();
			foreach(Element e : root.getChildren()) {
				Template t = new Template(e.getValueOfAttribute("match"));
				tree.add(t);
			}

			// iterate over tree for first time to set all parents and child
			// Templates where an apply-templates match is specified
			foreach(Template t : tree) {
				addContent(t)
			}

			// iterate a second time over tree to add all Templates where no // parent is specified as children to the one without an apply-
			// templates match
			Template root = tree.getFirst();
			foreach(Template t : tree) {
				if (t != root && t.getParent() = null) {
					root.addChild(t);
				}
			}
		}
	}

	void XSLTransformer::addContent(Template t) {
		foreach(Element child : t.getContent().getChildren) {
			if (child instanceOf Donnee) { // treat text nodes like "Title :"
				t.addToOutput(child);
			} else if (child instanceOf ElementBalise) {
				// récupérer le nom et tester le nom
				String name = child.getName();
				if (name.equals("xsl:apply-templates" && child.getAttributes !empty)) {
					Template filsT = tree.get(child.getAttribute("match"));
					t.addChild(filsT);
					filsT.setParent(t);
				} else if (name.equals("xsl:value-of")) {


				} else if (name.equals("xsl:for-each")) {

				}
			}
		}
	}
}