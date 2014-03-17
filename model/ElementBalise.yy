typedef enum Balise {Ouvrante, Fermante, Orpheline} Balise;

class Element
{
public:
    Element(arguments);
    ~Element();

    /* data */
};

class ElementBalise: public Element
{
public:
    ElementBalise(arguments);
    ~ElementBalise();

    /* data */
private:

};

class Attribut
{
public:
    Attribut(arguments);
    ~Attribut();

    /* data */
private:
    char *value;
    char *name;
};