fichier : y.tab.o lex.yy.o
	gcc -o fichier y.tab.o lex.yy.o -lm -lfl

y.tab.o : y.tab.h y.tab.c
	gcc -c y.tab.c

y.tab.c y.tab.h : fichier.yacc.y
	yacc -d fichier.yacc.y

lex.yy.o : lex.yy.c y.tab.h
	gcc -c lex.yy.c

lex.yy.c : fichier.lex 
	flex fichier.lex

clean:
	rm -f y.tab.*
	rm -f lex.yy.*
	rm -f fichier fichier.exe
	rm -f *~
	rm -f *.stackdump