#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "char2d_array.h"

int main(int argc, char *argv[]){
	char** t = NULL;
	int val1;
	int val2;
	
	printf("Donnez deux dimensions entières :");
	scanf("%d %d", &val1, &val2);

	t = create_char2d_array(val1, val2);
	fill_char2d_array(t, val1, val2);
	print_char2d_array(t, val1, val2);

	return EXIT_SUCCESS;
}
