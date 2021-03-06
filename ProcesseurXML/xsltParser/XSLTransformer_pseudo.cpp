XSLTransformer {
	
	XMLRep xml;
	XMLRep catalog;
	List<Template> tree;
	
	public XSLTransformer() {

	}

	public XSLTransformer(XML xmlRep, XMLRep cat) {
		xml = xmlRep;
		catalog = cat;
	}

	void createTemplateTree() {
		Balise root = xml.getRoot(); // <xsl:stylesheet>
		if (root = "xsl:stylesheet") {
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

	Template addContent(Template t) {
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
	}s
}