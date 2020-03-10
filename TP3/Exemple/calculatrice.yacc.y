%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *erreurMsg);
%}

%token ENTIER
%left '+' '-'
%left '*' '/'

%%

programme: expression '.' {
           printf("=%d\n", $1);
      }programme
      |
      ;

expression: ENTIER

      | expression '+' expression {
        $$ = $1 + $3;
      }
      | expression '-' expression {
        $$ = $1 - $3;
      }
      | expression '*' expression {
        $$ = $1 * $3;
      }
      | expression '/' expression {
        if($3 ==0){$3=1;}
        $$ = $1 / $3;
      }
      | '-' expression {
        $$ = -$2;
      };

%%

int main(void) {
  yyparse();
  return EXIT_SUCCESS;
}

/*Q4:on ajoute les reel.*/
/*    | expression '+' expression '*' expression {
        $$ = $3 * $5 + $1;
      }
      | expression '*' expression '+' expression {
        $$ = $1 * $3 + $5;
      }*/