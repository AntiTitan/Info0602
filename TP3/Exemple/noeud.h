#ifndef NOEUD_H
#define NOEUD_H

typedef struct{
	
}valeur_t;

typedef struct{
	
}variable_t;

typedef struct{
	
}fonction_t;

typedef struct noeud {
	struct noeud *pere;
	struct noeud *droite;
	struct noeud *gauche;
	union {
		int val;
		int var;
		fonction_t f;
	} data;
}noeud_t;

void initialiser_noeud(noeud_t*, int);
void detruire_noeud(noeud_t*);
int cmpnoeuds(noeud_t*, noeud_t*);

#endif