Template {

	List<Template> children;
	Template parent;
	ElementBalise content;
	String match;
	String output;
	
	public Template() {

	}

	public Template(String m, ElementBalise c) {
		match = m;
		content = c;
	}

	void addChild(Template t) {
		children.add(t);
	}

	void setParent(Template t) {
		parent = t;
	}

	void addToOutput(String o) {
		output += o;
	}

	String getOutput() {
		return output;
	}

	String getMatch(){
		return match;
	}

	ElementBalise getContent() {
		return content;
	}

	Template getParent() {
		return parent;
	}

	Template getChild(String match) {

	}

	List<Template> getChildren() {
		return children;
	}
}