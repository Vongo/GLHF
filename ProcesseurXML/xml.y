%{
#define YYDEBUG 1
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

void xmlerror(Document **d, const char * msg)
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
   list<Element*> *c;
   list<EnTete*> * en;
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
%token <s> VALEUR DONNEES COMMENT NOM CDATAEND

%type <l> valeurs;
%type <a> att;
%type <la> atts;
%type <e> element;
%type <c> content;
%type <en> entetes;

%parse-param {Document **d} //Le retour du parseur

%%

document
 : entetes element 					            {*d = new Document($1,$2);}
 | element 							                {*d = new Document($1);};
 ;

entetes
 : entetes INFSPECIAL NOM atts SUPSPECIAL 	{$$ = $1; $$->push_back(new Autre($3,$4));}
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
   INF SLASH NOM SUP 				           { if(strcmp($2,$8)!= 0)
                                          {
                                            char str[100];
                                            strcpy(str,"Non matching element names ");
                                            strcat(str,$2);
                                            strcat(str," and ");
                                            strcat(str,$8);
                                            strcat(str,"\n");
                                            fputs(str,stderr);
                                          }
                                          $$ = new ElementBalise($2, $5, $3, "xml");
                                        } //Balise Paire ok avec test si nom différent

 | INF NOM COLON NOM atts SUP 
   content
   INF SLASH NOM COLON NOM SUP         { 
                                          if(strcmp($2,$10)!= 0)
                                          {
                                            char str[100];
                                            strcpy(str,"Non matching element namespaces ");
                                            strcat(str,$2);
                                            strcat(str," and ");
                                            strcat(str,$10);
                                            strcat(str,"\n");
                                            fputs(str,stderr);
                                          }
                                          if(strcmp($4,$12)!= 0)
                                          {
                                            char str[100];
                                            strcpy(str,"Non matching element names ");
                                            strcat(str,$4);
                                            strcat(str," and ");
                                            strcat(str,$12);
                                            strcat(str,"\n");
                                            fputs(str,stderr);
                                          }
                                          {$$ = new ElementBalise($4, $7, $5, $2);} //Balise Paire XSL ou XSD
                                        }
 | INF NOM atts SLASH SUP              {$$ = new ElementBaliseOrpheline($2,$3, "xml");} //Balise Orpheline
 | INF NOM COLON NOM atts SLASH SUP 	 {$$ = new ElementBaliseOrpheline($4,$5,$2);} //Balise Orpheline XSL ou XSD
 ;

 atts
  : atts att 						               {$$->push_back($2);}
  | /*vide*/						               {$$ = new list<Attribut*>();}
  ;

 att
  : NOM EGAL VALEUR 				           {$$ = new Attribut($1,$3);}
  | NOM COLON NOM EGAL VALEUR               {$$ = new Attribut($3,$5);}
  ;

content
 : content element                {$$ = $1;$$->push_back($2);}
 | content CDATABEGIN CDATAEND 		{$$ = $1;$$->push_back(new Donnee($3,1));}
 | content DONNEES          {$$ = $1; $$->push_back(new Donnee($2,0));}
 | content COMMENT 					{$$ = $1; $$->push_back(new Donnee($2,2));}
 | /* vide */       				{$$ = new list<Element*>;}
 ;