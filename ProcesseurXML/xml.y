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
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
%token <s> VALEUR DONNEES COMMENT NOM CDATAEND

%type <l> valeurs;
%type <a> att;
%type <la> atts;
%type <e> element;
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
   INF SLASH NOM SUP {$$ = new Element($2, $5, $3);}	               
 ;

 atts
  : atts att 		{$$ = $1; $$->push_back($2);}
  | /*vide*/		{$$ = new list<Attribut*>();}
  ;

 att
  : NOM EGAL VALEUR {$$ = new Attribut($1,$3);} //refaire
  ;

content
 : content element
 | CDATABEGIN CDATAEND
 | COMMENT
 | DONNEES          
 | /* vide */              
 ;