#include <json-c/json.h>
#include "struct.h"

#define MAX_SIZE 200

/*changer en fonction en lire_plateau*/
/*man json-c: https://json-c.github.io/json-c/json-c-0.10/doc/html/json__object_8h.html  */
int main(int argc, char *argv[]) {
    int fd,exists;
    char buffer[MAX_SIZE];

    struct json_object *parsed_json;
    struct json_object *largeur;
    struct json_object *hauteur;
    struct json_object *debut;
    struct json_object *cases;

    /*struct json_object *x;
    struct json_object *y;
    struct json_object *direction;*/
    struct json_object *contenu;

    /*size_t deb;*/
    size_t nb_cases;
    size_t i;
    /*verification retour systeme !!!!!!!!!!!!!!!!!*/
    fd = open(argv[1], O_RDONLY);
    if(fd==-1){
		printf("error fopen : %s\n",strerror(errno));
	}
	if(read(fd, buffer, MAX_SIZE)==0){
		printf("Problème\n");
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
    exists = json_object_object_get_ex(parsed_json, "hauteur", &hauteur);
    if ( FALSE == exists )
    {
        printf( "\"hauteur\" not found in JSON\n" );
        return EXIT_FAILURE;
    }
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
    /*printf("read: %d\n", rd);*/
    printf("largeur: %d\n", json_object_get_int(largeur));
    printf("hauteur: %d\n", json_object_get_int(hauteur));
    printf("OK\n");

    /*deb = json_object_array_length(debut);*/
    /*pb pas un array? */
    nb_cases = json_object_array_length(cases);
    printf("nb de cases %lu\n", nb_cases);

    for (i=0; i<nb_cases; i++) {
        contenu = json_object_array_get_idx(cases,  i);
        printf("%lu. %s\n", i+1, json_object_get_string(contenu));
    }

    return 0;
}