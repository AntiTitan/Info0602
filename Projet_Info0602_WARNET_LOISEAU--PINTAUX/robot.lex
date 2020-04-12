%{
#include "y.tab.h"

int yylex();
void yyerror(const char *erreurMsg);
%}

%%

[0-9]+	 {
           yylval = atoi(yytext);
           return ENTIER;
         }
"proc"        { return DEBUTP; }
"finproc"     { return FINP; }
"main()"      { return MAIN; }
"tantque("    { return WHILE; }
"fintantque"  { return FINW; }
"si("         { return IF; }
"sinon"       { return ELSE; }
"finsi"       { return ENDI; }
"("           { return PAR; }
"avance()"    { return AV; }
"recule()"	  { return RE; }
"droite()"	  { return DR; }
"gauche()"	  { return GA; }
"pose()"	    { return PO; }
"prend()"	    { return PR; }
"case("       { return CA; }
")"           { return FIN; }
"="           { return EGAL; }
"!="          { return DIFF; }
"=="          { return TESTEG; }
"<"           { return INF; }
"<="          { return INFE; }
">"           { return SUP; }
">="          { return SUPE; }
[a-z]         { yylval = yytext; return VAR; }
[a-z]+        { yylval = yytext; return NOM; }
[ \t\n]	      ; 
.             yyerror("Caractère non valide");

%%

void yyerror(const char *erreurMsg) {
  fprintf(stderr, "\n Erreur '%s' sur '%s'.\n", erreurMsg, yytext);
  exit(EXIT_FAILURE);
}