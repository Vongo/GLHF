%{

#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
#include "commun.h"
#include "model/Attribut.h"
#include "model/Element.h"
#include "model/Donnee.h"

extern char xmltext[];

int xmllex(void);  

void xmlerror(const char * msg)
{
   fprintf(stderr,"%s\n",msg);
}

%}

%union {
   char * s;
   list<char *> * l;
   Attribut* a;
   list<Attribut *> * la;
   Element* e;
   list<Element>* c [2];
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
%token <s> VALEUR DONNEES COMMENT NOM CDATAEND

%type <l> valeurs;
%type <a> att;
%type <la> atts;
%type <e> element
%type <c> content;
%%

document
 : entetes element 
 | element
 | /*vide*/
 ;

entetes
 : entetes
 | INFSPECIAL atts SUPSPECIAL
 | DOCTYPE NOM NOM valeurs SUP
 | /*vide*/
 ;

valeurs				
 : valeurs VALEUR 	{$$ = $1; $$->push_back($2);}
 | /*vide*/			{$$ = new list<char* >();}
 ;

element
 : INF NOM atts SUP 
   content
   INF SLASH NOM SUP {$$ = new ElementBalise($2, $5, $3);} //Balise Paire
 | INF NOM atts SLASH SUP {$$ = new ElementBaliseOrpheline($2,$3);} //Balise Orpheline
 ;

 atts
  : atts att 		{$$ = $1; $$->push_back($2);}
  | /*vide*/		{$$ = new list<Attribut*>();}
  ;

 att
  : NOM EGAL VALEUR {$$ = new Attribut($1,$3);} //refaire
  ;

content
 : content element 			{$$ = $1; $$[1]->push_back($2);}
 | content CDATABEGIN CDATAEND {$$ = $1; $$[0]->push_back(new Donnee(strcat($2,$3),1));}
 | content COMMENT			{$$ = $1; $$[0]->push_back(Donnee($2,2));}
 | content DONNEES 			{$$ = $1; $$[0]->push_back(new Donnee($2,0));}         
 | /* vide */       {list<Donnee*>* donnees = new list<Donnee*>(); list<Element*>* elements = new list<Element*>(); $$ = {donnees, elements};  } 
 ;