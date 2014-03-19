%{

#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
#include "commun.h"
#include "model/Attribut.h"

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
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
%token <s> VALEUR DONNEES COMMENT NOM CDATAEND

%type <l> valeurs;
%type <a> att;
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
   INF SLASH NOM SUP               
 ;

 atts
  : atts att
  | /*vide*/
  ;

 att
  : NOM EGAL VALEUR {$$ = new Attribut();}
  ;

content
 : content element
 | CDATABEGIN CDATAEND
 | COMMENT
 | DONNEES          
 | /* vide */              
 ;