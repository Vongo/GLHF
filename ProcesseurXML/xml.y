%{

#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;
#include "commun.h"
#include "model/Attribut.h"
#include "model/Element.h"
#include "model/Donnee.h"
#include "model/EnTete.h"
#include "model/Document.h"
#include "model/Doctype.h"
#include "model/Autre.h"
#include "model/ElementBalise.h"
#include "model/ElementBaliseOrpheline.h"

extern char xmltext[];

int xmllex(void);  

void xmlerror(const char * msg)
{
   fprintf(stderr,"%s\n",msg);
}

%}

%union {
   char * s;
   list<char *>* l;
   Attribut* a;
   list<Attribut *>* la;
   Element* e;
   list<Element*> **c;
   list<EnTete*> * en;
   Document* d;
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
%token <s> VALEUR DONNEES COMMENT NOM CDATAEND

%type <l> valeurs;
%type <a> att;
%type <la> atts;
%type <e> element
%type <c> content;
%type <d> document;
%type <en> entetes;
%%

document
 : entetes element 					            {$$ = new Document($1,$2);}
 | element 							                {$$ = new Document($1);};
 ;

entetes
 : entetes INFSPECIAL atts SUPSPECIAL 	{$$ = $1; $$->push_back(new Autre($3));}
 | entetes DOCTYPE NOM NOM valeurs SUP 	{$$ = $1; $$->push_back(new Doctype($3,$4,$5));}
 | /*vide*/							                {$$ = new list<EnTete*>();}
 ;

valeurs				
 : valeurs VALEUR 				            	{$$ = $1; $$->push_back($2);}
 | /*vide*/							                {$$ = new list<char* >();}
 ;

element
 : INF NOM atts SUP 
   content
   INF SLASH NOM SUP 				           {$$ = new ElementBalise($2, $5, $3);} //Balise Paire
 | INF NOM COLON NOM atts SUP 
   content
   INF SLASH NOM COLON NOM SUP         {$$ = new ElementBalise($4, $7, $5);} //Balise Paire XSL
 | INF NOM atts SLASH SUP              {$$ = new ElementBaliseOrpheline($2,$3);} //Balise Orpheline
 | INF NOM COLON NOM atts SLASH SUP 	 {$$ = new ElementBaliseOrpheline($4,$5);} //Balise Orpheline XSL
 ;

 atts
  : atts att 						               {$$ = $1; $$->push_back($2);}
  | /*vide*/						               {$$ = new list<Attribut*>();}
  ;

 att
  : NOM EGAL VALEUR 				           {$$ = new Attribut($1,$3);}
  | NOM COLON NOM EGAL VALEUR               {$$ = new Attribut($3,$5);}
  ;

content
 : content element                {$$ = $1;$$[1]->push_back($2);}
 | content CDATABEGIN CDATAEND 		{$$ = $1;$$[0]->push_back(new Donnee($3,1));}
 | content DONNEES 					{$$ = $1; $$[0]->push_back(new Donnee($2,0));}         
 | /* vide */       				{list<Element*>* donnees = new list<Element*>(); list<Element*>* elements = new list<Element*>(); $$ = new list<Element*>*[2];$$[0]=donnees;$$[1]= elements;  } 
 ;