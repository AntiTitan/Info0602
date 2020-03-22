CC = gcc
OBJ = stringcell.o stringlist.o prog_txt.o file_functions.o table_hachage.o arbre.o noeud.o

all : prog_txt

prog_txt:$(OBJ)
	$(CC) -o prog_txt $(OBJ) -lm

prog_txt.o:prog_txt.c stringlist.h file_functions.h table_hachage.h
	$(CC) -c prog_txt.c

file_functions.o:file_functions.h file_functions.c stringlist.h
	$(CC) -c file_functions.c -lm

table_hachage.o:table_hachage.h table_hachage.c stringlist.h
	$(CC) -c table_hachage.c -lm

stringlist.o:stringlist.c stringlist.h stringcell.h
	$(CC) -c stringlist.c

arbre.o:arbre.c arbre.h noeud.h
	$(CC) -c arbre.c

stringcell.o:stringcell.h stringcell.c
	$(CC) -c stringcell.c

noeud.o:noeud.h noeud.c
	$(CC) -c noeud.c

clean:
	rm $(OBJ)