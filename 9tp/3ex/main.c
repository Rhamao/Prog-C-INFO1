#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "char2d_array.h"

int main(int argc, char *argv[]){
	char** t = NULL;
	int i = 0;

	t = initialize_char2d_array(argc);
	
    for(i = 0; i<argc; i++)
		t[i] = create_new_line(argv[i]);

	for(i = 0; i<argc; i++)
		printf("argv[%d] = %s\n", i, t[i]);

	return EXIT_SUCCESS;
}
