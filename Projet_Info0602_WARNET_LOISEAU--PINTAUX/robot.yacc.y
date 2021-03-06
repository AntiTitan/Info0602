%{
#include "procedures.h"
#include "parsing.h"

void yyerror(const char *erreurMsg);
int nbTrou, haut, larg, act, stop;
int yylex();
extern FILE* yyin;
case_t** grille;
robot_t robot;

%}

%token ENTIER
%token VAR
%token NOM
%token DEBUTP
%token FINP
%token MAIN
%token WHILE
%token FINW
%token IF
%token ELSE
%token ENDI
%token PAR
%token AV
%token RE
%token DR
%token GA
%token PO
%token PR
%token CA
%token FIN
%token EGAL
%token DIFF
%token TESTEG
%token INF
%token INFE
%token SUP
%token SUPE

%start programme
%%

programme: main
      | proc programme
      ;

main: DEBUTP MAIN actions FINP {
        stop = 1;
        $$ = nbTrou;
      }
      ;

proc: DEBUTP NOM PAR parametres FIN instructions FINP
      ;

parametres: parametres ',' parametre
      | parametre
      |
      ;

parametre: VAR ':' NOM
      ;

instructions: instructions instruction
      | instruction
      ;

instruction: affectation
      | procedure
      | WHILE exp FIN instructions FINW
      | IF exp FIN instructions ENDI
      | IF exp FIN instructions ELSE instructions ENDI
      ;

affectation: VAR EGAL ENTIER { $1 = $3;}
      | VAR EGAL VAR '+' ENTIER { $1 = $3 + $5;}
      | VAR EGAL ENTIER '+' VAR { $1 = $3 + $5;}
      | VAR EGAL VAR '-' ENTIER { $1 = $3 + $5;}
      | VAR EGAL ENTIER '-' VAR { $1 = $3 + $5;}
      ;

exp:    VAR DIFF VAR    { return ($1 != $3);}
      | VAR DIFF ENTIER { return ($1 != $3);}
      | VAR TESTEG VAR  { return ($1 != $3);}
      | VAR TESTEG ENTIER { return ($1 != $3);}
      | VAR INF VAR     { return ($1 != $3);}
      | VAR INF ENTIER  { return ($1 != $3);}
      | VAR INFE VAR    { return ($1 != $3);}
      | VAR INFE ENTIER { return ($1 != $3);}
      | VAR SUP VAR     { return ($1 != $3);}
      | VAR SUP ENTIER  { return ($1 != $3);}
      | VAR SUPE VAR    { return ($1 != $3);}
      | VAR SUPE ENTIER { return ($1 != $3);}
      ;

actions: actions procedure
      | procedure
      ;

procedure: AV {
        act = avance(robot, grille);
        if (act == FAUX) stop = 1;
        printf("avance\n");
      }
      | RE {
        act = recule(robot, grille);
        if (act == FAUX) stop = 1;
      }
      | DR {
        droite(robot);
      }
      | GA {
        gauche(robot);
      }
      | PO {
        act = pose(robot, grille);
        if (act == FAUX) stop = 1;
        else if (act = BOUCHE) nbTrou--;
      }
      | PR {
        act = prend(robot, grille);
        if (act == FAUX) stop = 1;
      }
      | CA ENTIER FIN {
        $$ = $1;
        act = contenu($$, robot, grille);
        if (act == VIDE) printf("vide\n");
        else if (act == CAISSE) printf("caisse\n");
        else if (act == BLOC) printf("bloc\n");
        else if (act == BILLE) printf("bille\n");
        else if (act == TROU) printf("trou\n");
      }
      ;

%%

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: %s plateau algo\n", argv[0]);
    printf("\tplateau: fichier JSON contenant la description du plateau\n");
    printf("\talgo: fichier contenant l'algo du robot\n");
    return EXIT_FAILURE;
  }
  act = 5;

  /*initialisation de la grille et du robot*/
  nbTrou = parsing(argv[1], grille, robot, haut, larg);
  printf("initialisation de la grille et du robot OK \n");

  /*lecture du fichier pour les actions du robot*/
  yyin = fopen(argv[2], "r");

  yyparse();

  return EXIT_SUCCESS;
}