calculatrice : y.tab.o lex.yy.o
	gcc -o calculatrice y.tab.o lex.yy.o -lm -lfl

arbre: noeud.o arbre.o
	gcc -o noeud.o arbre.o

y.tab.o : y.tab.h y.tab.c
	gcc -c y.tab.c

noeud.o:noeud.h noeud.c
	gcc -c noeud.c
	
arbre.o:arbre.c arbre.h noeud.h
	gcc -c arbre.c

y.tab.c y.tab.h : calculatrice.yacc.y
	yacc -d calculatrice.yacc.y

lex.yy.o : lex.yy.c y.tab.h
	gcc -c lex.yy.c

lex.yy.c : calculatrice.lex 
	flex calculatrice.lex

clean:
	rm -f y.tab.*
	rm -f lex.yy.*
	rm -f calculatrice calculatrice.exe
	rm -f *~
	rm -f *.stackdump
	rm -f *.o