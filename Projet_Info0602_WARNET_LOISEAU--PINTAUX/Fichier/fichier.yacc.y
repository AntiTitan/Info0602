%{
/*includes*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int yylex();
extern FILE* yyin;
%}

%token FLOAT
%token INT
%token STRING

%%

programme: expression programme
      |
      ;

expression:  FLOAT {
        $$ = $1;
        printf("Found a floating-point number: %f\n", $$);
      }
      | INT {
        $$ = $1;
        printf("Found an integer: %d\n", $$);
      }
      | STRING {
        $$ = $1;
        printf("Found a string: %s\n", $$);
      };

%%

int main(int argc, char* argv[]) {

  if (argc !=2) {
    printf("1 argument attendu: nomFichier\n");
    return EXIT_FAILURE;
  }
  
  yyin = fopen(argv[1], "r");

  yyparse();
  return EXIT_SUCCESS;
}