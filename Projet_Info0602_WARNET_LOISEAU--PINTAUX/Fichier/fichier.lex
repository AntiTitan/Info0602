%{
#include "y.tab.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int yylex();
void yyerror(const char *erreurMsg);
%}

%%

[ \t\n]          ;
[0-9]+\.[0-9]+   { yylval = atof(yytext); return FLOAT; }
[0-9]+           { yylval = atoi(yytext); return INT; }
[a-zA-Z0-9]+     { yylval = yytext; return STRING; }
.                ;

%%

void yyerror(const char *erreurMsg) {
  fprintf(stderr, "\n Erreur '%s' sur '%s'.\n", erreurMsg, yytext);
  exit(EXIT_FAILURE);
}