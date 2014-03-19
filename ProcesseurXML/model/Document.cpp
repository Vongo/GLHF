#include "Document.h"
#include "Balise.h"
#include <iostream>
#include <fstream>
using namespace std;

Document::Document(string path)
{
    bool estOrpheline;
    string line;
    ifstream myfile;
    myfile.open (path);

    //elementRacine = premiere balise non orpheline
    estOrpheline = true;
    if (myfile.is_open())
    {
        while ( estOrpheline )
        {
            getline (myfile, line);

            //Test ligne vide
            if (!line.empty())
            {
                //Test balise non orpheline
                if ((line.at(0) == '<') && (line.at(line.length - 1) != '/')))
                {
                    estOrpheline = false;
                    //On passe le contenu = tout jusqu'a la balise fermante
                    string contenu = line;

                    while (getline (myfile, newline))
                    {
                        contenu += newLine;
                    }

                    elementRacine = new Balise(contenu);
                }
            }

        }
        myfile.close();
    }

    else cout << "Unable to open file";
}