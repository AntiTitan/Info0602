#ifndef ARBRE_H
#define ARBRE_H

#include "noeud.h"

typedef struct arbre {
	noeud_t* racine;
}arbre_t;

void initialiser_arbre(arbre_t*);
void detruire_arbre(arbre_t*);
noeud_t * min_arbre(noeud_t *);
void inserer_arbre(arbre_t*, int m);
noeud_t* search_arbre(arbre_t*, int m);
void supprimer_arbre(arbre_t*, int m);
void afficher_arbre(arbre_t);
int compter_arbre(arbre_t);

#endif