%{
#include "procedures.h"

int yylex();
void yyerror(const char *erreurMsg);
case_t** grille;
robot_t robot;
%}

%token ENTIER
%token DEBUTP
%token FINP
%token AV
%token RE
%token DR
%token GA
%token PO
%token PR
%token CA
%token FIN
%token PUIS

%%

programme: DEBUTP expression FINP {}
      |
      ;

expression:  AV {
        avance(robot, grille);
      }
      | RE {
        recule(robot, grille);
      }
      | DR {
        droite(robot);
      }
      | GA {
        gauche(robot);
      }
      | PO {
        pose(robot, grille);
      }
      | PR {
        prend(robot, grille);
      }
      | CA ENTIER FIN {
        /*a voir, pas sure*/
        contenu($1, robot, grille);
      }
      | expression PUIS expression {
      };

%%

int main(void) {
  yyparse();
  return EXIT_SUCCESS;
}