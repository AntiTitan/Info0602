%{
    /*declarations en c*/
#include <stdio.h>
#include <stdlib.h>

int cmpl=0,cmpnb=0,cmpm=0,cmpo=0;

%}
    /*definitions*/
CHIFFRE  [0-9]
NOMBRE   {CHIFFRE}+
LETTRE   [a-zA-Z]
MOT      {LETTRE}+

%%
    /*regles*/
{NOMBRE}        {cmpnb++;
                printf("nombre %d ", atoi(yytext));}
"NBL"           {printf("%d lignes\n",cmpl);}
{MOT}           {cmpm++;
                printf("mot-clef %s ", yytext);}
"+"|"-"|"*"|"/" {cmpo++;
                printf("operateur %s ", yytext);}

.               ;
\n              {cmpl++;};

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
    flex xxx.lex
    gcc -o toto lex.yy.c -lfl
    ./toto
*/