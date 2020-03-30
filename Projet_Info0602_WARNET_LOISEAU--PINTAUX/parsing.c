#include <stdio.h>
#include <json-c/json.h>
#include "struct.h"

#define MAX_SIZE 200

/*changer en fonction en lire_plateau*/
/*man json-c: https://json-c.github.io/json-c/json-c-0.10/doc/html/json__object_8h.html  */
int main(int argc, char *argv[]) {
    FILE *fd;
    int rd;
    int type;
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
    fd = fopen(argv[1], "r");
    rd = fread(buffer, MAX_SIZE, 1, fd);
    fclose(fd);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "largeur", &largeur);
    json_object_object_get_ex(parsed_json, "hauteur", &hauteur);
    json_object_object_get_ex(parsed_json, "debut", &debut);
    json_object_object_get_ex(parsed_json, "cases", &cases);

    printf("read: %d\n", rd);
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