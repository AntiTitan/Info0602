%{
    /*declarations en c*/
#include <stdio.h>
#include <stdlib.h>

int sommet=0;
float tmp;
float pile [20];
%}
    /*definitions*/
CHIFFRE [0-9]
ENTIER {CHIFFRE}+
REEL {ENTIER}(\.{ENTIER}+)?

%%
    /*regles*/
{ENTIER}    {pile[sommet] = atoi(yytext); sommet++;}
{REEL}      {pile[sommet] = atoi(yytext); sommet++;}

"-"{ENTIER} {pile[sommet] = atoi(yytext); sommet++;}
"+"         {pile[sommet-2] += pile[sommet-1];
            sommet--;
            printf("resultat : %f\n",pile[sommet-1]);}
"-"         {pile[sommet-2] = pile[sommet-1] - pile[sommet-2];
            sommet--;
            printf("resultat : %f\n",pile[sommet-1]);}
"*"         {pile[sommet-2] *= pile[sommet-1];
            sommet--;
            printf("resultat : %f\n",pile[sommet-1]);}
"/"         {pile[sommet-2] = pile[sommet-1] / pile[sommet-2];
            sommet--;
            printf("resultat : %f\n",pile[sommet-1]);}

"="         {for(int i=0; i<20; i++) printf(" %f ",pile[i]); printf("\n");}
"CLEAR"     {for(int i=0; i<20; i++) pile[i]=0; sommet=0; printf("Pile vidée\n");}
"SWAP"      {
                tmp = pile[sommet-1];
                pile[sommet-1]=pile[sommet-2];
                pile[sommet -2]=tmp;
            }
            
.       ;
\n  ;

%%
    /*fonctions c*/

int main(int argc,char * argv []) {
    if ( argc > 1 )
        yyin = fopen( argv[1], "r" );
    else
        yyin = stdin;

    yylex(); 
  
    return EXIT_SUCCESS;
}

/*execution:
    flex calculatrice.lex
    gcc -o toto lex.yy.c -lfl
    ./toto
*/