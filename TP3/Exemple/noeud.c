#include "noeud.h"
#include <string.h>
#include <stdlib.h>

void initialiser_noeud(noeud_t* a, int m) {
	a->pere=NULL;
	a->droite=NULL;
	a->gauche=NULL;
    a->data=m;
}

void detruire_noeud(noeud_t* a) {
	free(a->pere);
	a->pere=NULL;
	free(a->droite);
	a->droite=NULL;
	free(a->gauche);
	a->gauche=NULL;
}

int cmpnoeuds(noeud_t* a, noeud_t* b){
	return(a->data == b->data);
}