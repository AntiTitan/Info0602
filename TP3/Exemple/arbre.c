#include "arbre.h"
#include <stdlib.h>
#include <stdio.h>

int cpt;

void initialiser_arbre(arbre_t* a) {
	a->racine = NULL;
}

void inserer_arbre(arbre_t* a, int m) {
	noeud_t* z=(noeud_t*)malloc(sizeof(noeud_t));
	noeud_t* x = a->racine;
	noeud_t* y = NULL;
	initialiser_noeud(z, m);
	while(x!=NULL) {
		y=x;
		if(z->data < x->data) {
			x =x->gauche;
		}else{
			x = x->droite;
		}
	}
	z->pere=y;
	if(y==NULL) {
		a->racine =z;
	}else if(z->data < y->data) {
		y->gauche=z;
	}else{
		y->droite=z;
	}

}

noeud_t* search_arbre(arbre_t* 	a, int m) {
	noeud_t* x=a->racine;
	while(x!=NULL && (m != x->data)) {
		if(m < x->data) {
			x=x->gauche;
		}else{
			x=x->droite;
		}
	}
	return x;
}

void transplanter(arbre_t* a, noeud_t* u, noeud_t* v){
	if(u->pere==NULL){
		a->racine=v;
	}else if(u==u->pere->gauche) {
		u->pere->gauche=v;
	}else{
		u->pere->droite=v;
	}
	if(v!=NULL) {
		v->pere=u->pere;
	}
}

noeud_t * min_arbre(noeud_t * a){
	noeud_t * tmp = a;
	while(tmp->gauche !=NULL){
		tmp=tmp->gauche;
	}
	return tmp;
}


void supprimer_arbre(arbre_t* a, int m) {
	noeud_t* z = search_arbre(a, m);
	noeud_t* y;
	if(z->gauche==NULL){
		transplanter(a, z, z->droite);
	}else {
		if(z->droite==NULL) {
			transplanter(a, z, z->gauche);
		}else{
			y=min_arbre(z->droite);
			if(!cmpnoeuds(y->pere,z)){
				transplanter(a,y,y->droite);
				y->droite=z->droite;
				y->droite->pere=y;
			}
			transplanter(a,z,y);
			y->gauche=z->gauche;
			y->gauche->pere=y;
		}
	}
	
}

void parcours_infixe(noeud_t* x) {
	if(x!=NULL) {
		parcours_infixe(x->gauche);
		printf("%d\n", x->data);
		parcours_infixe(x->droite);
	}
}


void afficher_arbre(arbre_t a) {
	if(a.racine != NULL)
		parcours_infixe(a.racine);
	else
		printf("Arbre NULL\n");
}

void afficher_noeud(noeud_t * n) {
	if(n!=NULL)
		printf("%d\n", n->data);
	else
		printf("noeud NULL\n");
}

void detruire_arbre_rec(noeud_t* a) {
	if(a->gauche != NULL) detruire_arbre_rec(a->gauche);
	if(a->droite != NULL) detruire_arbre_rec(a->droite);
	detruire_noeud(a);
	// free(a);
	a=NULL;
}

void detruire_arbre(arbre_t* a) {
	detruire_arbre_rec(a->racine);
	a->racine=NULL;
}

int compter_arbre_noeud(noeud_t* x) {
	if(x!=NULL) {
		cpt+=1;
		compter_arbre_noeud(x->gauche);
		compter_arbre_noeud(x->droite);
	}
	return cpt;
}

int compter_arbre(arbre_t a) {
	cpt = 0;
	return compter_arbre_noeud(a.racine);
}

int main(){
	arbre_t a;
	initialiser_arbre(&a);
	printf("insertion 2 , 6 , 10, 1, 7, 15\n");
	inserer_arbre(&a,2);
	afficher_arbre(a);
	printf("\n");

	inserer_arbre(&a,6);
	afficher_arbre(a);
	printf("\n");
	
	inserer_arbre(&a,10);
	afficher_arbre(a);
	printf("\n");
	
	inserer_arbre(&a,1);
	afficher_arbre(a);
	printf("\n");
	
	inserer_arbre(&a,7);
	afficher_arbre(a);
	printf("\n");
	
	inserer_arbre(&a,15);
	printf("affichage\n");
	afficher_arbre(a);

	return 0;
}