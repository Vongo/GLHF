#include "Balise.h"


int main(int argc, char const *argv[])
{
    Balise balise = new Balise("<doc name=\"mon document\">
                               <h1>Le titre</h1>
                               <p>Un paragraphe avec <i>du texte en italique</i> et
                               du <b>texte en gras</b>.</p>
                               <h1>Un autre titre</h1>
                               <ul>
                               <li>Un</li>
                               <li>Deux</li>
                               <li>Trois</li>
                               </ul>
                               </doc>");
    

    return 0;
}