%{
#include "proceduresS.h"

int yylex();
void yyerror(const char *erreurMsg);
case_t** grille;
robot_t robot;
%}

%token ENTIER
%left '+' '-'
%left '*' '/'

%%

programme: 'proc main()' expression 'finproc' {
           printf("=%d\n", $1);
      }
      |
      ;

expression: ENTIER

      | 'avance()' {
        avance(robot, grille);
      }
      | 'recule()' {
        recule(robot, grille);
      }
      | 'droite()' {
        droite(robot);
      }
      | 'gauche()' {
        gauche(robot);
      }
      | 'pose()' {
        pose(robot);
      }
      | 'prend()' {
        prend(robot);
      }
      | 'case('ENTIER')' {
        contenu;/*mauvais*/
      };

%%

int main(void) {
  yyparse();
  return EXIT_SUCCESS;
}