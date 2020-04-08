#include <stdio.h>
#include <json-c/json.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	int fd, exists;
	char buffer[1024];
	struct json_object *parsed_json;
	struct json_object *name;
	struct json_object *age;
	struct json_object *friends;
	struct json_object *friend;
	size_t n_friends;

	size_t i;	

	fd = open(argv[1],O_RDONLY);
	if(fd==-1){
		printf("error open : %s\n",strerror(errno));
	}
	if(read(fd, buffer, 1024) == 0){
		printf("Problème lors de la lecture\n");
		return EXIT_FAILURE;		
	}
	close(fd);

	parsed_json = json_tokener_parse(buffer);

	exists = json_object_object_get_ex(parsed_json, "name", &name);
	if ( FALSE == exists )
    {
        printf( "\"name\" not found in JSON\n" );
        return EXIT_FAILURE;
    }
	printf("Name: %s\n", json_object_get_string(name));

	exists = json_object_object_get_ex(parsed_json, "age", &age);
	if ( FALSE == exists )
    {
        printf( "\"age\" not found in JSON\n" );
        return EXIT_FAILURE;
    }
	printf("Age: %d\n", json_object_get_int(age));

	exists = json_object_object_get_ex(parsed_json, "friends", &friends);
	if ( FALSE == exists )
    {
        printf( "\"friends\" not found in JSON\n" );
        return EXIT_FAILURE;
    }

	n_friends = json_object_array_length(friends);
	printf("Found %lu friends\n",n_friends);

	for(i=0;i<n_friends;i++) {
		friend = json_object_array_get_idx(friends, i);
		printf("%lu. %s\n",i+1,json_object_get_string(friend));
	}
	return EXIT_SUCCESS;	
}