#include <stdio.h>
#include <json-c/json.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv) {
	FILE *fp;
	char buffer[1024];
	struct json_object *parsed_json;
	struct json_object *name;
	struct json_object *age;
	struct json_object *friends;
	struct json_object *friend;
	size_t n_friends;
	int id;

	size_t i;	

	fp = fopen("test.json","r");
	if(fp==NULL){
		printf("error fopen : %s\n",strerror(errno));
	}
	if(fread(buffer, 1024, sizeof(char), fp)==0){
		printf("Problème\n");
		if(ferror(fp)==-1){
			return EXIT_FAILURE;
		}
		clearerr(fp);
		id=fread(buffer, 1024, sizeof(char), fp);
		if(id<1024){
			printf("id=%d\n",id);
			return EXIT_FAILURE;
		}
		
	}
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "name", &name);
	json_object_object_get_ex(parsed_json, "age", &age);
	json_object_object_get_ex(parsed_json, "friends", &friends);

	printf("Name: %s\n", json_object_get_string(name));
	printf("Age: %d\n", json_object_get_int(age));

	n_friends = json_object_array_length(friends);
	printf("Found %lu friends\n",n_friends);

	for(i=0;i<n_friends;i++) {
		friend = json_object_array_get_idx(friends, i);
		printf("%lu. %s\n",i+1,json_object_get_string(friend));
	}
	return EXIT_SUCCESS;	
}