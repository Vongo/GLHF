typedef enum TypeBalise {OUVRANTE, FERMANTE, ORPHELINE} TypeBalise;

class Balise
{
public:
    Balise(char *);
    ~Balise();
private:
    TypeBalise typeBalise;
    //Nom nomBalise;
    //Attribut attributs;
};
