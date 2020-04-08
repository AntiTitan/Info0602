robot : y.tab.o lex.yy.o
	gcc -o robot y.tab.o lex.yy.o -lm -lfl

y.tab.o : y.tab.h y.tab.c
	gcc -c y.tab.c

y.tab.c y.tab.h : robot.yacc.y
	yacc -d robot.yacc.y

lex.yy.o : lex.yy.c y.tab.h
	gcc -c lex.yy.c

lex.yy.c : robot.lex 
	flex robot.lex

clean:
	rm -f y.tab.*
	rm -f lex.yy.*
	rm -f robot robot.exe
	rm -f *~
	rm -f *.stackdump