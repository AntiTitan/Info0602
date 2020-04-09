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
"proc main()" { return DEBUTP; }
"finproc"     { return FINP; }
"avance()"    { return AV; }
"recule()"	  { return RE; }
"droite()"	  { return DR; }
"gauche()"	  { return GA; }
"pose()"	    { return PO; }
"prend()"	    { return PR; }
"case("       { return CA; }
")"           { return FIN; }
\n            { return PUIS; }
[ \t]	 ; 
.        yyerror("Caractère non valide");

%%

void yyerror(const char *erreurMsg) {
  fprintf(stderr, "\n Erreur '%s' sur '%s'.\n", erreurMsg, yytext);
  exit(EXIT_FAILURE);
}
