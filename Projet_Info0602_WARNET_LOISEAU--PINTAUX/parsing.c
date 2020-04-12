#include "parsing.h"

int parsing(char* nomFichier, case_t** grille, robot_t robot, int h, int l) {
    int fd, exists, nbTrou;
    int k, j, xx, yy;
    char buffer[MAX_SIZE];
    const char* dir;
    const char* t;

    struct json_object *parsed_json;
    struct json_object *largeur;
    struct json_object *hauteur;
    struct json_object *debut;
    struct json_object *cases;

    struct json_object *x;
    struct json_object *y;
    struct json_object *direction;
    struct json_object *type;
    struct json_object *contenu;

    size_t nb_cases;
    size_t i;
    
    /*ouverture, lecture et fermeture du fichier*/
    fd = open(nomFichier, O_RDONLY);
    if(fd == -1){
		printf("Erreur lors du open : %s\n",strerror(errno));
	}
	if(read(fd, buffer, MAX_SIZE) == 0){
		printf("Problème lors de la lecture\n");
		return EXIT_FAILURE;		
	}
	close(fd);

    parsed_json = json_tokener_parse(buffer);

    /**********Recuperation de la hauteur et de la largeur**********/

    exists = json_object_object_get_ex(parsed_json, "largeur", &largeur);
    if ( FALSE == exists ) {
        printf( "\"largeur\" not found in JSON\n" );
        return EXIT_FAILURE;
    }
    l = json_object_get_int(largeur);

    exists = json_object_object_get_ex(parsed_json, "hauteur", &hauteur);
    if ( FALSE == exists ) {
        printf( "\"hauteur\" not found in JSON\n" );
        return EXIT_FAILURE;
    }
    h = json_object_get_int(hauteur);

    /**********Recuperation des infos du robot**********/

    exists = json_object_object_get_ex(parsed_json, "debut", &debut);
    if ( FALSE == exists ) {
        printf( "\"debut\" not found in JSON\n" );
        return EXIT_FAILURE;
    }

    robot.porte = VIDE;
    contenu = json_object_array_get_idx(debut,  0);
    json_object_object_get_ex(contenu, "x", &x);
    robot.x = json_object_get_int(x);
    json_object_object_get_ex(contenu, "y", &y);
    robot.y = json_object_get_int(y);
    json_object_object_get_ex(contenu, "direction", &direction);
    dir = json_object_get_string(direction);

    if (strcmp(dir, "HAUT") == 0) {
        robot.dir = HAUT;
    }
    else if (strcmp(dir, "DROITE") == 0) {
        robot.dir = DROITE;
    }
    else if (strcmp(dir, "BAS") == 0) {
        robot.dir = BAS;
    }
    else if (strcmp(dir, "GAUCHE") == 0) {
        robot.dir = GAUCHE;
    }
    else {
        printf("erreur lors de la lecture de la dir du robot\n");
        return EXIT_FAILURE;
    }

    /**********Initialisation de la grille**********/
    /*x: colonne, y: ligne*/
    if((grille = malloc(sizeof(case_t*)*h))==NULL){
        /*ncurses_stopper();*/
        fprintf(stderr, "erreur malloc\n");
        exit(EXIT_FAILURE);
    }
    for (j=0; j<h; j++) {
        if((grille[j] = malloc(sizeof(case_t)*l))==NULL){
            /*ncurses_stopper();*/
            fprintf(stderr, "erreur malloc\n");
            exit(EXIT_FAILURE);
        }
    }
    for (j=0; j<h; j++) {
        for (k=0; k<l; k++) {
            grille[j][k].x = k;
            grille[j][k].y = j;
            grille[j][k].type = VIDE;
        }
    }

    /**********Recuperation des infos de la grille**********/

    exists = json_object_object_get_ex(parsed_json, "cases", &cases);
    if ( FALSE == exists ) {
        printf( "\"cases\" not found in JSON\n" );
        return EXIT_FAILURE;
    }

    nb_cases = json_object_array_length(cases);
    for (i=0; i<nb_cases; i++) {
        contenu = json_object_array_get_idx(cases,  i);
        json_object_object_get_ex(contenu, "x", &x);
        xx = json_object_get_int(x);
        json_object_object_get_ex(contenu, "y", &y);
        yy = json_object_get_int(y);
        json_object_object_get_ex(contenu, "type", &type);
        t = json_object_get_string(type);
        
        if (strcmp(t, "CAISSE") == 0) {
            grille[yy][xx].type = CAISSE;
        }
        else if (strcmp(t, "BLOC") == 0) {
            grille[yy][xx].type = BLOC;
        }
        else if (strcmp(t, "BILLE") == 0) {
            grille[yy][xx].type = BILLE;
        }
        else if (strcmp(t, "TROU") == 0) {
            grille[yy][xx].type = TROU;
            nbTrou++;
        }
    }

    return nbTrou;
}