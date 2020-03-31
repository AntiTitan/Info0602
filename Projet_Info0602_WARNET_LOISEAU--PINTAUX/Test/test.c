#include <stdio.h>
#include <json-c/json.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	int fp;
	char buffer[1024];
	struct json_object *parsed_json;
	struct json_object *name;
	struct json_object *age;
	struct json_object *friends;
	struct json_object *friend;
	size_t n_friends;

	size_t i;	

	fp = open("test.json",O_RDONLY);
	if(fp==-1){
		printf("error fopen : %s\n",strerror(errno));
	}
	if(read(fp, buffer, 1024)==0){
		printf("Problème\n");
		return EXIT_FAILURE;		
	}
	close(fp);

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