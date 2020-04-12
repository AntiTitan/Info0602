#include <json-c/json.h>
#include "struct.h"

#define MAX_SIZE 2048

int main(int argc, char *argv[]) {
    int fd,exists;
    char buffer[MAX_SIZE];
    const char* dir;

    struct json_object *parsed_json;
    struct json_object *largeur;
    struct json_object *hauteur;
    struct json_object *debut;
    struct json_object *cases;

    struct json_object *x;
    struct json_object *y;
    struct json_object *direction;
    struct json_object *contenu;

    size_t nb_cases;
    size_t i;
    
    fd = open(argv[1], O_RDONLY);
    if(fd==-1){
		printf("error open : %s\n",strerror(errno));
	}
	if(read(fd, buffer, MAX_SIZE)==0){
		printf("Problème lors de la lecture\n");
		return EXIT_FAILURE;		
	}
	close(fd);

    parsed_json = json_tokener_parse(buffer);

    exists = json_object_object_get_ex(parsed_json, "largeur", &largeur);
    if ( FALSE == exists )
    {
        printf( "\"largeur\" not found in JSON\n" );
        return EXIT_FAILURE;
    }
    printf("largeur: %d\n", json_object_get_int(largeur));

    exists = json_object_object_get_ex(parsed_json, "hauteur", &hauteur);
    if ( FALSE == exists )
    {
        printf( "\"hauteur\" not found in JSON\n" );
        return EXIT_FAILURE;
    }
    printf("hauteur: %d\n", json_object_get_int(hauteur));

    exists = json_object_object_get_ex(parsed_json, "debut", &debut);
    if ( FALSE == exists )
    {
        printf( "\"debut\" not found in JSON\n" );
        return EXIT_FAILURE;
    }
    exists = json_object_object_get_ex(parsed_json, "cases", &cases);
    if ( FALSE == exists )
    {
        printf( "\"cases\" not found in JSON\n" );
        return EXIT_FAILURE;
    }

    nb_cases = json_object_array_length(cases);
    printf("nb de cases %lu\n", nb_cases);
    for (i=0; i<nb_cases; i++) {
        contenu = json_object_array_get_idx(cases,  i);
        printf("%lu. %s\n", i+1, json_object_get_string(contenu));
    }

    contenu = json_object_array_get_idx(debut,  0);
    printf("%lu. %s\n", i+1, json_object_get_string(contenu));
    json_object_object_get_ex(contenu, "x", &x);
    printf("x: %d\n", json_object_get_int(x));
    json_object_object_get_ex(contenu, "y", &y);
    printf("y: %d\n", json_object_get_int(y));
    json_object_object_get_ex(contenu, "direction", &direction);
    dir = json_object_get_string(direction);
    
    if (strcmp(dir, "HAUT") == 0) {
        printf("haut\n");
    }
    else if (strcmp(dir, "DROITE") == 0) {
        printf("droite\n");
    }
    else if (strcmp(dir, "BAS") == 0) {
        printf("bas\n");
    }
    else if (strcmp(dir, "GAUCHE") == 0) {
        printf("gauche\n");
    }
    

    return EXIT_SUCCESS;
}